#include <Arduino.h>

#include "configuration.h"
#include "pads_controller.h"

#ifdef PADS_HAVE_LED
#include "leds_controller.h"
#endif

void setup() {
  setupPads();

#ifdef PADS_HAVE_LED
  setupLeds();
  delay(INIT_INSPECT_DELAY);
#endif
}

// This is checking the pads 10 times a second just as a back up in case a pad
// or LED gets "stuck" in a wrong state. If all goes well this is redundant.
void loop() {
  checkPads();

#ifdef PADS_HAVE_LED
  // If the LED controller is enabled, set then according to the pads state.
  for (int padIndex = 0; padIndex < NUMBER_OF_PADS; padIndex++) {
    padLeds[padIndex]->setState(leds, pads[padIndex]->isPressed());
  }

  // Write to strip, updating the LEDs.
  FastLED.show();
#endif

  delay(1);
}
