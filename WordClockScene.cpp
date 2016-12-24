#include <TimeLib.h>

#include "WordClockScene.h"

void WordClockScene::loop() {
  WordList wl = getWords();

  driver->setDots(getDotsCount(), red, green, blue);
  
  wl.show(animator, red, green, blue);
  driver->show();
  
  delay(1000);
  
  wl.hide(animator);
}

WordList WordClockScene::getWords() {
  return wordingStrategy->wordsForTime(hour(), minute());
}

uint8_t WordClockScene::getDotsCount() {
  return minute() % 5;
}
