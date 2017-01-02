#ifndef I_COLOR_CONTROLLABLE_H
#define I_COLOR_CONTROLLABLE_H

#include <stdint.h>

class IColorControllable
{
  public:
    virtual void setRed(uint8_t red) = 0;
    virtual void setGreen(uint8_t green) = 0;
    virtual void setBlue(uint8_t blue) = 0;
};


#endif  /* !I_COLOR_CONTROLLABLE_H */





