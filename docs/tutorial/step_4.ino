#include <Arduino.h>
#include <Joystick.h>

// The number of input buttons the controller has. For PIU pads, this will be 5
#define NUMBER_OF_BUTTONS 5

// Debounce interval, in milliseconds
#define DEBOUNCE_INTERVAL 20

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

int buttonPins[NUMBER_OF_BUTTONS];
bool isButtonPressed[NUMBER_OF_BUTTONS];
unsigned long lastChanges[NUMBER_OF_BUTTONS];

void setup() {
  Joystick.begin();

  // We still have to configure the pins one by one
  buttonPins[0] = 2;
  buttonPins[1] = 4;
  buttonPins[2] = 6;
  buttonPins[3] = 8;
  buttonPins[4] = 10;

  // Iterate over all buttons to set them up
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    isButtonPressed[i] = false;
    lastChanges[i] = 0;
  }
}

void loop() {
  // Iterate over all buttons to read them
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
    readButton(i);
  }
}

void readButton(int index) {
  bool newState = digitalRead(buttonPins[index]) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChanges[index]);

  bool stateChanged = newState != isButtonPressed[index];
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButtonPressed[index] = newState;
    lastChanges[index] = millis();

    Joystick.setButton(index, isButtonPressed[index]);
  }
}
