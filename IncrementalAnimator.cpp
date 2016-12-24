#include "IncrementalAnimator.h"

void IncrementalAnimator::setDots(uint8_t count, uint8_t red, uint8_t green, uint8_t blue) {
  driver->setDots(count, red, green, blue);
}

void IncrementalAnimator::setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) {
  driver->setPixel(x, y, red, green, blue);
  driver->show();
  delay(100);
}

void IncrementalAnimator::clearPixel(uint8_t x, uint8_t y) {
  driver->clearPixel(x, y);
  driver->show();
  delay(100);
}

void IncrementalAnimator::commit() {
  driver->show();
}
