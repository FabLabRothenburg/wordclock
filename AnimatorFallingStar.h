#ifndef FALLING_STAR_ANIMATOR_H
#define FALLING_STAR_ANIMATOR_H

#include <Arduino.h>
#include "AnimatorNull.h"

#define FALLING_STAR_LIMIT 20

class FallingStar
{
  private:
    IDisplayDriver *driver;

    uint8_t x = 0;
    uint8_t y = 0;
    int delay = 0;
    uint32_t color = 0;
    bool applied = true;
    bool finished = false;

  public:
    FallingStar() { }
    FallingStar(IDisplayDriver *driver, uint8_t x, uint8_t y, int delay);

    bool animate();
};

class FallingStarAnimator: public NullAnimator
{
  private:
    FallingStar stars[FALLING_STAR_LIMIT];
    uint8_t starCount = 0;

  public:
    FallingStarAnimator(IDisplayDriver *driver): NullAnimator(driver) { }

    virtual void clearPixel(uint8_t x, uint8_t y);
    virtual void commit();
};


#endif  /* !FALLING_STAR_ANIMATOR_H */

