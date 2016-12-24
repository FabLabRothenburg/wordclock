#ifndef MOCK_WORD_CLOCK_SCENE_H
#define MOCK_WORD_CLOCK_SCENE_H

#include "IDisplayDriver.h"
#include "IWordingStrategy.h"
#include "WordClockScene.h"

class MockWordClockScene : public WordClockScene {
  private:
    uint8_t hour;
    uint8_t minute;

  public:
    MockWordClockScene(IDisplayDriver *driver, IAnimator *animator, IWordingStrategy *wordingStrategy)
      : WordClockScene(driver, animator, wordingStrategy) { }

  protected:
    virtual WordList getWords(void);
    virtual uint8_t getDotsCount(void);
};

#endif /* !MOCK_WORD_CLOCK_SCENE_H */

