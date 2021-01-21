#include <Arduino.h>

#include "DisplayDriverMinutesFirstClock.h"

DisplayDriverMinutesFirstClock::DisplayDriverMinutesFirstClock(uint16_t digPin)
  : DisplayDriver10x11Clock(digPin) {
}

void DisplayDriverMinutesFirstClock::setDots(uint8_t count, uint32_t color)
{
  uint8_t positions[4] = {2, 1, 0, 3}; // 1st 4 pixels for the minutes
  uint8_t i = 0;

  for (; i < count; ++i)
    pixels.setPixelColor(positions[i], color);

  for (; i < 4; ++i)
    pixels.setPixelColor(positions[i], 0);
}

uint8_t DisplayDriverMinutesFirstClock::getPixelIndex(uint8_t x, uint8_t y)
{
  if ((y % 2) == 1) // x axis is flipped if y is odd
    x = width() - 1 - x;

  return y * width() + x + 4; // 1st 4 pixels for the minutes
}
