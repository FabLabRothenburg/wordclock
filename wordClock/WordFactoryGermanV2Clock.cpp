#include "WordFactoryGermanV2Clock.h"

const Word WordFactoryGermanV2Clock::getWordES() const {
  return Word(0, 0, 2);
}

const Word WordFactoryGermanV2Clock::getWordIST() const {
  return Word(3, 0, 3);
}


const Word WordFactoryGermanV2Clock::getWordFUENF() const {
  return Word(7, 0, 4);
}

const Word WordFactoryGermanV2Clock::getWordZEHN() const {
  return Word(0, 1, 4);
}

const Word WordFactoryGermanV2Clock::getWordZWANZIG() const {
  return Word(4, 1, 7);
}


const Word WordFactoryGermanV2Clock::getWordVIERTEL() const {
  return Word(4, 2, 7);
}

const Word WordFactoryGermanV2Clock::getWordHALB() const {
  return Word(0, 4, 4);
}

const Word WordFactoryGermanV2Clock::getWordDREIVIERTEL() const {
  return Word(0, 2, 11);
}


const Word WordFactoryGermanV2Clock::getWordVOR() const {
  return Word(6, 3, 3);
}

const Word WordFactoryGermanV2Clock::getWordNACH() const {
  return Word(2, 3, 4);
}


const Word WordFactoryGermanV2Clock::getWordEIN() const {
  return Word(2, 5, 3);
}

const Word WordFactoryGermanV2Clock::getWordUHR() const {
  return Word(8, 9, 3);
}

const Word WordFactoryGermanV2Clock::getWordForHour(uint8_t hour) const {
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




