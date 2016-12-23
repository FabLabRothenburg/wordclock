#ifndef IWORDING_STRATEGY_H
#define IWORDING_STRATEGY_H

#include "WordList.h"

class IWordingStrategy {
  public:
    virtual WordList wordsForTime(uint8_t hour, uint8_t minute) = 0;
};

#endif /* !IWORDING_STRATEGY_H */
