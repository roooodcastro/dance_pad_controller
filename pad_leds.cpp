#include "configuration.h"
#include "pad_leds.h"

#ifdef ARROWS_HAVE_LEDS
PadLeds::PadLeds(int padIndex, int ledsPerPad, CRGB color) {
  _color      = color;
  _padIndex   = padIndex;
  _ledsPerPad = ledsPerPad;
}

CRGB *PadLeds::getLeds() {
  return _leds;
}

void PadLeds::setState(bool onOff) {
  CRGB newColor = onOff ? _color : CRGB::Black;
  for (int i = 0; i < _ledsPerPad; i++) {
    _leds[i] = newColor;
  }
}
#endif