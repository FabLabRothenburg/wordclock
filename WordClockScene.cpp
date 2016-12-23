#include <TimeLib.h>

#include "WordClockScene.h"
#include "WordList.h"

void WordClockScene::loop() {
  WordList wl = wordingStrategy->wordsForTime(hour(), minute());

  driver->setDots(minute() % 5, red, green, blue);
  
  wl.show(animator, red, green, blue);
  driver->show();
  
  delay(1000);
  
  wl.hide(animator);
}


