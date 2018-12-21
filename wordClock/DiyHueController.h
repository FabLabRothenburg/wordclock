#ifndef DIY_HUE_CONTROLLER_H
#define DIY_HUE_CONTROLLER_H

#include "IColorControllable.h"

class DiyHueController : public IColorControllable {
  private:
    IColorControllable *controllable;

    bool light_state = true;
    uint8_t rgb[3] = { 192, 0, 0 };
    uint8_t bri;
    uint8_t sat;
    uint8_t color_mode;
    int ct;
    int hue;
    float step_level[3];
    float current_rgb[3];
    float x, y;

  public:
    DiyHueController(IColorControllable *controllable)
      : controllable(controllable) { apply_colors(); }
    void maintain();

    void setLightState(bool light_state) { this->light_state = light_state; }
    bool getLightState() const { return light_state; }

    uint8_t getColorMode() const { return color_mode; }

    virtual void setRed(uint8_t red);
    virtual void setGreen(uint8_t green);
    virtual void setBlue(uint8_t blue);
    virtual void setRGB(uint8_t red, uint8_t green, uint8_t blue);

    void setColorX(float x);
    void setColorY(float y);

    float getColorX() const { return x; }
    float getColorY() const { return y; }

    void setBri(uint8_t bri) { this->bri = bri; }
    void incBri(int bri);
    uint8_t getBri() const { return bri; }

    void setCt(int ct);
    void setSat(uint8_t sat);
    void setHue(int hue);

    int getCt() const { return ct; }
    uint8_t getSat() const { return sat; }
    int getHue() const { return hue; }

    void alert();
    void process_lightdata(float transitiontime);

  private:
    void convert_hue();
    void convert_xy();
    void convert_ct();

    void apply_colors();

};

extern DiyHueController diyHueController;

#endif  /* DIY_HUE_CONTROLLER_H */


