#ifndef DISPLAY_DRIVER_FRICKEL_CLOCK_H
#define DISPLAY_DRIVER_FRICKEL_CLOCK_H

#include <Adafruit_NeoPixel.h>
#include "IDisplayDriver.h"
#include "IAnimator.h"

class DisplayDriverFrickelClock : public IDisplayDriver, public IAnimator
{
  public:
    void setup();

    virtual int width();
    virtual int height();
    
    virtual void setPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
    virtual void clearPixel(uint8_t x, uint8_t y);
    void clear();
    
    virtual void show();
};

#endif  /* !DISPLAY_DRIVER_FRICKEL_CLOCK_H */



