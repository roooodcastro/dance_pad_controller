#include <Arduino.h>
#include <Joystick.h>

// The number of input buttons the controller has. For PIU pads, this will be 5
#define NUMBER_OF_BUTTONS 5

// Which pins are assigned to which buttons
#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 4
#define BUTTON_3_PIN 6
#define BUTTON_4_PIN 8
#define BUTTON_5_PIN 10

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

void setup() {
  Joystick.begin();

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
}

void loop() {
  // Because we're using the PULLUP mode, the LOW value is actually the button's
  // pressed state, and not the HIGH value.
  bool isButton1Pressed = digitalRead(BUTTON_1_PIN) == LOW;
  bool isButton2Pressed = digitalRead(BUTTON_2_PIN) == LOW;
  bool isButton3Pressed = digitalRead(BUTTON_3_PIN) == LOW;
  bool isButton4Pressed = digitalRead(BUTTON_4_PIN) == LOW;
  bool isButton5Pressed = digitalRead(BUTTON_5_PIN) == LOW;

  // Write data to the host PC
  Joystick.setButton(0, isButton1Pressed);
  Joystick.setButton(1, isButton2Pressed);
  Joystick.setButton(2, isButton3Pressed);
  Joystick.setButton(3, isButton4Pressed);
  Joystick.setButton(4, isButton5Pressed);
}
