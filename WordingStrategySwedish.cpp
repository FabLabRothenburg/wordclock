#include "WordingStrategySwedish.h"

WordList WordingStrategySwedish::wordsForTime(uint8_t hour, uint8_t minute) {
  WordList words;
  words.add(wordFactory->getWordKLOCKAN());
  words.add(wordFactory->getWordAER());

  hour = hour % 12;
  uint8_t minuteCluster = minute / 5;

  switch (minuteCluster) {
    case 0:
    
      break;

    case 1:
      words.add(wordFactory->getWordFEMMINUTER());
      words.add(wordFactory->getWordOEVER());
      break;

    case 2:
      words.add(wordFactory->getWordTIOMINUTER());
      words.add(wordFactory->getWordOEVER());
      break;

    case 3:
      words.add(wordFactory->getWordKVART());
      words.add(wordFactory->getWordOEVER());
      break;

    case 4:
      words.add(wordFactory->getWordTJUGO());
      words.add(wordFactory->getWordOEVER());
      break;

    case 5:
      words.add(wordFactory->getWordFEMMINUTER());
      words.add(wordFactory->getWordOEVER());
      words.add(wordFactory->getWordHALV());
      break;

    case 6:
      words.add(wordFactory->getWordHALV());
      break;

    case 7:
      words.add(wordFactory->getWordFEMMINUTER());
      words.add(wordFactory->getWordI());
      words.add(wordFactory->getWordHALV());
      break;

    case 8:
      words.add(wordFactory->getWordTJUGO());
      words.add(wordFactory->getWordI());
      break;

    case 9:
      words.add(wordFactory->getWordKVART());
      words.add(wordFactory->getWordI());
      break;

    case 10:
      words.add(wordFactory->getWordTIOMINUTER());
      words.add(wordFactory->getWordI());
      break;

    case 11:
      words.add(wordFactory->getWordFEMMINUTER());
      words.add(wordFactory->getWordI());
      break;
  }

  if (minuteCluster >= 7)
    hour ++;

  words.add(wordFactory->getWordForHour(hour));

  return words;
};
