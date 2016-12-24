#ifndef INCREMENTAL_ANIMATOR_H
#define INCREMENTAL_ANIMATOR_H

#include <Arduino.h>
#include "IDisplayDriver.h"
#include "IAnimator.h"

class IncrementalAnimator: public IAnimator
{
  private:
    IDisplayDriver *driver;

  public:
    IncrementalAnimator(IDisplayDriver *driver): driver(driver) { }

    virtual void setDots(uint8_t count, uint8_t red, uint8_t green, uint8_t blue);
    virtual void setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
    virtual void clearPixel(uint8_t x, uint8_t y);
    virtual void commit();
};


#endif  /* !INCREMENTAL_ANIMATOR_H */






