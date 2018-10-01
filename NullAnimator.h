#ifndef NULL_ANIMATOR_H
#define NULL_ANIMATOR_H

#include <Arduino.h>
#include "IDisplayDriver.h"
#include "IAnimator.h"

class NullAnimator: public IAnimator
{
  protected:
    IDisplayDriver *driver;

    uint8_t red = 255;
    uint8_t green = 255;
    uint8_t blue = 255;

  public:
    NullAnimator(IDisplayDriver *driver): driver(driver) { }

    virtual void setRed(uint8_t red);
    virtual void setGreen(uint8_t green);
    virtual void setBlue(uint8_t blue);

    virtual void setDots(uint8_t count);
    virtual void setPixel(uint8_t x, uint8_t y);
    virtual void clearPixel(uint8_t x, uint8_t y);
    virtual void commit();

  private:
    void updateColors(uint32_t oldColor, uint32_t newColor);
};


#endif  /* !NULL_ANIMATOR_H */





