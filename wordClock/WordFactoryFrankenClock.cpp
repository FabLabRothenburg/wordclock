#include "WordFactoryFrankenClock.h"

const Word WordFactoryFrankenClock::getWordES() const {
  return Word(0, 0, 2);
}

const Word WordFactoryFrankenClock::getWordIST() const {
  return Word(3, 0, 3);
}


const Word WordFactoryFrankenClock::getWordFUENF() const {
  return Word(7, 0, 4);
}

const Word WordFactoryFrankenClock::getWordZEHN() const {
  return Word(0, 1, 4);
}

const Word WordFactoryFrankenClock::getWordZWANZIG() const {
  return Word(4, 1, 7);
}


const Word WordFactoryFrankenClock::getWordVIERTEL() const {
  return Word(4, 2, 7);
}

const Word WordFactoryFrankenClock::getWordHALB() const {
  return Word(0, 4, 4);
}

const Word WordFactoryFrankenClock::getWordDREIVIERTEL() const {
  return Word(0, 2, 11);
}


const Word WordFactoryFrankenClock::getWordVOR() const {
  return Word(0, 3, 3);
}

const Word WordFactoryFrankenClock::getWordNACH() const {
  return Word(7, 3, 4);
}


const Word WordFactoryFrankenClock::getWordEIN() const {
  return Word(0, 5, 3);
}

const Word WordFactoryFrankenClock::getWordUHR() const {
  return Word(8, 9, 3);
}

const Word WordFactoryFrankenClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0: return Word(6, 8, 5);
    case 1: return Word(0, 5, 4);
    case 2: return Word(7, 5, 4);
    case 3: return Word(0, 6, 4);
    case 4: return Word(7, 6, 4);
    case 5: return Word(7, 4, 4);
    case 6: return Word(0, 7, 5);
    case 7: return Word(0, 8, 6);
    case 8: return Word(7, 7, 4);
    case 9: return Word(3, 9, 4);
    case 10: return Word(0, 9, 4);
    case 11: return Word(5, 4, 3);
  }

  /* not reached */
  for(;;);
}




