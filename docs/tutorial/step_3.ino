#include <Arduino.h>
#include <Joystick.h>

// The number of input buttons the controller has. For PIU pads, this will be 5
#define NUMBER_OF_BUTTONS 5

// Debounce interval, in milliseconds
#define DEBOUNCE_INTERVAL 20

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

bool isButton1Pressed;
bool isButton2Pressed;
bool isButton3Pressed;
bool isButton4Pressed;
bool isButton5Pressed;

unsigned long lastChangeTimeButton1;
unsigned long lastChangeTimeButton2;
unsigned long lastChangeTimeButton3;
unsigned long lastChangeTimeButton4;
unsigned long lastChangeTimeButton5;

void setup() {
  Joystick.begin();

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);

  isButton1Pressed = false;
  isButton2Pressed = false;
  isButton3Pressed = false;
  isButton4Pressed = false;
  isButton5Pressed = false;

  lastChangeTimeButton1 = 0;
  lastChangeTimeButton2 = 0;
  lastChangeTimeButton3 = 0;
  lastChangeTimeButton4 = 0;
  lastChangeTimeButton5 = 0;
}

void loop() {
  readButton1();
  readButton2();
  readButton3();
  readButton4();
  readButton5();
}

void readButton1() {
  bool newState = digitalRead(BUTTON_1_PIN) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChangeTimeButton1);

  bool stateChanged = newState != isButton1Pressed;
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButton1Pressed = newState;
    lastChangeTimeButton1 = millis();

    Joystick.setButton(0, isButton1Pressed);
  }
}

void readButton2() {
  bool newState = digitalRead(BUTTON_2_PIN) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChangeTimeButton2);

  bool stateChanged = newState != isButton2Pressed;
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButton2Pressed = newState;
    lastChangeTimeButton2 = millis();

    Joystick.setButton(1, isButton2Pressed);
  }
}

void readButton3() {
  bool newState = digitalRead(BUTTON_3_PIN) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChangeTimeButton3);

  bool stateChanged = newState != isButton3Pressed;
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButton3Pressed = newState;
    lastChangeTimeButton3 = millis();

    Joystick.setButton(2, isButton3Pressed);
  }
}

void readButton4() {
  bool newState = digitalRead(BUTTON_4_PIN) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChangeTimeButton4);

  bool stateChanged = newState != isButton5Pressed;
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButton4Pressed = newState;
    lastChangeTimeButton4 = millis();

    Joystick.setButton(3, isButton4Pressed);
  }
}

void readButton5() {
  bool newState = digitalRead(BUTTON_5_PIN) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChangeTimeButton5);

  bool stateChanged = newState != isButton5Pressed;
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isButton5Pressed = newState;
    lastChangeTimeButton5 = millis();

    Joystick.setButton(4, isButton5Pressed);
  }
}