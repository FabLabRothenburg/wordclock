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
  if (red == 0 && green == 0 && blue == 0) {
    red = 1; // don't actually turn off the last LED
  }

  updateColors(pack(this->red, green, blue), pack(red, green, blue));
  this->red = red;
}

void NullAnimator::setGreen(uint8_t green) {
  if (red == 0 && green == 0 && blue == 0) {
    green = 1; // don't actually turn off the last LED
  }

  updateColors(pack(red, this->green, blue), pack(red, green, blue));
  this->green = green;
}

void NullAnimator::setBlue(uint8_t blue) {
  if (red == 0 && green == 0 && blue == 0) {
    blue = 1; // don't actually turn off the last LED
  }

  updateColors(pack(red, green, this->blue), pack(red, green, blue));
  this->blue = blue;
}

void NullAnimator::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
  if (red == 0 && green == 0 && blue == 0) {
    blue = 1; // don't actually turn off the last LED
  }

  updateColors(pack(this->red, this->green, this->blue), pack(red, green, blue));

  this->red = red;
  this->green = green;
  this->blue = blue;
}


void NullAnimator::updateColors(uint32_t oldColor, uint32_t newColor) {
  if (oldColor == 0) {
    // don't update if old color was black, otherwise all LEDs would be enabled
    return;
  }

  for (uint8_t y = 0; y < driver->height(); y ++) {
    for (uint8_t x = 0; x < driver->width(); x ++) {
      if (driver->getPixel(x, y) == oldColor) {
        driver->setPixel(x, y, newColor);
      }
    }
  }

  commit();
}
