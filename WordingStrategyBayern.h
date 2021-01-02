#ifndef WORDING_STRATEGY_BAYERN_H
#define WORDING_STRATEGY_BAYERN_H

#include <Arduino.h>

#include "IWordingStrategy.h"
#include "WordList.h"
#include "WordFactoryBayernClock.h"

class WordingStrategyBayern : public IWordingStrategy {
  private:
    const WordFactoryBayernClock *wordFactory;

  public:
    WordingStrategyBayern(const WordFactoryBayernClock *wordFactory, const bool dreivaidl)
      : wordFactory(wordFactory), useDreivaidl(dreivaidl) {}

    virtual WordList wordsForTime(uint8_t hour, uint8_t minute);

    bool useDreivaidl = true;
};

#endif // WORDING_STRATEGY_BAYERN_H

