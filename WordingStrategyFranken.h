#ifndef WORDING_STRATEGY_FRANKEN_H
#define WORDING_STRATEGY_FRANKEN_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordFactoryFrankenClock.h"
#include "WordList.h"

class WordingStrategyFranken : public IWordingStrategy {
  private:
    const WordFactoryFrankenClock *wordFactory;

  public:
    WordingStrategyFranken(const WordFactoryFrankenClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_FRANKEN_H */

