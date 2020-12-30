#ifndef WORD_FACTORY_SWEDISH_CLOCK_H
#define WORD_FACTORY_SWEDISH_CLOCK_H

#include "Word.h"

class WordFactorySwedishClock {
  public:
    virtual const Word getWordKLOCKAN() const;
    virtual const Word getWordAER() const;
    virtual const Word getWordFEMMINUTER() const;
    virtual const Word getWordTIOMINUTER() const;
    virtual const Word getWordTJUGO() const;

    virtual const Word getWordKVART() const;
    virtual const Word getWordHALV() const;

    virtual const Word getWordI() const;
    virtual const Word getWordOEVER() const;

    virtual const Word getWordForHour(uint8_t hour) const;
};

#endif  /* !WORD_FACTORY_SWEDISH_CLOCK_H */
