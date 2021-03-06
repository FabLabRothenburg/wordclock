#include <Arduino.h>

#include "DisplayDriverFrickelClock.h"

void DisplayDriverFrickelClock::setup() {
  pixels.begin();
}

int DisplayDriverFrickelClock::width() {
  return 11;
}

int DisplayDriverFrickelClock::height() {
  return 10;
}

uint32_t DisplayDriverFrickelClock::getPixel(uint8_t x, uint8_t y) {
  return pixels.getPixelColor(getPixelIndex(x, y));
}

void DisplayDriverFrickelClock::setPixel(uint8_t x, uint8_t y, uint32_t color) {
  if (y == 9) {
    if (x >= 4 && x <= 7)
      return;
  }

  pixels.setPixelColor(getPixelIndex(x, y), color);
}

uint8_t DisplayDriverFrickelClock::getPixelIndex(uint8_t x, uint8_t y) {
  /* every second row is flipped */
  if ((y % 2) == 1) x = width() - 1 - x;

  /* the whole screen is flipped */
  uint8_t n = (height() - 1 - y) * width() + x;

  /* there are four pixels missing in the lowest row */
  if (n > 3) n -= 4;

  return n;
}

void DisplayDriverFrickelClock::show() {
  pixels.show();
}

