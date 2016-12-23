#include <Arduino.h>

#include "DisplayDriver10x11Clock.h"

void DisplayDriver10x11Clock::setup() {
  pixels.begin();
}

int DisplayDriver10x11Clock::width() {
  return 11;
}

int DisplayDriver10x11Clock::height() {
  return 10;
}

void DisplayDriver10x11Clock::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  /* y axis is flipped */
  y = height() - 1 - y;

  uint8_t n = x * height() + y;

  /* there are two extra minute digit pixels before the matrix pixels */
  n += 2;

  pixels.setPixelColor(n, pixels.Color(red, green, blue));
}

void DisplayDriver10x11Clock::clearPixel(uint8_t x, uint8_t y) {
  setPixel(x, y, 0, 0, 0);
}

void DisplayDriver10x11Clock::show() {
  pixels.show();
}

void DisplayDriver10x11Clock::clear() {
  pixels.clear();
}



