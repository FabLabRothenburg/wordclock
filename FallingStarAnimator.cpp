#include "FallingStarAnimator.h"

#define FALLING_STAR_FACTOR 0.8

FallingStar::FallingStar(IDisplayDriver *driver, uint8_t x, uint8_t y, int delay)
  : driver(driver), x(x), y(y), delay(delay) {
  color = driver->getPixel(x, y);
  applied = true;
  finished = false;
}

bool FallingStar::animate() {
  if (finished)
    return true;

  if (delay) {
    delay --;
    return false;
  }

  if (applied)
    driver->setPixel(x, y, 0);

  y ++;

  if (y >= driver->height()) {
    finished = true;
    return true;
  }

  if (driver->getPixel(x, y)) {
    /* pixel is used otherwise, don't animate here */
    applied = false;
    return false;
  }

  // FIXME decide for either RGB or single color value
  uint8_t r = (uint8_t)(color >> 16);
  uint8_t g = (uint8_t)(color >>  8);
  uint8_t b = (uint8_t)(color >>  0);

  r *= FALLING_STAR_FACTOR;
  g *= FALLING_STAR_FACTOR;
  b *= FALLING_STAR_FACTOR;

  color = ((uint32_t)r << 16) | ((uint32_t)g <<  8) | ((uint32_t)b <<  0);
  driver->setPixel(x, y, color);
  applied = true;
  return false;
}

void FallingStarAnimator::clearPixel(uint8_t x, uint8_t y) {
  if (starCount == FALLING_STAR_LIMIT) {
    Serial.print("FALLING_STAR_LIMIT reached\n");
    driver->setPixel(x, y, 0);
    return;
  }
  
  FallingStar newStar = { driver, x, y, starCount * 2 };
  stars[starCount ++] = newStar;
}

void FallingStarAnimator::commit() {
  bool finished;

  do {
    finished = true;

    for (uint8_t i = 0; i < starCount; i ++) 
      if (!stars[i].animate())
	finished = false;

    driver->show();
    delay(50);
  } while(!finished);

  starCount = 0;
}
