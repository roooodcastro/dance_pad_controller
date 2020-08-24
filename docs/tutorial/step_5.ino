#include <Arduino.h>
#include <Joystick.h>
#include <FastLED.h>

// The number of arrows the controller has. For PIU pads, this will be 5
#define NUMBER_OF_ARROWS 5

// Debounce interval, in milliseconds
#define DEBOUNCE_INTERVAL 20

// The number of LEDs per arrow
#define LEDS_PER_ARROW 8

// Initializes the Joystick library. It creates only the exact number of buttons
// needed to map all pads. This initializer defines all types of input methods
// a controller might have, such as accelerator, brake, rudder, or analog axis.
// Because our controller only uses momentary button switches, everything else
// must be set to false, because their default value is true.
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, // Device ID and type
  NUMBER_OF_ARROWS, 0,   // Button Count, Hat Switch Count
  false, false, false,   // No X, Y, or Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

// Pin configuration
int arrowPins[NUMBER_OF_ARROWS];

// Pins for the LEDs. This needs to be a constant to work with FastLED library
constexpr int LED_PINS[] = {
  3, // Top Left
  5, // Top Right
  7, // Center
  9, // Bottom Left
  11 // Bottom Right
};

// Debouncing configuration
bool isArrowPressed[NUMBER_OF_ARROWS];
unsigned long lastChanges[NUMBER_OF_ARROWS];

// This needs to be a 2D array, as each of the 5 arrows have 8 LEDs
CRGB leds[NUMBER_OF_ARROWS][LEDS_PER_ARROW];

// Colors to set each arrow when pressed
CRGB colors[NUMBER_OF_ARROWS];

void setup() {
  Joystick.begin();

  // We still have to configure the pins one by one
  arrowPins[0] = 2;
  arrowPins[1] = 4;
  arrowPins[2] = 6;
  arrowPins[3] = 8;
  arrowPins[4] = 10;

  // We have to define the colours for the arrows
  colors[0] = CRGB(255, 128, 128); // Red(-ish)
  colors[1] = CRGB(255, 128, 128); // Red(-ish)
  colors[2] = CRGB(255, 255, 0);   // Yellow(-ish)
  colors[3] = CRGB(128, 128, 255); // Blue(-ish)
  colors[4] = CRGB(128, 128, 255); // Blue(-ish)

  // Also initialize the library (this cannot be done in the for loop below)
  FastLED.addLeds<WS2812B, LED_PINS[0], GRB>(leds[0], LEDS_PER_ARROW);
  FastLED.addLeds<WS2812B, LED_PINS[1], GRB>(leds[1], LEDS_PER_ARROW);
  FastLED.addLeds<WS2812B, LED_PINS[2], GRB>(leds[2], LEDS_PER_ARROW);
  FastLED.addLeds<WS2812B, LED_PINS[3], GRB>(leds[3], LEDS_PER_ARROW);
  FastLED.addLeds<WS2812B, LED_PINS[4], GRB>(leds[4], LEDS_PER_ARROW);

  // Iterate over all buttons to set them up
  for (int i = 0; i < NUMBER_OF_ARROWS; i++) {
    pinMode(arrowPins[i], INPUT_PULLUP);
    pinMode(LED_PINS[i], OUTPUT);

    isArrowPressed[i] = false;
    lastChanges[i] = 0;
  }
}

void loop() {
  // Iterate over all buttons to read them
  for (int i = 0; i < NUMBER_OF_ARROWS; i++) {
    readButton(i);
  }
}

void readButton(int index) {
  bool newState = digitalRead(arrowPins[index]) == LOW;
  unsigned long timeSinceLastDebounce = abs(millis() - lastChanges[index]);

  bool stateChanged = newState != isArrowPressed[index];
  bool inputDebounced = timeSinceLastDebounce >= DEBOUNCE_INTERVAL;

  if (stateChanged && inputDebounced) {
    isArrowPressed[index] = newState;
    lastChanges[index] = millis();

    Joystick.setButton(index, isArrowPressed[index]);

    // If arrow is pressed, set the configured colour, otherwise set black
    CRGB newColor = isArrowPressed[index] ? colors[index] : CRGB::Black;
    setStripColor(index, newColor);
  }
}

// New function to change the colour of an arrow
void setStripColor(int arrowIndex, CRGB color) {
  for (int ledIndex = 0; ledIndex < LEDS_PER_ARROW; ledIndex++) {
    leds[arrowIndex][ledIndex] = color;
  }

  FastLED.show();
}