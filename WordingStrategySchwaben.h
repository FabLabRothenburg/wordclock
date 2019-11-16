#ifndef WORDING_STRATEGY_SCHWABEN_H
#define WORDING_STRATEGY_SCHWABEN_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "IWordFactoryFrankenClock.h"
#include "WordList.h"

class WordingStrategySchwaben : public IWordingStrategy {
  private:
    const IWordFactoryFrankenClock *wordFactory;

  public:
    WordingStrategySchwaben(const IWordFactoryFrankenClock *wordFactory)
      : wordFactory(wordFactory) {
    }

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);
};

#endif /* !WORDING_STRATEGY_SCHWABEN_H */
