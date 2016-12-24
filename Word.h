#ifndef WORD_H
#define WORD_H

#include <Arduino.h>
#include "IAnimator.h"

class Word {
  private:
    uint8_t x;
    uint8_t y;
    uint8_t length;

  public:
    Word() : x(0), y(0), length(0) { }
    Word(uint8_t x, uint8_t y, uint8_t length) : x(x), y(y), length(length) { }

    void show(IAnimator *animator, uint8_t r, uint8_t g, uint8_t b) const;
    void hide(IAnimator *animator) const;

    bool operator == (const Word& w) const {
         return x == w.x && y == w.y && length == w.length;
    }
};

#endif  /* !WORD_H */




