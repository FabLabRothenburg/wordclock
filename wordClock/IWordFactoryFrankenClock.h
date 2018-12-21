#ifndef I_WORD_FACTORY_FRANKEN_CLOCK_H
#define I_WORD_FACTORY_FRANKEN_CLOCK_H

#include "Word.h"

class IWordFactoryFrankenClock {
  public:
    virtual const Word getWordES() const = 0;
    virtual const Word getWordIST() const = 0;
    virtual const Word getWordFUENF() const = 0;
    virtual const Word getWordZEHN() const = 0;
    virtual const Word getWordZWANZIG() const = 0;

    virtual const Word getWordVIERTEL() const = 0;
    virtual const Word getWordHALB() const = 0;
    virtual const Word getWordDREIVIERTEL() const = 0;

    virtual const Word getWordVOR() const = 0;
    virtual const Word getWordNACH() const = 0;

    virtual const Word getWordEIN() const = 0;
    virtual const Word getWordUHR() const = 0;

    virtual const Word getWordForHour(uint8_t hour) const = 0;
};

#endif  /* !I_WORD_FACTORY_FRANKEN_CLOCK_H */




