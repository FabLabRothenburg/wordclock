#ifndef WORD_FACTORY_FRICKEL_CLOCK_H
#define WORD_FACTORY_FRICKEL_CLOCK_H

#include "Word.h"

class WordFactoryFrickelClock {
  public:
    const Word getWordES() const;
    const Word getWordIST() const;
    const Word getWordFUENF() const;
    const Word getWordUND() const;
    const Word getWordZWANZIG() const;
    const Word getWordZEHN() const;
    const Word getWordVIERTEL() const;
    const Word getWordNACH() const;
    const Word getWordHALB() const;
    const Word getWordVOR() const;
    const Word getWordEIN() const;
    const Word getWordUHR() const;

    const Word getWordForHour(uint8_t hour) const;
};

#endif  /* !WORD_FACTORY_FRICKEL_CLOCK_H */



