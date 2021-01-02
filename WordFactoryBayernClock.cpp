#include "WordFactoryBayernClock.h"

const Word WordFactoryBayernClock::getWordES() const {
  return Word(0, 0, 2);
}

const Word WordFactoryBayernClock::getWordIS() const {
  return Word(4, 0, 2);
}

const Word WordFactoryBayernClock::getWordFUEMF() const {
  return Word(7, 0, 4);
}

const Word WordFactoryBayernClock::getWordZEHN() const {
  return Word(0, 1, 4);
}

const Word WordFactoryBayernClock::getWordZWANZG() const {
  return Word(5, 1, 6);
}

const Word WordFactoryBayernClock::getWordVOA() const {
  return Word(6, 3, 3);
}

const Word WordFactoryBayernClock::getWordNOCH() const {
  return Word(0, 3, 4);
}

const Word WordFactoryBayernClock::getWordPUNKT() const {
  return Word(6, 4, 5);
}

const Word WordFactoryBayernClock::getWordVIADL() const {
  return Word(5, 2, 5);
}

const Word WordFactoryBayernClock::getWordHOIWE() const {
  return Word(1, 4, 5);
}

const Word WordFactoryBayernClock::getWordDREIVIADL() const {
  return Word(1, 2, 9);
}

const Word WordFactoryBayernClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0:  return Word(5, 9, 6);       // 12
    case 1:  return Word(2, 5, 4);
    case 2:  return Word(0, 5, 4);
    case 3:  return Word(1, 6, 4);
    case 4:  return Word(6, 6, 5);
    case 5:  return Word(0, 7, 5);
    case 6:  return Word(5, 8, 6);
    case 7:  return Word(5, 5, 5);
    case 8:  return Word(0, 9, 5);
    case 9:  return Word(5, 7, 5);
    case 10: return Word(0, 8, 5);
    case 11: return Word(7, 9, 4);
  }

  /* not reached */
  for(;;);
}
