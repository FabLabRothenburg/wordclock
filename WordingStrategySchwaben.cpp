#include "WordingStrategySchwaben.h"

WordList WordingStrategySchwaben::wordsForTime(uint8_t hour, uint8_t minute) {
  WordList words;
  words.add(wordFactory->getWordES());
  words.add(wordFactory->getWordIST());

  hour = hour % 12;
  uint8_t minuteCluster = minute / 5;

  switch (minuteCluster) {
    case 0:
      words.add(wordFactory->getWordUHR());

      if (hour == 1) {
        /* special case: ES IST EIN UHR */
        words.add(wordFactory->getWordEIN());
        return words;
      }
      break;

    case 1:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordNACH());
      break;

    case 2:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordVOR());
      words.add(wordFactory->getWordVIERTEL());
      break;

    case 3:
      words.add(wordFactory->getWordVIERTEL());
      break;

    case 4:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordNACH());
      words.add(wordFactory->getWordVIERTEL());
      break;

    case 5:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordVOR());
      words.add(wordFactory->getWordHALB());
      break;

    case 6:
      words.add(wordFactory->getWordHALB());
      break;

    case 7:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordNACH());
      words.add(wordFactory->getWordHALB());
      break;

    case 8:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordVOR());
      words.add(wordFactory->getWordDREIVIERTEL());
      break;

    case 9:
      words.add(wordFactory->getWordDREIVIERTEL());
      break;

    case 10:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordNACH());
      words.add(wordFactory->getWordDREIVIERTEL());
      break;

    case 11:
      words.add(wordFactory->getWordFUENF());
      words.add(wordFactory->getWordVOR());
      break;
  }

  if (minuteCluster >= 2)
    hour ++;

  words.add(wordFactory->getWordForHour(hour));

  return words;
};
