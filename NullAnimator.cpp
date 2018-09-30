#include "NullAnimator.h"

void NullAnimator::setDots(uint8_t count, uint8_t red, uint8_t green, uint8_t blue) {
  driver->setDots(count, pack(red, green, blue));
}

void NullAnimator::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  driver->setPixel(x, y, pack(red, green, blue));
}

void NullAnimator::clearPixel(uint8_t x, uint8_t y) {
  driver->setPixel(x, y, 0);
}

void NullAnimator::commit() {
  driver->show();
}
