#ifndef WORD_FACTORY_FRANKEN_CLOCK_H
#define WORD_FACTORY_FRANKEN_CLOCK_H

#include "Word.h"

class WordFactoryFrankenClock {
  public:
    const Word getWordES() const;
    const Word getWordIST() const;
    const Word getWordFUENF() const;
    const Word getWordZEHN() const;
    const Word getWordZWANZIG() const;

    const Word getWordVIERTEL() const;
    const Word getWordHALB() const;
    const Word getWordDREIVIERTEL() const;

    const Word getWordVOR() const;
    const Word getWordNACH() const;

    const Word getWordEIN() const;
    const Word getWordUHR() const;

    const Word getWordForHour(uint8_t hour) const;
};

#endif  /* !WORD_FACTORY_FRANKEN_CLOCK_H */




