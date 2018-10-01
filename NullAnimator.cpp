#include "NullAnimator.h"

void NullAnimator::setDots(uint8_t count) {
  driver->setDots(count, pack(red, green, blue));
}

void NullAnimator::setPixel(uint8_t x, uint8_t y) {
  driver->setPixel(x, y, pack(red, green, blue));
}

void NullAnimator::clearPixel(uint8_t x, uint8_t y) {
  driver->setPixel(x, y, 0);
}

void NullAnimator::commit() {
  driver->show();
}

void NullAnimator::setRed(uint8_t red) {
  updateColors(pack(this->red, green, blue), pack(red, green, blue));
  this->red = red;
}

void NullAnimator::setGreen(uint8_t green) {
  updateColors(pack(red, this->green, blue), pack(red, green, blue));
  this->green = green;
}

void NullAnimator::setBlue(uint8_t blue) {
  updateColors(pack(red, green, this->blue), pack(red, green, blue));
  this->blue = blue;
}

void NullAnimator::updateColors(uint32_t oldColor, uint32_t newColor) {
  for (uint8_t y = 0; y < driver->height(); y ++) {
    for (uint8_t x = 0; x < driver->width(); x ++) {
      if (driver->getPixel(x, y) == oldColor) {
        driver->setPixel(x, y, newColor);
      }
    }
  }
}
