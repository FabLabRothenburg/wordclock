#include "DisplayDriver10x11Clock.h"

DisplayDriver10x11Clock::DisplayDriver10x11Clock()
  : pin(5), pixels( 114, pin, NEO_GRB + NEO_KHZ800 ) {
}

DisplayDriver10x11Clock::DisplayDriver10x11Clock(uint16_t digPin)
  : pin(digPin), pixels( 114, digPin, NEO_GRB + NEO_KHZ800 ) {
}

void DisplayDriver10x11Clock::setup() {
  pixels.begin();
}

int DisplayDriver10x11Clock::width() {
  return 11;
}

int DisplayDriver10x11Clock::height() {
  return 10;
}

void DisplayDriver10x11Clock::setDots(uint8_t count, uint32_t color) {
  uint8_t positions[4] = { 0, 1, 112, 113 };
  uint8_t i = 0;

  for (; i < count; i ++)
    pixels.setPixelColor(positions[i], color);

  for (; i < 4; i ++)
    pixels.setPixelColor(positions[i], 0);
}

uint32_t DisplayDriver10x11Clock::getPixel(uint8_t x, uint8_t y) {
  return pixels.getPixelColor(getPixelIndex(x, y));
}

void DisplayDriver10x11Clock::setPixel(uint8_t x, uint8_t y, uint32_t color) {
  pixels.setPixelColor(getPixelIndex(x, y), color);
}

uint8_t DisplayDriver10x11Clock::getPixelIndex(uint8_t x, uint8_t y) {
  // y axis is flipped if x is even
  if ((x % 2) == 0)
    y = height() - 1 - y;

  uint8_t n = x * height() + y;

  return n + 2;   // there are two extra minute digit pixels before the matrix pixels
}

void DisplayDriver10x11Clock::show() {
  pixels.show();
}

