#ifndef WORDING_STRATEGY_ENGLISH_H
#define WORDING_STRATEGY_ENGLISH_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordFactoryEnglish10x11Clock.h"
#include "WordList.h"

class WordingStrategyEnglish : public IWordingStrategy {
  private:
    const WordFactoryEnglish10x11Clock *wordFactory;

  public:
    WordingStrategyEnglish(const WordFactoryEnglish10x11Clock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_ENGLISH_H */

