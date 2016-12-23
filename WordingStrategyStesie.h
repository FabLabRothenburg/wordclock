#ifndef WORDING_STRATEGY_STESIE_H
#define WORDING_STRATEGY_STESIE_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordFactoryFrickelClock.h"
#include "WordList.h"

class WordingStrategyStesie : public IWordingStrategy {
  private:
    const WordFactoryFrickelClock *wordFactory;

  public:
    WordingStrategyStesie(const WordFactoryFrickelClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_STESIE_H */
