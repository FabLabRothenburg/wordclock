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

void DisplayDriver10x11Clock::setDots(uint8_t count, uint8_t red, uint8_t green, uint8_t blue) {
  uint8_t positions[4] = { 0, 1, 112, 113 };
  uint8_t i = 0;

  for (; i < count; i ++)
    pixels.setPixelColor(positions[i], pixels.Color(red, green, blue));

  for (; i < 4; i ++)
    pixels.setPixelColor(positions[i], 0);
}

uint32_t DisplayDriver10x11Clock::getPixel(uint8_t x, uint8_t y) {
  return pixels.getPixelColor(getPixelIndex(x, y));
}

void DisplayDriver10x11Clock::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {

  pixels.setPixelColor(getPixelIndex(x, y), pixels.Color(red, green, blue));
}

uint8_t DisplayDriver10x11Clock::getPixelIndex(uint8_t x, uint8_t y) {
  /* y axis is flipped if x is even */
  if ((x % 2) == 0)
    y = height() - 1 - y;

  uint8_t n = x * height() + y;

  /* there are two extra minute digit pixels before the matrix pixels */
  n += 2;

  return n;
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

