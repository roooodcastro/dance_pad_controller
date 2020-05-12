#include "pad_leds.h"

PadLeds::PadLeds(int padIndex, int ledsPerPad, CRGB color) {
  _color      = color;
  _padIndex   = padIndex;
  _ledsPerPad = ledsPerPad;
}

void PadLeds::setState(CRGB *leds, bool onOff) {
  if (_padIndex != 2) {
    return; // Temporary while the pad is not ready
  }

  CRGB newColor = onOff ? _color : CRGB::Black;
  int ledOffset = _padIndex * _ledsPerPad;
  for (int i = 0; i < _ledsPerPad; i++) {
    //leds[ledOffset + i] = newColor;
    leds[i] = newColor;
  }
}
