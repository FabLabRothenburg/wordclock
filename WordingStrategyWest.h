#ifndef WORDING_STRATEGY_WEST_H
#define WORDING_STRATEGY_WEST_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "IWordFactoryFrankenClock.h"
#include "WordList.h"

class WordingStrategyWest : public IWordingStrategy {
  private:
    const IWordFactoryFrankenClock *wordFactory;

  public:
    WordingStrategyWest(const IWordFactoryFrankenClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_WEST_H */

