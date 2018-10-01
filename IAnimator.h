#ifndef I_ANIMATOR_H
#define I_ANIMATOR_H

#include <stdint.h>
#include "IColorControllable.h"

class IAnimator : public IColorControllable
{
  public:
    virtual void setDots(uint8_t count) = 0;
    virtual void setPixel(uint8_t x, uint8_t y) = 0;
    virtual void clearPixel(uint8_t x, uint8_t y) = 0;
    virtual void commit() = 0;

  protected:
    uint32_t pack(uint8_t r, uint8_t g, uint8_t b) { 
      return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | ((uint32_t)b <<  0);
    }
};


#endif  /* !I_ANIMATOR_H */




