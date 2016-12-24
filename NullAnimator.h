#ifndef NULL_ANIMATOR_H
#define NULL_ANIMATOR_H

#include <Arduino.h>
#include "IDisplayDriver.h"
#include "IAnimator.h"

class NullAnimator: public IAnimator
{
  private:
    IDisplayDriver *driver;

  public:
    NullAnimator(IDisplayDriver *driver): driver(driver) { }

    virtual void setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
    virtual void clearPixel(uint8_t x, uint8_t y);
    virtual void commit();
};


#endif  /* !NULL_ANIMATOR_H */





