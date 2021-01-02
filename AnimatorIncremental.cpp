#include "AnimatorIncremental.h"

void IncrementalAnimator::setPixel(uint8_t x, uint8_t y) {
  driver->setPixel(x, y, pack(red, green, blue));
  driver->show();
  delay(100);
}

void IncrementalAnimator::clearPixel(uint8_t x, uint8_t y) {
  driver->setPixel(x, y, 0);
  driver->show();
  delay(100);
}
