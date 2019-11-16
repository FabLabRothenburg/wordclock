#ifndef WORD_FACTORY_GERMANY_V2_CLOCK_H
#define WORD_FACTORY_GERMANY_V2_CLOCK_H

#include "IWordFactoryFrankenClock.h"

class WordFactoryGermanV2Clock : public IWordFactoryFrankenClock {
  public:
    virtual const Word getWordES() const;
    virtual const Word getWordIST() const;
    virtual const Word getWordFUENF() const;
    virtual const Word getWordZEHN() const;
    virtual const Word getWordZWANZIG() const;

    virtual const Word getWordVIERTEL() const;
    virtual const Word getWordHALB() const;
    virtual const Word getWordDREIVIERTEL() const;

    virtual const Word getWordVOR() const;
    virtual const Word getWordNACH() const;

    virtual const Word getWordEIN() const;
    virtual const Word getWordUHR() const;

    virtual const Word getWordForHour(uint8_t hour) const;
};

#endif  /* !WORD_FACTORY_GERMANY_V2_CLOCK_H */
