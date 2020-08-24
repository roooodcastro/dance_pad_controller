#ifndef PAD_LEDS_H
#define PAD_LEDS_H

#include <Arduino.h>
#include "configuration.h"

struct CRGB;
class PadLeds;

#ifdef ARROWS_HAVE_LEDS
#include <FastLED.h>

class PadLeds
{
  public:
    PadLeds(int padIndex, int ledsPerPad, CRGB color);
    void setState(bool onOff);
    CRGB *getLeds();

  private:
    int  _padIndex;
    int  _ledsPerPad;
    CRGB _color;
    CRGB _leds[LEDS_PER_ARROW];
};
#endif
#endif
