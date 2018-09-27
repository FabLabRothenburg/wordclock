#include "MockWordClockScene.h"

WordList MockWordClockScene::getWords(time_t time) {
  minute ++;

  if (minute >= 60) {
    minute = 0;
    hour ++;
  }

  if (hour >= 24) {
    hour = 0;
  }

  return wordingStrategy->wordsForTime(hour, minute);
}

uint8_t MockWordClockScene::getDotsCount(time_t time) {
  return minute % 5;
}
