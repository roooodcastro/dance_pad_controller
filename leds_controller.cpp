#include "configuration.h"
#include "leds_controller.h"

#ifdef ARROWS_HAVE_LEDS
// PadLeds array. Each member controls the LEDs of a single pad.
PadLeds *padLeds[NUMBER_OF_ARROWS];

// Initialize the FastLED library and turn on LEDs on all pads.
void setupLeds() {
  for (int padIndex = 0; padIndex < NUMBER_OF_ARROWS; padIndex++) {
    padLeds[padIndex] = new PadLeds(
      padIndex,
      LEDS_PER_ARROW,
      ARROW_COLORS[padIndex]
    );

    pinMode(LED_PINS[padIndex], OUTPUT);

    setPadLedsState(padIndex, true);
  }

// Supports pads of up to 9 arrows (a full 3x3 grid)
#if NUMBER_OF_ARROWS > 0
  FastLED.addLeds<LED_CHIPSET, LED_PINS[0], LED_RGB_ORDER>(padLeds[0]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 1
  FastLED.addLeds<LED_CHIPSET, LED_PINS[1], LED_RGB_ORDER>(padLeds[1]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 2
  FastLED.addLeds<LED_CHIPSET, LED_PINS[2], LED_RGB_ORDER>(padLeds[2]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 3
  FastLED.addLeds<LED_CHIPSET, LED_PINS[3], LED_RGB_ORDER>(padLeds[3]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 4
  FastLED.addLeds<LED_CHIPSET, LED_PINS[4], LED_RGB_ORDER>(padLeds[4]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 5
  FastLED.addLeds<LED_CHIPSET, LED_PINS[5], LED_RGB_ORDER>(padLeds[5]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 6
  FastLED.addLeds<LED_CHIPSET, LED_PINS[6], LED_RGB_ORDER>(padLeds[6]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 7
  FastLED.addLeds<LED_CHIPSET, LED_PINS[7], LED_RGB_ORDER>(padLeds[7]->getLeds(), LEDS_PER_ARROW);
#endif
#if NUMBER_OF_ARROWS > 8
  FastLED.addLeds<LED_CHIPSET, LED_PINS[8], LED_RGB_ORDER>(padLeds[8]->getLeds(), LEDS_PER_ARROW);
#endif

  for (int padIndex = 0; padIndex < NUMBER_OF_ARROWS; padIndex++) {
    setPadLedsState(padIndex, true);
  }

  FastLED.show();
}

void setPadLedsState(int padIndex, bool onOff) {
  padLeds[padIndex]->setState(onOff);
}
#endif