#ifndef INCREMENTAL_ANIMATOR_H
#define INCREMENTAL_ANIMATOR_H

#include <Arduino.h>
#include "IDisplayDriver.h"
#include "AnimatorNull.h"

class IncrementalAnimator: public NullAnimator
{
  public:
    IncrementalAnimator(IDisplayDriver *driver): NullAnimator(driver) { }

    virtual void setPixel(uint8_t x, uint8_t y);
    virtual void clearPixel(uint8_t x, uint8_t y);
};


#endif  /* !INCREMENTAL_ANIMATOR_H */
