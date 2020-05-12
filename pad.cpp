#include "pad.h"

Pad::Pad(int pin, int debounceInterval) {
  _pin              = pin;
  _pressed          = false;
  _lastPressed      = 0;
  _debounceInterval = debounceInterval;

  pinMode(pin, INPUT_PULLUP);
}

// Check the status of the press and the timing.
// In timeSinceLastPress, abs() handles the edge case of the Arduino timer
// overflowing and resetting to zero.
bool Pad::pressChanged() {
  const bool newPressed = digitalRead(_pin) == LOW;
  unsigned long timeSinceLastPress = abs(millis() - _lastPressed);

  // Check for status change and debouncing
  bool changed = newPressed != _pressed && timeSinceLastPress >= _debounceInterval;
  if (changed) {
    _pressed     = newPressed;
    _lastPressed = millis();
  }

  return changed;
}

bool Pad::isPressed() {
  return _pressed;
}
