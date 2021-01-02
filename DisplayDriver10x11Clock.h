#ifndef DISPLAY_DRIVER_10x11_CLOCK_H
#define DISPLAY_DRIVER_10x11_CLOCK_H

#include <Adafruit_NeoPixel.h>
#include "IDisplayDriver.h"

// 10x11Clock: Verkabelungsstart links oben. Die letzten 4 Pixel gehoeren den Minuten. Min-Start links oben
class DisplayDriver10x11Clock : public IDisplayDriver
{
  protected:
    uint8_t pin = 5;  // D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15
    Adafruit_NeoPixel pixels = { 114, pin, NEO_GRB + NEO_KHZ800 };

  public:
    void setup();

    virtual int width();
    virtual int height();
    
    virtual void setDots(uint8_t count, uint32_t color);

    virtual uint32_t getPixel(uint8_t x, uint8_t y);
    virtual void setPixel(uint8_t x, uint8_t y, uint32_t color);

    virtual void show();

  protected:
    virtual uint8_t getPixelIndex(uint8_t x, uint8_t y);
};

#endif  /* !DISPLAY_DRIVER_10x11_CLOCK_H */
