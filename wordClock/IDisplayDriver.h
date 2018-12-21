#ifndef IDISPLAY_DRIVER_H
#define IDISPLAY_DRIVER_H

#include <Arduino.h>

class IDisplayDriver
{
  public:
    virtual int width() = 0;
    virtual int height() = 0;
    virtual void setDots(uint8_t count, uint32_t color) = 0;

    virtual uint32_t getPixel(uint8_t x, uint8_t y) = 0;
    virtual void setPixel(uint8_t x, uint8_t y, uint32_t color) = 0;

    virtual void show() = 0;
};

#endif  /* !IDISPLAY_DRIVER_H */


