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

void DisplayDriverFablabNeaClock::setDots(uint8_t count, uint8_t red, uint8_t green, uint8_t blue) {
  uint8_t positions[4] = { 111, 112, 113, 110 };
  uint8_t i = 0;

  for (; i < count; i ++)
    pixels.setPixelColor(positions[i], pixels.Color(red, green, blue));

  for (; i < 4; i ++)
    pixels.setPixelColor(positions[i], 0);
}

uint32_t DisplayDriverFablabNeaClock::getPixel(uint8_t x, uint8_t y) {
  return pixels.getPixelColor(getPixelIndex(x, y));
}

void DisplayDriverFablabNeaClock::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {

  pixels.setPixelColor(getPixelIndex(x, y), pixels.Color(red, green, blue));
}

uint8_t DisplayDriverFablabNeaClock::getPixelIndex(uint8_t x, uint8_t y) {
  /* x axis is flipped if y is odd */
  if ((y % 2) == 1)
    x = width() - 1 - x;

  return y * width() + x;
}

void DisplayDriverFablabNeaClock::clearPixel(uint8_t x, uint8_t y) {
  setPixel(x, y, 0, 0, 0);
}

void DisplayDriverFablabNeaClock::show() {
  pixels.show();
}

void DisplayDriverFablabNeaClock::clear() {
  pixels.clear();
}

