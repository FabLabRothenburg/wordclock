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
      : controllable(controllable) { }
    void maintain();

    void setLightState(bool light_state) { this->light_state = light_state; }

    virtual void setRed(uint8_t red);
    virtual void setGreen(uint8_t green);
    virtual void setBlue(uint8_t blue);

    void setColorX(float x);
    void setColorY(float y);

    void setBri(uint8_t bri) { this->bri = bri; }
    void incBri(int bri);

    void setCt(int ct);
    void setSat(uint8_t sat);
    void setHue(int hue);

    void alert();
    void process_lightdata(float transitiontime);

  private:
    void convert_hue();
    void convert_xy();
    void convert_ct();

};

extern DiyHueController diyHueController;

#endif  /* DIY_HUE_CONTROLLER_H */


