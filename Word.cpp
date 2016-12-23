#include "Word.h"

void Word::show(IAnimator *animator, uint8_t r, uint8_t g, uint8_t b) const {
  for (uint8_t i = 0; i < length; i ++)
    animator->setPixel(x + i, y, r, g, b);
}

void Word::hide(IAnimator *animator) const {
  for (uint8_t i = 0; i < length; i ++)
    animator->clearPixel(x + i, y);
}




