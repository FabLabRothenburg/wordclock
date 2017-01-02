#ifndef WORD_CLOCK_SCENE_H
#define WORD_CLOCK_SCENE_H

#include "IAnimator.h"
#include "IColorControllable.h"
#include "IWordingStrategy.h"
#include "WordList.h"

class WordClockScene : public IColorControllable {
  private:
    IAnimator *animator;

    uint8_t red = 255;
    uint8_t green = 255;
    uint8_t blue = 255;

    WordList currentWords;

  protected:
    IWordingStrategy *wordingStrategy;

    
  public:
    WordClockScene(IAnimator *animator, IWordingStrategy *wordingStrategy)
      : animator(animator), wordingStrategy(wordingStrategy) { }
    void loop();

    virtual void setRed(uint8_t red) { this->red = red; }
    virtual void setGreen(uint8_t green) { this->green = green; }
    virtual void setBlue(uint8_t blue) { this->blue = blue; }

  protected:
    virtual WordList getWords(void);
    virtual uint8_t getDotsCount(void);
};

#endif /* !WORD_CLOCK_SCENE_H */

