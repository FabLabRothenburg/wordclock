#include "IDisplayDriver.h"
#include "IWordingStrategy.h"

class WordClockScene {
  private:
    IDisplayDriver *driver; 
    IAnimator *animator;
    IWordingStrategy *wordingStrategy;
    
  public:
    WordClockScene(IDisplayDriver *driver, IAnimator *animator, IWordingStrategy *wordingStrategy)
      : driver(driver), animator(animator), wordingStrategy(wordingStrategy) { }
    void loop();
};


