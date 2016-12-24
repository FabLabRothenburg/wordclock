#ifndef WORD_CLOCK_SCENE_H
#define WORD_CLOCK_SCENE_H

#include "IAnimator.h"
#include "IWordingStrategy.h"
#include "WordList.h"

class WordClockScene {
  private:
    IAnimator *animator;

    uint8_t red = 255;
    uint8_t green = 255;
    uint8_t blue = 255;

  protected:
    IWordingStrategy *wordingStrategy;

    
  public:
    WordClockScene(IAnimator *animator, IWordingStrategy *wordingStrategy)
      : animator(animator), wordingStrategy(wordingStrategy) { }
    void loop();

    void setRed(uint8_t red) { this->red = red; }
    void setGreen(uint8_t green) { this->green = green; }
    void setBlue(uint8_t blue) { this->blue = blue; }

  protected:
    virtual WordList getWords(void);
    virtual uint8_t getDotsCount(void);
};

#endif /* !WORD_CLOCK_SCENE_H */

