#include "WordFactorySchwabenClock.h"

const Word WordFactorySchwabenClock::getWordES() const {
  return Word(0, 0, 2);
}

const Word WordFactorySchwabenClock::getWordIST() const {
  return Word(3, 0, 3);
}


const Word WordFactorySchwabenClock::getWordFUENF() const {
  return Word(7, 0, 4);
}

const Word WordFactorySchwabenClock::getWordZEHN() const {
  return Word(0, 1, 4);
}

const Word WordFactorySchwabenClock::getWordZWANZIG() const {
  return Word(4, 1, 7);
}

const Word WordFactorySchwabenClock::getWordVIERTEL() const {
  return Word(4, 3, 7);
}

const Word WordFactorySchwabenClock::getWordHALB() const {
  return Word(0, 4, 4);
}

const Word WordFactorySchwabenClock::getWordDREIVIERTEL() const {
  return Word(0, 3, 11);
}


const Word WordFactorySchwabenClock::getWordVOR() const {
  return Word(6, 2, 3);
}

const Word WordFactorySchwabenClock::getWordNACH() const {
  return Word(2, 2, 4);
}


const Word WordFactorySchwabenClock::getWordEIN() const {
  return Word(2, 5, 3);
}

const Word WordFactorySchwabenClock::getWordUHR() const {
  return Word(8, 9, 3);
}

const Word WordFactorySchwabenClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0: return Word(5, 4, 5);
    case 1: return Word(2, 5, 4);
    case 2: return Word(0, 5, 4);
    case 3: return Word(1, 6, 4);
    case 4: return Word(7, 7, 4);
    case 5: return Word(7, 6, 4);
    case 6: return Word(1, 9, 5);
    case 7: return Word(5, 5, 6);
    case 8: return Word(1, 8, 4);
    case 9: return Word(3, 7, 4);
    case 10: return Word(5, 8, 4);
    case 11: return Word(0, 7, 3);
  }

  /* not reached */
  for(;;);
}
