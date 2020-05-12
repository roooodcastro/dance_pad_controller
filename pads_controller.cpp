#include "pads_controller.h"

// Initializes the Joystick library. It creates only the exact number of buttons
// needed to map all pads.
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   NUMBER_OF_PADS, 0,     // Button Count, Hat Switch Count
                   false, false, false,   // No X, Y, or Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering

Pad *pads[NUMBER_OF_PADS];

void setupPads() {
  Joystick.begin();
  
  for (int padIndex = 0; padIndex < NUMBER_OF_PADS; padIndex++) {
    pads[padIndex] = new Pad(SENSOR_PINS[padIndex], DEBOUNCE_INTERVAL);
  }
}

// Iterates over all pads, checking if each one is pressed and sending the
// appropriate inputs to the Joystick and LED controller.
void checkPads() {
  for (int padIndex = 0; padIndex < NUMBER_OF_PADS; padIndex++) {
    Pad *pad = pads[padIndex];
    if (pad->pressChanged()) {
      Joystick.setButton(padIndex, pad->isPressed());
    }
  }
}
