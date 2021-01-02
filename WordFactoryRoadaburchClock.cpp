#include "WordFactoryRoadaburchClock.h"

const Word WordFactoryRoadaburchClock::getWordSCHO() const {
  return Word(7, 0, 4);
}

const Word WordFactoryRoadaburchClock::getWordETZ() const {
  return Word(0, 0, 3);
}

const Word WordFactoryRoadaburchClock::getWordIS() const {
  return Word(4, 0, 2);
}

const Word WordFactoryRoadaburchClock::getWordFUENF() const {
  return Word(1, 1, 4);
}

const Word WordFactoryRoadaburchClock::getWordZEAH() const {
  return Word(6, 1, 4);
}

const Word WordFactoryRoadaburchClock::getWordFERDL() const {
  return Word(5, 2, 5);
}

const Word WordFactoryRoadaburchClock::getWordHALBER() const {
  return Word(0, 4, 6);
}

const Word WordFactoryRoadaburchClock::getWordDREIFERDL() const {
  return Word(1, 2, 9);
}

const Word WordFactoryRoadaburchClock::getWordVOR() const {
  return Word(1, 3, 3);
}

const Word WordFactoryRoadaburchClock::getWordNACH() const {
  return Word(6, 3, 4);
}

const Word WordFactoryRoadaburchClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0:  return Word(4, 9, 6);       // 12
    case 1:  return Word(2, 5, 4);
    case 2:  return Word(0, 5, 4);
    case 3:  return Word(1, 6, 5);
    case 4:  return Word(6, 5, 5);
    case 5:  return Word(6, 6, 5);
    case 6:  return Word(0, 7, 6);
    case 7:  return Word(6, 7, 5);
    case 8:  return Word(0, 8, 5);
    case 9:  return Word(6, 8, 5);
    case 10: return Word(6, 4, 5);
    case 11: return Word(0, 9, 4);
  }

  /* not reached */
  for(;;);
}
