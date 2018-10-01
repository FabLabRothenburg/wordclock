#include "Word.h"

void Word::show(IAnimator *animator) const {
  for (uint8_t i = 0; i < length; i ++)
    animator->setPixel(x + i, y);
}

void Word::hide(IAnimator *animator) const {
  for (uint8_t i = 0; i < length; i ++)
    animator->clearPixel(x + i, y);
}





