#ifndef WORDING_STRATEGY_SWEDISH_H
#define WORDING_STRATEGY_SWEDISH_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordFactorySwedishClock.h"
#include "WordList.h"

class WordingStrategySwedish : public IWordingStrategy {
  private:
    const WordFactorySwedishClock *wordFactory;

  public:
    WordingStrategySwedish(const WordFactorySwedishClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_SWEDISH_H */
