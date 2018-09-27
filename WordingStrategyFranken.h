#ifndef WORDING_STRATEGY_FRANKEN_H
#define WORDING_STRATEGY_FRANKEN_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "IWordFactoryFrankenClock.h"
#include "WordList.h"

class WordingStrategyFranken : public IWordingStrategy {
  private:
    const IWordFactoryFrankenClock *wordFactory;

  public:
    WordingStrategyFranken(const IWordFactoryFrankenClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_FRANKEN_H */

