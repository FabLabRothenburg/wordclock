#ifndef DISPLAY_DRIVER_FRICKEL_CLOCK_H
#define DISPLAY_DRIVER_FRICKEL_CLOCK_H

#include <Adafruit_NeoPixel.h>
#include "IDisplayDriver.h"
#include "IAnimator.h"

class DisplayDriverFrickelClock : public IDisplayDriver
{
  private:
    uint8_t pin = 5;
    Adafruit_NeoPixel pixels = { 106, pin, NEO_GRB + NEO_KHZ800 };

  public:
    void setup();

    virtual int width();
    virtual int height();

    virtual void setDots(uint8_t count, uint32_t color) { }
    
    virtual uint32_t getPixel(uint8_t x, uint8_t y);
    virtual void setPixel(uint8_t x, uint8_t y, uint32_t color);

    virtual void show();

  private:
    uint8_t getPixelIndex(uint8_t x, uint8_t y);
};

#endif  /* !DISPLAY_DRIVER_FRICKEL_CLOCK_H */




