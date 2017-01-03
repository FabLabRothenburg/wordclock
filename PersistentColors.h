#ifndef I_PERSISTENT_COLORS_H
#define I_PERSISTENT_COLORS_H

#include <stdint.h>
#include "IColorControllable.h"

class PersistentColors: public IColorControllable
{
    IColorControllable *colorControllable;
    bool needCommit = false;

  public:
    PersistentColors(IColorControllable *colorControllable)
      : colorControllable(colorControllable) { }

    void setup();

    virtual void setRed(uint8_t red);
    virtual void setGreen(uint8_t green);
    virtual void setBlue(uint8_t blue);
};


#endif  /* !I_PERSISTENT_COLORS_H */






