#include "WordFactoryFrickelClock.h"

const Word WordFactoryFrickelClock::getWordES() const {
  return Word(0, 0, 2);
}

const Word WordFactoryFrickelClock::getWordIST() const {
  return Word(3, 0, 3);
}

const Word WordFactoryFrickelClock::getWordFUENF() const {
  return Word(7, 0, 4);
}

const Word WordFactoryFrickelClock::getWordUND() const {
  return Word(0, 1, 3);
}

const Word WordFactoryFrickelClock::getWordZWANZIG() const {
  return Word(4, 1, 7);
}

const Word WordFactoryFrickelClock::getWordZEHN() const {
  return Word(0, 2, 4);
}

const Word WordFactoryFrickelClock::getWordVIERTEL() const {
  return Word(4, 2, 7);
}

const Word WordFactoryFrickelClock::getWordNACH() const {
  return Word(0, 3, 4);
}

const Word WordFactoryFrickelClock::getWordHALB() const {
  return Word(5, 3, 4);
}

const Word WordFactoryFrickelClock::getWordVOR() const {
  return Word(0, 4, 3);
}

const Word WordFactoryFrickelClock::getWordEIN() const {
  return Word(7, 4, 3);
}

const Word WordFactoryFrickelClock::getWordUHR() const {
  return Word(8, 9, 3);
}

const Word WordFactoryFrickelClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0: return Word(6, 8, 5);
    case 1: return Word(7, 4, 4);
    case 2: return Word(5, 4, 4);
    case 3: return Word(0, 6, 4);
    case 4: return Word(7, 6, 4);
    case 5: return Word(4, 5, 4);
    case 6: return Word(0, 7, 5);
    case 7: return Word(0, 8, 6);
    case 8: return Word(7, 7, 4);
    case 9: return Word(0, 5, 4);
    case 10: return Word(0, 9, 4);
    case 11: return Word(8, 5, 3);
    case 12: return Word(6, 8, 5);
  }

  /* not reached */
  for(;;);
}




