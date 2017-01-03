#include <EEPROM.h>
#include "PersistentColors.h"

#define PERSISTENT_COLOR_OFFSET_MAGIC	0x00
#define PERSISTENT_COLOR_OFFSET_RED	0x01
#define PERSISTENT_COLOR_OFFSET_GREEN	0x02
#define PERSISTENT_COLOR_OFFSET_BLUE	0x03

#define PERSISTENT_COLOR_MAGIC_VALUE	0x42


#define PERSISTENT_COLOR_DEFAULT_RED	255
#define PERSISTENT_COLOR_DEFAULT_GREEN	128
#define PERSISTENT_COLOR_DEFAULT_BLUE	0

void PersistentColors::setup() {
  EEPROM.begin(4);

  if (EEPROM.read(PERSISTENT_COLOR_OFFSET_MAGIC) != PERSISTENT_COLOR_MAGIC_VALUE) {
    EEPROM.write(PERSISTENT_COLOR_OFFSET_MAGIC, PERSISTENT_COLOR_MAGIC_VALUE);
    setRed(PERSISTENT_COLOR_DEFAULT_RED);
    setGreen(PERSISTENT_COLOR_DEFAULT_GREEN);
    setBlue(PERSISTENT_COLOR_DEFAULT_BLUE);
  }

  colorControllable->setRed(EEPROM.read(PERSISTENT_COLOR_OFFSET_RED));
  colorControllable->setGreen(EEPROM.read(PERSISTENT_COLOR_OFFSET_GREEN));
  colorControllable->setBlue(EEPROM.read(PERSISTENT_COLOR_OFFSET_BLUE));
}

void PersistentColors::setRed(uint8_t red) {
  colorControllable->setRed(red);
  EEPROM.write(PERSISTENT_COLOR_OFFSET_RED, red);
  EEPROM.commit();
}

void PersistentColors::setGreen(uint8_t green) {
  colorControllable->setGreen(green);
  EEPROM.write(PERSISTENT_COLOR_OFFSET_GREEN, green);
  EEPROM.commit();
}

void PersistentColors::setBlue(uint8_t blue) {
  colorControllable->setBlue(blue);
  EEPROM.write(PERSISTENT_COLOR_OFFSET_BLUE, blue);
  EEPROM.commit();
}
