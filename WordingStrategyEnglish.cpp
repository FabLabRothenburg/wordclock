#include "WordingStrategyEnglish.h"

WordList WordingStrategyEnglish::wordsForTime(uint8_t hour, uint8_t minute) {
  WordList words;
  words.add(wordFactory->getWordIT());
  words.add(wordFactory->getWordIS());

  hour = hour % 12;
  uint8_t minuteCluster = minute / 5;

  switch (minuteCluster) {
    case 0:
      words.add(wordFactory->getWordOCLOCK());
      break;

    case 1:
      words.add(wordFactory->getWordFIVE());
      words.add(wordFactory->getWordPAST());
      break;

    case 2:
      words.add(wordFactory->getWordTEN());
      words.add(wordFactory->getWordPAST());
      break;

    case 3:
      words.add(wordFactory->getWordQUARTER());
      words.add(wordFactory->getWordPAST());
      break;

    case 4:
      words.add(wordFactory->getWordTWENTY());
      words.add(wordFactory->getWordPAST());
      break;

    case 5:
      words.add(wordFactory->getWordTWENTY());
      words.add(wordFactory->getWordFIVE());
      words.add(wordFactory->getWordPAST());
      break;

    case 6:
      words.add(wordFactory->getWordHALF());
      words.add(wordFactory->getWordPAST());
      break;

    case 7:
      words.add(wordFactory->getWordTWENTY());
      words.add(wordFactory->getWordFIVE());
      words.add(wordFactory->getWordTO());
      break;

    case 8:
      words.add(wordFactory->getWordTWENTY());
      words.add(wordFactory->getWordTO());
      break;

    case 9:
      words.add(wordFactory->getWordQUARTER());
      words.add(wordFactory->getWordTO());
      break;

    case 10:
      words.add(wordFactory->getWordTEN());
      words.add(wordFactory->getWordTO());
      break;

    case 11:
      words.add(wordFactory->getWordFIVE());
      words.add(wordFactory->getWordTO());
      break;
  }

  if (minuteCluster >= 7)
    hour ++;

  words.add(wordFactory->getWordForHour(hour));

  return words;
};

