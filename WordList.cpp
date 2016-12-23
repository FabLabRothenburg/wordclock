#include <Arduino.h>
#include "WordList.h"

void WordList::add(const Word w) {
  words[length ++] = w;
}

void WordList::show(IAnimator *animator, uint8_t r, uint8_t g, uint8_t b) const {
  for (uint8_t i = 0; i < length; i ++)
    words[i].show(animator, r, g, b);
}

void WordList::hide(IAnimator *animator) const {
  for (uint8_t i = 0; i < length; i ++)
    words[i].hide(animator);
}

