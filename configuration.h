#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "mappings.h"

/*
  ==============================================================================
  Pads configuration
  ==============================================================================
*/

// Debounce interval in milliseconds. This is to prevent bouncing, when the
// electrical contact is briefly lost on the pad due to physical bouncing. If
// absent, a single pad step would usually result in extra step inputs being
// sent to the controller, causing gameplay issues.
//
// An interval of 20ms allows up to 50 steps per second, which is more than
// enough for human gameplay.
#define DEBOUNCE_INTERVAL 20

// Number of pads present in the dance mat.
// This would be 4 for DDR, and 5 for PIU.
#define NUMBER_OF_PADS 5

// Arduino pins where each pad is connected to. Pads will be treated as
// momentary switches, and will be set in Arduino as INPUT_PULLUP.
//
// Add or remove lines according to the number of pads present.
// Check "mappings.h" file for available mappings, or create your own by
// uncommenting the code below.
//
//const int CUSTOM_SENSOR_PINS[] = {
//  9,  // Pad 1
//  10, // Pad 2
//  11, // Pad 3
//  12  // Pad 4
//};
//#define SENSOR_PINS CUSTOM_SENSOR_PINS
//
#define SENSOR_PINS PIU_SENSOR_PINS

/*
  ==============================================================================
  LEDs configuration
  ==============================================================================

  The dance pad can be configured to use LEDs to light up individual pads.

  This can be turned off by commenting PADS_HAVE_LEDS, if the dance pad does
  not have such a feature.

  If enabled, the FastLED library must be installed:
  - https://github.com/FastLED/FastLED

  The physical installation of the LEDs MUST be such that a continuous strip is
  formed from the first pad to the last, in the correct order. This means each
  sub-strip's Din and D0 must form a chain in order for ALL LEDs to be
  recognized as a single FastLED strip.
*/

// Whether the dance mat has LEDs that light up when the player steps on them.
// This only works if all pads have LEDs, and also same number of them per pad.
#define PADS_HAVE_LEDS

#ifdef PADS_HAVE_LEDS

// The LED chipset.
// Refer to https://github.com/FastLED/FastLED#supported-led-chipsets
// for a list of supported chipsets.
#define LED_CHIPSET WS2812B

// The order of the RGB pins on the chipset. Reorder as necessary.
#define LED_RGB_ORDER RGB

// Arduino Pin where the Data pin of the LED is connected to.
// This pin should be connected to the Din input on the first LED of the first
// pad. From there, the D0 (output) wire should connect to the Din wire on the
// first LED of the second pad, and so on.
#define LED_PIN 8

// How many LEDs are there per pad. The total current draw of the mat must be
// taken into account when choosing the numbe of LEDs.
//
// For example, if only USB power is going to be used, each pad can only have a
// very limited number of LEDs, as typical current limit on USB 2 is 500mA, or
// 900mA for USB 3.
//
// For instance, for a PIU pad using WS2812 LEDs and the colours suggested
// below, each LED will draw roughly 20mA, so using for instance, 8 leds per pad
// will result in a max current draw of 800mA, when all 5 pads are pressed at
// the same time (20mA * 8 leds * 5 pads). If more LEDs are required, an
// external power source is needed.
#define LEDS_PER_PAD 8

// Duration in milliseconds for which the LEDs flash on when the pad is
// initialized. This can be used to make sure the LEDs are working, and also as
// an indicator that the pad is now online and ready for use.
#define INIT_INSPECT_DELAY 1000

// Map colours to pads. Check "mappings.h" file for available mappings, or
// create your own by uncommenting the code below.
//
//const CRGB CUSTOM_PAD_COLORS[] = {
//  CRGB::White, // Pad 1
//  CRGB::White, // Pad 2
//  CRGB::White, // Pad 3
//  CRGB::White  // Pad 4
//};
//#define PAD_COLORS CUSTOM_PAD_COLORS;
//
#define PAD_COLORS PIU_PAD_COLORS

#endif
#endif
