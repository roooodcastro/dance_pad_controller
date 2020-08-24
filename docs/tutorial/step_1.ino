#include <Arduino.h>
#include <Joystick.h>

// The number of input buttons the controller has. For PIU pads, this will be 5
#define NUMBER_OF_BUTTONS 5

// Initializes the Joystick library. It creates only the exact number of buttons
// needed to map all pads. This initializer defines all types of input methods
// a controller might have, such as accelerator, brake, rudder, or analog axis.
// Because our controller only uses momentary button switches, everything else
// must be set to false, because their default value is true.
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, // Device ID and type
  NUMBER_OF_BUTTONS, 0,  // Button Count, Hat Switch Count
  false, false, false,   // No X, Y, or Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int buttonIndex;

void setup() {
  Joystick.begin();

  buttonIndex = 0;
}

void loop() {
  // For values from 0 to 4, we're setting the buttons in the "pressed" state
  // For values from 5 to 9, we're setting the buttons in the "released" state
  bool isButtonPressed = buttonIndex < 5;

  // Write data to the host PC
  Joystick.setButton(buttonIndex % 5, isButtonPressed);

  // Code needed to loop through all 5 buttons continuously
  buttonIndex += 1;
  if (buttonIndex == 10)
    buttonIndex = 0;

  // 100ms is slow enough to see what's happening and fast enough for it to be
  // interesting :)
  delay(100);
}
