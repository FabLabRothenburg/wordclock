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

    struct {
      char ssid[16];
      char password[64];
    } wifi;

    struct {
      char domain[32];
      char clientId[16];
      char user[16];
      char password[16];
    } mqtt;

    struct {
      char domain[32];
    } ntp;

    struct {
      unsigned int mqttEnabled : 1;
    } flags;

    void setup();
    void resetToDefaults();
    void commit();

  private:
    uint8_t crc;
    uint8_t calculateCrc();
};


#endif  /* !I_PERSISTENT_STORAGE_H */







