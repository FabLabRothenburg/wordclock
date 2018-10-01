#include <Arduino.h>

#include "DisplayDriverFablabNeaClock.h"

void DisplayDriverFablabNeaClock::setup() {
  pixels.begin();
}

int DisplayDriverFablabNeaClock::width() {
  return 11;
}

int DisplayDriverFablabNeaClock::height() {
  return 10;
}

void DisplayDriverFablabNeaClock::setDots(uint8_t count, uint32_t color) {
  uint8_t positions[4] = { 111, 112, 113, 110 };
  uint8_t i = 0;

  for (; i < count; i ++)
    pixels.setPixelColor(positions[i], color);

  for (; i < 4; i ++)
    pixels.setPixelColor(positions[i], 0);
}

uint32_t DisplayDriverFablabNeaClock::getPixel(uint8_t x, uint8_t y) {
  return pixels.getPixelColor(getPixelIndex(x, y));
}

void DisplayDriverFablabNeaClock::setPixel(uint8_t x, uint8_t y, uint32_t color) {
  pixels.setPixelColor(getPixelIndex(x, y), color);
}

uint8_t DisplayDriverFablabNeaClock::getPixelIndex(uint8_t x, uint8_t y) {
  /* x axis is flipped if y is odd */
  if ((y % 2) == 1)
    x = width() - 1 - x;

  return y * width() + x;
}

void DisplayDriverFablabNeaClock::show() {
  pixels.show();
}

