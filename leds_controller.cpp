#include "leds_controller.h"

// Main LED array. This stores information about all LEDs.
CRGB leds[LEDS_PER_PAD * NUMBER_OF_PADS];

// PadLeds array. Each member controls the LEDs of a single pad.
PadLeds *padLeds[NUMBER_OF_PADS];

// Initialize the FastLED library and turn on LEDs on all pads.
void setupLeds() {
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds<LED_CHIPSET, LED_PIN, LED_RGB_ORDER>(leds, LED_COUNT);

  for (int padIndex = 0; padIndex < NUMBER_OF_PADS; padIndex++) {
    padLeds[padIndex] = new PadLeds(
      padIndex,
      LEDS_PER_PAD,
      PAD_COLORS[padIndex]
    );
    setPadLedsState(padIndex, true);
  }

  FastLED.show();
}

void setPadLedsState(int padIndex, bool onOff) {
  padLeds[padIndex]->setState(leds, onOff);
}
