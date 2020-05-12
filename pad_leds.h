#ifndef PAD_LEDS_H
#define PAD_LEDS_H

#include <Arduino.h>
#include <FastLED.h>

class PadLeds
{
  public:
    PadLeds(int padIndex, int ledsPerPad, CRGB color);
    void setState(CRGB *leds, bool onOff);

  private:
    int  _padIndex;
    int  _ledsPerPad;
    CRGB _color;
};
#endif
