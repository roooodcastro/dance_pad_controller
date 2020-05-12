#ifndef LEDS_CONTROLLER_H
#define LEDS_CONTROLLER_H

#include <Arduino.h>
#include <FastLED.h>

#include "configuration.h"
#include "pad_leds.h"

// Total number of LEDs. Example: 8 LEDs per pad with 5 pads = 40 LEDs total
#define LED_COUNT NUMBER_OF_PADS * LEDS_PER_PAD

// Main LED array. This stores information about the current state of all LEDs.
extern CRGB leds[];
extern PadLeds *padLeds[];

void setupLeds();
void setPadLedsState(int padIndex, bool onOff);

#endif
