#ifndef WORD_FACTORY_ROT_CLOCK_H
#define WORD_FACTORY_ROT_CLOCK_H

#include "Word.h"

class WordFactoryRoadaburchClock {
  public:
    virtual const Word getWordSCHO() const;

    virtual const Word getWordETZ() const;
    virtual const Word getWordIS() const;
    virtual const Word getWordFUENF() const;
    virtual const Word getWordZEAH() const;

    virtual const Word getWordFERDL() const;
    virtual const Word getWordHALBER() const;
    virtual const Word getWordDREIFERDL() const;

    virtual const Word getWordVOR() const;
    virtual const Word getWordNACH() const;

    virtual const Word getWordForHour(uint8_t hour) const;
};

#endif  // WORD_FACTORY_ROT_CLOCK_H
