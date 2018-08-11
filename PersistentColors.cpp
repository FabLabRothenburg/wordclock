#include "PersistentColors.h"

void PersistentColors::setup() {
  colorControllable->setRed(persistentStorage->red);
  colorControllable->setGreen(persistentStorage->green);
  colorControllable->setBlue(persistentStorage->blue);
}

void PersistentColors::setRed(uint8_t red) {
  persistentStorage->red = red;
  persistentStorage->commit();
}

void PersistentColors::setGreen(uint8_t green) {
  persistentStorage->green = green;
  persistentStorage->commit();
}

void PersistentColors::setBlue(uint8_t blue) {
  persistentStorage->blue = blue;
  persistentStorage->commit();
}
