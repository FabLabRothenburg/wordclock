#ifndef I_PERSISTENT_STORAGE_H
#define I_PERSISTENT_STORAGE_H

#include <stdint.h>

class PersistentStorage
{
  private:
    uint8_t magicValue;

  public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    void setup();
    void resetToDefaults();
    void commit();

  private:
    uint8_t crc;
    uint8_t calculateCrc();
};


#endif  /* !I_PERSISTENT_STORAGE_H */







