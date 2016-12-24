#include <TimeLib.h>

#include "WordClockScene.h"

void WordClockScene::loop() {
  WordList nextWords = getWords();
  
  nextWords.diff(currentWords).show(animator, red, green, blue);
  currentWords.diff(nextWords).hide(animator);

  animator->setDots(getDotsCount(), red, green, blue);
  animator->commit();
  
  currentWords = nextWords;
}

WordList WordClockScene::getWords() {
  return wordingStrategy->wordsForTime(hour(), minute());
}

uint8_t WordClockScene::getDotsCount() {
  return minute() % 5;
}
