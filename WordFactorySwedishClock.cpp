#include "WordFactorySwedishClock.h"

const Word WordFactorySwedishClock::getWordKLOCKAN() const {
  return Word(0, 0, 7);
}

const Word WordFactorySwedishClock::getWordAER() const {
  return Word(0, 9, 2);
}


const Word WordFactorySwedishClock::getWordFEMMINUTER() const {
  return Word(1, 3, 3);
}

const Word WordFactorySwedishClock::getWordTIOMINUTER() const {
  return Word(1, 6, 3);
}

const Word WordFactorySwedishClock::getWordTJUGO() const {
  return Word(2, 1, 5);
}


const Word WordFactorySwedishClock::getWordKVART() const {
  return Word(2, 2, 5);
}

const Word WordFactorySwedishClock::getWordHALV() const {
  return Word(4, 6, 4);
}


const Word WordFactorySwedishClock::getWordI() const {
  return Word(4, 3, 1);
}

const Word WordFactorySwedishClock::getWordOEVER() const {
  return Word(3, 7, 4);
}

const Word WordFactorySwedishClock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0: return Word(9, 2, 4);
    case 1: return Word(7, 0, 3);
    case 2: return Word(8, 0, 3);
    case 3: return Word(7, 2, 3);
    case 4: return Word(6, 7, 4);
    case 5: return Word(7, 6, 4);
    case 6: return Word(6, 3, 3);
    case 7: return Word(8, 6, 3);
    case 8: return Word(8, 2, 4);
    case 9: return Word(5, 1, 3);
    case 10: return Word(7, 5, 3);
    case 11: return Word(5, 5, 4);
  }

  /* not reached */
  for(;;);
}
