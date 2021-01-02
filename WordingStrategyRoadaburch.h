#ifndef WORDING_STRATEGY_ROT_H
#define WORDING_STRATEGY_ROT_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordFactoryRoadaburchClock.h"
#include "WordList.h"

class WordingStrategyRoadaburch : public IWordingStrategy {
  private:
    const WordFactoryRoadaburchClock *wordFactory;

  public:
    WordingStrategyRoadaburch(const WordFactoryRoadaburchClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif // WORDING_STRATEGY_ROT_H
