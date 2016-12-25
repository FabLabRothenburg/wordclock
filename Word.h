#ifndef WORD_H
#define WORD_H

#include <stdint.h>
#include <cassert>
#include "IAnimator.h"

class Word {
  private:
    uint8_t x;
    uint8_t y;
    uint8_t length;

  public:
    Word() : x(0), y(0), length(0) { }
    Word(uint8_t x, uint8_t y, uint8_t length) : x(x), y(y), length(length) {
      assert(length <= 11);
    }

    void show(IAnimator *animator, uint8_t r, uint8_t g, uint8_t b) const;
    void hide(IAnimator *animator) const;

    bool operator == (const Word& w) const {
         return x == w.x && y == w.y && length == w.length;
    }

    bool isOverlapping (const Word& w) const {
      /* overlapping words must be on same row */
      if (y != w.y)
        return false;

      /* THIS can start before W and run into it */
      if (x <= w.x && x + length > w.x)
        return true;

      /* W can start before THIS and run into it */
      if (w.x <= x && w.x + w.length > x)
        return true;

      return false;
    }

    bool isEmpty () const {
      return length == 0;
    }

    const Word diff(const Word& w) const {
      if (!isOverlapping(w))
        return *this;

      /* THIS starts *before* W (and runs into it); the *diff* are the letters before W

         THIS
           WWWW
         ^^
       */
      if (x < w.x)
        return Word(x, y, w.x - x);

      /* THIS starts *after* W (and W runs into THIS); the *diff* is the part of THIS beyond W

         WWWW
           THIS
             ^^

         If W is longer than THIS (considering the different starting points), then the result
         is just empty.

         WWWWWWWWWW
            THIS

            --> THIS completely re-used; i.e. yield empty
       */
      if (w.x + w.length >= x + length)
        return Word();

      return Word(w.x + w.length, y, x + length - w.x - w.length);
    }
};

#endif  /* !WORD_H */




