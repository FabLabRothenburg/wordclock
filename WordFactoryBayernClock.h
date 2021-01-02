#ifndef WORD_FACTORY_BAYERN_CLOCK_H
#define WORD_FACTORY_BAYERN_CLOCK_H

#include "Word.h"

class WordFactoryBayernClock {
  public:
    virtual const Word getWordES() const;
    virtual const Word getWordIS() const;

    virtual const Word getWordFUEMF() const;
    virtual const Word getWordZEHN() const;
    virtual const Word getWordZWANZG() const;

    virtual const Word getWordVOA() const;
    virtual const Word getWordNOCH() const;

    virtual const Word getWordPUNKT() const;
    virtual const Word getWordVIADL() const;
    virtual const Word getWordHOIWE() const;
    virtual const Word getWordDREIVIADL() const;

    virtual const Word getWordForHour(uint8_t hour) const;
};

#endif  // WORD_FACTORY_BAYERN_CLOCK_H




