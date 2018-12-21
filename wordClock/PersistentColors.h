#ifndef I_PERSISTENT_COLORS_H
#define I_PERSISTENT_COLORS_H

#include <stdint.h>
#include "IColorControllable.h"
#include "PersistentStorage.h"

class PersistentColors: public IColorControllable
{
    IColorControllable *colorControllable;

  public:
    PersistentColors(IColorControllable *colorControllable)
      : colorControllable(colorControllable) { }

    void setup();

    virtual void setRed(uint8_t red);
    virtual void setGreen(uint8_t green);
    virtual void setBlue(uint8_t blue);
    virtual void setRGB(uint8_t red, uint8_t green, uint8_t blue);
};


#endif  /* !I_PERSISTENT_COLORS_H */






