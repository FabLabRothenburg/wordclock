#ifndef WORD_LIST_H
#define WORD_LIST_H

#include "Word.h"

class WordList {
  private:
    Word words[10];
    uint8_t length = 0;

  public:
    void add(const Word w);
    void show(IAnimator *animator) const;
    void hide(IAnimator *animator) const;

    WordList diff(WordList &diffWords) const;

    const Word &getWord(uint8_t index) const { return words[index]; }
    uint8_t getLength() const { return length; }

    bool isEmpty () const {
      return length == 0;
    }
};

#endif  /* !WORD_LIST_H */

