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

WordList WordList::diff(WordList &diffWords) const {
  WordList result;

  for (uint8_t i = 0; i < length; i ++) {
    uint8_t found = 0;

    for (uint8_t j = 0; j < diffWords.length; j ++) {
      if (words[i] == diffWords.words[j]) {
	found = 1;
	break;
      }
    }

    if (!found)
      result.add(words[i]);
  }

  return result;
}
