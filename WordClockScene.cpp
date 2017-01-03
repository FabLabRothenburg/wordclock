#include <TimeLib.h>

#include "WordClockScene.h"

void WordClockScene::loop() {
  WordList nextWords = getWords();
  showWords(nextWords);
}

WordList WordClockScene::getWords() {
  return wordingStrategy->wordsForTime(hour(), minute());
}

uint8_t WordClockScene::getDotsCount() {
  return minute() % 5;
}

void WordClockScene::showWords(WordList &nextWords) {
  nextWords.diff(currentWords).show(animator, red, green, blue);
  currentWords.diff(nextWords).hide(animator);

  animator->setDots(getDotsCount(), red, green, blue);
  animator->commit();
  
  currentWords = nextWords;
}

void WordClockScene::clearScreen() {
  WordList noWords;
  showWords(noWords);
}

