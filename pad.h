#ifndef PAD_H
#define PAD_H

#include <Arduino.h>

class Pad
{
  public:
    Pad(int pin, int debounceInterval);
    bool pressChanged();
    bool isPressed();

  private:
    int           _pin;
    int           _debounceInterval;
    bool          _pressed;
    unsigned long _lastPressed;
};

#endif
