#ifndef WORD_FACTORY_ENGLISH_10X11_CLOCK_H
#define WORD_FACTORY_ENGLISH_10X11_CLOCK_H

#include "Word.h"

class WordFactoryEnglish10x11Clock {
  public:
    const Word getWordIT() const;
    const Word getWordIS() const;
    const Word getWordAM() const;
    const Word getWordPM() const;
    const Word getWordFIVE() const;
    const Word getWordTWENTY() const;
    const Word getWordTEN() const;
    const Word getWordQUARTER() const;
    const Word getWordTO() const;
    const Word getWordHALF() const;
    const Word getWordPAST() const;
    const Word getWordOCLOCK() const;

    const Word getWordForHour(uint8_t hour) const;
};

#endif  /* !WORD_FACTORY_ENGLISH_10X11_CLOCK_H */





