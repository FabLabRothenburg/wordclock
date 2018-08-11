#include <EEPROM.h>
#include "PersistentStorage.h"

#define PERSISTENT_STORAGE_MAGIC_VALUE            0x42

#define PERSISTENT_STORAGE_DEFAULT_RED            140
#define PERSISTENT_STORAGE_DEFAULT_GREEN          64
#define PERSISTENT_STORAGE_DEFAULT_BLUE           0

#define PERSISTENT_STORAGE_FLAGS_MQTT_ENABLED     0


static uint8_t crcUpdate(uint8_t crc, uint8_t data) {
  uint8_t i;

  crc = crc ^ data;
  for (i = 0; i < 8; i++)
  {
    if (crc & 0x01)
      crc = (crc >> 1) ^ 0x8C;
    else
      crc >>= 1;
  }

  return crc;
}

uint8_t PersistentStorage::calculateCrc() {
  uint8_t crc;

  for (uint8_t i = 0; i < offsetof(PersistentStorage, crc); i ++) {
    crc = crcUpdate(crc, ((uint8_t *) this)[i]);
  }

  return crc;
}

void PersistentStorage::setup() {
  EEPROM.begin(0);

  for (uint8_t i = 0; i < sizeof(PersistentStorage); i ++) {
    ((uint8_t *)this)[i] = EEPROM.read(i);
  }

  if (crc != calculateCrc() || magicValue != PERSISTENT_STORAGE_MAGIC_VALUE) {
    resetToDefaults();
  }
}

void PersistentStorage::resetToDefaults() {
  memset(this, 0, sizeof(PersistentStorage));
  magicValue = PERSISTENT_STORAGE_MAGIC_VALUE;

  red = PERSISTENT_STORAGE_DEFAULT_RED;
  green = PERSISTENT_STORAGE_DEFAULT_GREEN;
  blue = PERSISTENT_STORAGE_DEFAULT_BLUE;

  flags.mqttEnabled = PERSISTENT_STORAGE_FLAGS_MQTT_ENABLED;

  commit();
}

void PersistentStorage::commit() {
  crc = calculateCrc();

  for (uint8_t i = 0; i < sizeof(PersistentStorage); i ++) {
    EEPROM.write(i, ((uint8_t *)this)[i]);
  }

  EEPROM.commit();
}

