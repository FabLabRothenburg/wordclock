#ifndef DISPLAY_DRIVER_MINS_FIRST_CLOCK_H
#define DISPLAY_DRIVER_MINS_FIRST_CLOCK_H

#include <Adafruit_NeoPixel.h>
#include "DisplayDriver10x11Clock.h"

// 10x11Clock: Die ersten 4 Pixel gehoeren den Minuten. Verkabelungsstart links unten. Min-Start rechts oben
class DisplayDriverMinutesFirstClock : public DisplayDriver10x11Clock
{
  public:
    DisplayDriverMinutesFirstClock()  {}
    DisplayDriverMinutesFirstClock(uint8_t digPin);

  public:
    virtual void setDots(uint8_t count, uint32_t color);

  protected:
    virtual uint8_t getPixelIndex(uint8_t x, uint8_t y);
};

#endif  /* DISPLAY_DRIVER_MINS_FIRST_CLOCK_H */
