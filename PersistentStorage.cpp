#ifdef ESP8266
#  include <ESP8266WiFi.h>
#endif

#include <EEPROM.h>
#include "PersistentStorage.h"

#define PERSISTENT_STORAGE_MAGIC_VALUE            0x42

#define PERSISTENT_STORAGE_DEFAULT_RED            140
#define PERSISTENT_STORAGE_DEFAULT_GREEN          64
#define PERSISTENT_STORAGE_DEFAULT_BLUE           0

#define PERSISTENT_STORAGE_FLAGS_MQTT_ENABLED     0

PersistentStorage persistentStorage;

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
  uint8_t crc = 0;

  for (uint8_t i = 0; i < offsetof(PersistentStorage, crc); i ++) {
    crc = crcUpdate(crc, ((uint8_t *) this)[i]);
  }

  return crc;
}

void PersistentStorage::setup() {
  EEPROM.begin(sizeof(PersistentStorage));

  Serial.println("restoring " + String(sizeof(PersistentStorage)) + " bytes from EEPROM");
  for (uint8_t i = 0; i < sizeof(PersistentStorage); i ++) {
    ((uint8_t *)this)[i] = EEPROM.read(i);
  }

  Serial.println("restored eeprom data, stored magic: " + String(magicValue));
  Serial.println("stored crc: " + String(crc));
  Serial.println("calculated crc: " + String(calculateCrc()));
  if (crc != calculateCrc() || magicValue != PERSISTENT_STORAGE_MAGIC_VALUE) {
    Serial.println("restoring defaults");
    resetToDefaults();
  }
}

void PersistentStorage::resetToDefaults() {
  memset(this, 0, sizeof(PersistentStorage));
  magicValue = PERSISTENT_STORAGE_MAGIC_VALUE;

  red = PERSISTENT_STORAGE_DEFAULT_RED;
  green = PERSISTENT_STORAGE_DEFAULT_GREEN;
  blue = PERSISTENT_STORAGE_DEFAULT_BLUE;

  strcpy(ntp.domain, "0.de.pool.ntp.org");

  flags.mqttEnabled = PERSISTENT_STORAGE_FLAGS_MQTT_ENABLED;

  commit();
}

void PersistentStorage::commit() {
  crc = calculateCrc();
  Serial.println("updated crc to " + String(crc));

  for (uint8_t i = 0; i < sizeof(PersistentStorage); i ++) {
    EEPROM.write(i, ((uint8_t *)this)[i]);
  }

  Serial.println("stored data to EEPROM.");
  EEPROM.commit();
}

