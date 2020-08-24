#include "configuration.h"

#include <Arduino.h>
#include "pads_controller.h"
#include "leds_controller.h"

void setup() {
  delay(500);

  setupPads();

#ifdef ARROWS_HAVE_LEDS
  setupLeds();
  delay(INIT_INSPECT_DELAY);
#endif
}

// This is checking the pads 10 times a second just as a back up in case a pad
// or LED gets "stuck" in a wrong state. If all goes well this is redundant.
void loop() {
  checkPads();

#ifdef ARROWS_HAVE_LEDS
  // If the LED controller is enabled, set then according to the pads state.
  for (int padIndex = 0; padIndex < NUMBER_OF_ARROWS; padIndex++) {
    padLeds[padIndex]->setState(pads[padIndex]->isPressed());
  }

  // Write to strip, updating the LEDs.
  FastLED.show();
#endif
}
