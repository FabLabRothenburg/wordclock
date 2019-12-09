/*
 * Adaption of diyHue code for the wordClock project.
 * Source: https://github.com/mariusmotea/diyHue/blob/master/Lights/Arduino/Generic_RGB_Light/Generic_RGB_Light.ino
 * 
 * All code is subject to GPLv3.
 */
#include <Arduino.h>
#include <math.h>

#include "DiyHueController.h"

#define FALLBACK_TRANSITION_TIME 4

void DiyHueController::setRed(uint8_t red) {
  rgb[0] = red;
  color_mode = 0;

  // force re-calculation (in case caller isn't aware of specific necessities)
  process_lightdata(FALLBACK_TRANSITION_TIME);
}

void DiyHueController::setGreen(uint8_t green) {
  rgb[1] = green;
  color_mode = 0;

  // force re-calculation (in case caller isn't aware of specific necessities)
  process_lightdata(FALLBACK_TRANSITION_TIME);
}

void DiyHueController::setBlue(uint8_t blue) {
  rgb[2] = blue;
  color_mode = 0;

  // force re-calculation (in case caller isn't aware of specific necessities)
  process_lightdata(FALLBACK_TRANSITION_TIME);
}

void DiyHueController::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
  rgb[0] = red;
  rgb[1] = green;
  rgb[2] = blue;
  color_mode = 0;

  // force re-calculation (in case caller isn't aware of specific necessities)
  process_lightdata(FALLBACK_TRANSITION_TIME);
}


void DiyHueController::setColorX(float x) {
  this->x = x;
  color_mode = 1;
}

void DiyHueController::setColorY(float y) {
  this->y = y;
  color_mode = 1;
}

void DiyHueController::incBri(int bri) {
  int new_bri = (int)this->bri + bri;
  if (bri < 0) bri = 0;
  if (bri > 255) bri = 255;
  this->bri = new_bri;
}

void DiyHueController::setCt(int ct) {
  this->ct = ct;
  color_mode = 2;
}

void DiyHueController::setSat(uint8_t sat) {
  this->sat = sat;
  color_mode = 3;
}

void DiyHueController::setHue(int hue) {
  this->hue = hue;
  color_mode = 3;
}

void DiyHueController::alert() {
  if (light_state) {
    current_rgb[0] = 0;
    current_rgb[1] = 0;
    current_rgb[2] = 0;
  }
  else {
    current_rgb[0] = 255;
    current_rgb[1] = 255;
    current_rgb[2] = 255;
  }
}

void DiyHueController::convert_hue() {
  double      hh, p, q, t, ff, s, v;
  long        i;

  s = sat / 255.0;
  v = bri / 255.0;

  if (s <= 0.0) {      // < is bogus, just shuts up warnings
    rgb[0] = v;
    rgb[1] = v;
    rgb[2] = v;
    return;
  }
  hh = hue;
  if (hh >= 65535.0) hh = 0.0;
  hh /= 11850, 0;
  i = (long)hh;
  ff = hh - i;
  p = v * (1.0 - s);
  q = v * (1.0 - (s * ff));
  t = v * (1.0 - (s * (1.0 - ff)));

  switch (i) {
    case 0:
      rgb[0] = v * 255.0;
      rgb[1] = t * 255.0;
      rgb[2] = p * 255.0;
      break;
    case 1:
      rgb[0] = q * 255.0;
      rgb[1] = v * 255.0;
      rgb[2] = p * 255.0;
      break;
    case 2:
      rgb[0] = p * 255.0;
      rgb[1] = v * 255.0;
      rgb[2] = t * 255.0;
      break;

    case 3:
      rgb[0] = p * 255.0;
      rgb[1] = q * 255.0;
      rgb[2] = v * 255.0;
      break;
    case 4:
      rgb[0] = t * 255.0;
      rgb[1] = p * 255.0;
      rgb[2] = v * 255.0;
      break;
    case 5:
    default:
      rgb[0] = v * 255.0;
      rgb[1] = p * 255.0;
      rgb[2] = q * 255.0;
      break;
  }
}

void DiyHueController::convert_xy() {
  int optimal_bri = bri;
  if (optimal_bri < 5) {
    optimal_bri = 5;
  }
  float Y = y;
  float X = x;
  float Z = 1.0f - x - y;

  // sRGB D65 conversion
  float r =  X * 3.2406f - Y * 1.5372f - Z * 0.4986f;
  float g = -X * 0.9689f + Y * 1.8758f + Z * 0.0415f;
  float b =  X * 0.0557f - Y * 0.2040f + Z * 1.0570f;


  // Apply gamma correction
  //r = r <= 0.04045f ? r / 12.92f : pow((r + 0.055f) / (1.0f + 0.055f), 2.4f);
  //g = g <= 0.04045f ? g / 12.92f : pow((g + 0.055f) / (1.0f + 0.055f), 2.4f);
  //b = b <= 0.04045f ? b / 12.92f : pow((b + 0.055f) / (1.0f + 0.055f), 2.4f);

  if (r > b && r > g) {
    // red is biggest
    if (r > 1.0f) {
      g = g / r;
      b = b / r;
      r = 1.0f;
    }
  }
  else if (g > b && g > r) {
    // green is biggest
    if (g > 1.0f) {
      r = r / g;
      b = b / g;
      g = 1.0f;
    }
  }
  else if (b > r && b > g) {
    // blue is biggest
    if (b > 1.0f) {
      r = r / b;
      g = g / b;
      b = 1.0f;
    }
  }

  r = r < 0 ? 0 : r;
  g = g < 0 ? 0 : g;
  b = b < 0 ? 0 : b;

  rgb[0] = (int) (r * optimal_bri); rgb[1] = (int) (g * optimal_bri); rgb[2] = (int) (b * optimal_bri);
}

void DiyHueController::convert_ct() {
  int hectemp = 10000 / ct;
  int r, g, b;
  if (hectemp <= 66) {
    r = 255;
    g = 99.4708025861 * log(hectemp) - 161.1195681661;
    b = hectemp <= 19 ? 0 : (138.5177312231 * log(hectemp - 10) - 305.0447927307);
  } else {
    r = 329.698727446 * pow(hectemp - 60, -0.1332047592);
    g = 288.1221695283 * pow(hectemp - 60, -0.0755148492);
    b = 255;
  }
  r = r > 255 ? 255 : r;
  g = g > 255 ? 255 : g;
  b = b > 255 ? 255 : b;
  rgb[0] = r * (bri / 255.0f); rgb[1] = g * (bri / 255.0f); rgb[2] = b * (bri / 255.0f);
}

void DiyHueController::process_lightdata(float transitiontime) {
  transitiontime *= 8;

  if (color_mode == 1 && light_state == true) {
    convert_xy();
  } else if (color_mode == 2 && light_state == true) {
    convert_ct();
  } else if (color_mode == 3 && light_state == true) {
    convert_hue();
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (light_state) {
      step_level[i] = ((float)rgb[i] - current_rgb[i]) / transitiontime;
    } else {
      step_level[i] = current_rgb[i] / transitiontime;
    }
  }
}

void DiyHueController::maintain() {
  if (light_state) {
    if (rgb[0] != current_rgb[0] || rgb[1] != current_rgb[1] || rgb[2] != current_rgb[2]) {
      for (uint8_t k = 0; k < 3; k++) {
        if (rgb[k] != current_rgb[k]) current_rgb[k] += step_level[k];
        if ((step_level[k] > 0.0 && current_rgb[k] > rgb[k]) || (step_level[k] < 0.0 && current_rgb[k] < rgb[k])) current_rgb[k] = rgb[k];
      }

      apply_colors();
    }
  } else {
    if (current_rgb[0] != 0 || current_rgb[1] != 0 || current_rgb[2] != 0) {
      for (uint8_t k = 0; k < 3; k++) {
        if (current_rgb[k] != 0) current_rgb[k] -= step_level[k];
        if (current_rgb[k] < 0) current_rgb[k] = 0;
      }

      apply_colors();
    }
  }
}

void DiyHueController::apply_colors() {
  controllable->setRGB(current_rgb[0], current_rgb[1], current_rgb[2]);
}

