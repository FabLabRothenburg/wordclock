#include <Arduino.h>

#include "DisplayDriverFrickelClock.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      106

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
static Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void DisplayDriverFrickelClock::setup() {
  pixels.begin();
}

int DisplayDriverFrickelClock::width() {
  return 11;
}

int DisplayDriverFrickelClock::height() {
  return 10;
}

void DisplayDriverFrickelClock::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  /* every second row is flipped */
  if ((y % 2) == 1) x = width() - 1 - x;

  /* the whole screen is flipped */
  uint8_t n = (height() - 1 - y) * width() + x;

  /* there are four pixels missing in the lowest row */
  if (n > 3) n -= 4;

  pixels.setPixelColor(n, pixels.Color(red, green, blue));
}

void DisplayDriverFrickelClock::clearPixel(uint8_t x, uint8_t y) {
  setPixel(x, y, 0, 0, 0);
}

void DisplayDriverFrickelClock::show() {
  pixels.show();
}

void DisplayDriverFrickelClock::clear() {
  pixels.clear();
}


