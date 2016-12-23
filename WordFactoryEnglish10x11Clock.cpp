#include "WordFactoryEnglish10x11Clock.h"

const Word WordFactoryEnglish10x11Clock::getWordIT() const {
  return Word(0, 0, 2);
}

const Word WordFactoryEnglish10x11Clock::getWordIS() const {
  return Word(3, 0, 2);
}

const Word WordFactoryEnglish10x11Clock::getWordFIVE() const {
  return Word(6, 2, 4);
}

const Word WordFactoryEnglish10x11Clock::getWordTWENTY() const {
  return Word(0, 2, 6);
}

const Word WordFactoryEnglish10x11Clock::getWordTEN() const {
  return Word(5, 3, 3);
}

const Word WordFactoryEnglish10x11Clock::getWordQUARTER() const {
  return Word(2, 1, 7);
}

const Word WordFactoryEnglish10x11Clock::getWordTO() const {
  return Word(9, 3, 2);
}

const Word WordFactoryEnglish10x11Clock::getWordHALF() const {
  return Word(0, 3, 4);
}

const Word WordFactoryEnglish10x11Clock::getWordPAST() const {
  return Word(0, 4, 4);
}

const Word WordFactoryEnglish10x11Clock::getWordOCLOCK() const {
  return Word(5, 9, 6);
}

const Word WordFactoryEnglish10x11Clock::getWordForHour(uint8_t hour) const {
  switch (hour % 12) {
    case 0: return Word(5, 8, 6);
    case 1: return Word(0, 5, 3);
    case 2: return Word(8, 6, 3);
    case 3: return Word(6, 5, 5);
    case 4: return Word(0, 6, 4);
    case 5: return Word(4, 6, 4);
    case 6: return Word(3, 5, 3);
    case 7: return Word(0, 8, 5);
    case 8: return Word(0, 7, 5);
    case 9: return Word(7, 4, 4);
    case 10: return Word(0, 9, 3);
    case 11: return Word(5, 7, 6);
  }

  /* not reached */
  for(;;);
}




