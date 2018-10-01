#ifndef WORD_CLOCK_SCENE_H
#define WORD_CLOCK_SCENE_H

#include <Time.h>
#include <Timezone.h>  // https://github.com/JChristensen/Timezone
#include "IAnimator.h"
#include "IWordingStrategy.h"
#include "WordList.h"

class WordClockScene {
  private:
    IAnimator *animator;
    WordList currentWords;

  protected:
    IWordingStrategy *wordingStrategy;
    
  public:
    WordClockScene(IAnimator *animator, IWordingStrategy *wordingStrategy)
      : animator(animator), wordingStrategy(wordingStrategy) { }
    void loop();

  protected:
    virtual WordList getWords(time_t time);
    virtual uint8_t getDotsCount(time_t time);
    time_t getLocalTime();

  private:
    void showWords(WordList &nextWords, time_t time);
};

#endif /* !WORD_CLOCK_SCENE_H */

