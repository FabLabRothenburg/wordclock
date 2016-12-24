#ifndef I_ANIMATOR_H
#define I_ANIMATOR_H

#include <Arduino.h>

class IAnimator
{
  public:
    virtual void setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue) = 0;
    virtual void clearPixel(uint8_t x, uint8_t y) = 0;
    virtual void commit() = 0;
};


#endif  /* !I_ANIMATOR_H */




