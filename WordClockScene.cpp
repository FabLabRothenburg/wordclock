#include "WordClockScene.h"

void WordClockScene::loop() {
  time_t localTime = getLocalTime();
  WordList nextWords = getWords(localTime);
  showWords(nextWords, localTime);
}

WordList WordClockScene::getWords(time_t time) {
  return wordingStrategy->wordsForTime(hour(time), minute(time));
}

uint8_t WordClockScene::getDotsCount(time_t time) {
  return minute(time) % 5;
}

void WordClockScene::showWords(WordList &nextWords, time_t time) {
  nextWords.diff(currentWords).show(animator);
  currentWords.diff(nextWords).hide(animator);

  animator->setDots(getDotsCount(time));
  animator->commit();
  
  currentWords = nextWords;
}

time_t WordClockScene::getLocalTime() {
  //Central European Time (Frankfurt, Paris)
  TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     //Central European Summer Time
  TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       //Central European Standard Time
  Timezone localTimezone(CEST, CET);
  return localTimezone.toLocal(now());
}
