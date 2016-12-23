#ifndef WORD_CLOCK_SCENE_H
#define WORD_CLOCK_SCENE_H

#include "IDisplayDriver.h"
#include "IWordingStrategy.h"

class WordClockScene {
  private:
    IDisplayDriver *driver; 
    IAnimator *animator;
    IWordingStrategy *wordingStrategy;

    uint8_t red = 255;
    uint8_t green = 255;
    uint8_t blue = 255;
    
  public:
    WordClockScene(IDisplayDriver *driver, IAnimator *animator, IWordingStrategy *wordingStrategy)
      : driver(driver), animator(animator), wordingStrategy(wordingStrategy) { }
    void loop();

    void setRed(uint8_t red) { this->red = red; }
    void setGreen(uint8_t green) { this->green = green; }
    void setBlue(uint8_t blue) { this->blue = blue; }
};

#endif /* !WORD_CLOCK_SCENE_H */

