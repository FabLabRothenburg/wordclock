#include <TimeLib.h>

#include "WordClockScene.h"
#include "WordList.h"

#define COLOR   255, 255, 255

void WordClockScene::loop() {
  WordList wl = wordingStrategy->wordsForTime(hour(), minute());
  
  wl.show(animator, COLOR);
  driver->show();
  
  delay(1000);
  
  wl.hide(animator);
}

