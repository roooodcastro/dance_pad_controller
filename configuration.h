#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// This configuration file is split in two sections: Arrows and LEDs
// configurations. If your pad does NOT have LEDs, you can either delete or
// comment out the line "#define ARROWS_HAVE_LEDS" at the start of the LED section
// and ignore the rest of the file.

/*
  ==============================================================================
  Arrows configuration
  ==============================================================================
*/

// Debounce interval in milliseconds. This is to prevent bouncing, when the
// electrical contact is briefly lost on the pad due to physical bouncing. If
// absent, a single pad step would usually result in extra step inputs being
// sent to the controller, causing gameplay issues.
//
// An interval of 50ms allows up to 25 steps per second, which should be fine
// for all songs.
#define DEBOUNCE_INTERVAL 50

// Number of arrow panels present in the dance mat.
// This would be 4 for DDR, and 5 for PIU.
#define NUMBER_OF_ARROWS 5

// Arduino pins where each pad is connected to. Arrow sensors will be treated as
// momentary switches, and will be configured in Arduino as INPUT_PULLUP.
//
// Add or remove lines below according to the number of arrows present.
// Example Pump it Up pad layout:
//
// ╔═══════════════╗
// ║┌───┐     ┌───┐║
// ║│ 2 │     │ 4 │║
// ║└───┘┌───┐└───┘║
// ║     │ 6 │     ║
// ║┌───┐└───┘┌───┐║
// ║│ 8 │     │10 │║
// ║└───┘     └───┘║
// ╚═══════════════╝
const int SENSOR_PINS[] = {
  2, // Top Left
  4, // Top Right
  6, // Center
  8, // Bottom Left
  10 // Bottom Right
};

/*
  ==============================================================================
  LEDs configuration
  ==============================================================================

  The dance pad can be configured to use LEDs to light up individual arrows.

  This can be turned off by commenting ARROWS_HAVE_LEDS, if the dance pad does
  not have such a feature.

  If enabled, the FastLED library must be installed:
  - https://github.com/FastLED/FastLED

  The physical installation of the LEDs MUST be such that a continuous strip is
  formed from the first arrow to the last, in the correct order. This means each
  sub-strip's Din and D0 must form a chain in order for ALL LEDs to be
  recognized as a single FastLED strip.
*/

// Whether the dance mat has LEDs that light up when the player steps on them.
// Note that the number of LEDs per arrow must be the same for all arrows.
#define ARROWS_HAVE_LEDS

#ifdef ARROWS_HAVE_LEDS // This shouldn't be changed

// The LED chipset.
// Refer to https://github.com/FastLED/FastLED#supported-led-chipsets
// for a list of supported chipsets.
#define LED_CHIPSET WS2812B

// The order of the RGB pins on the chipset. Reorder as necessary.
#define LED_RGB_ORDER GRB

// Map colours to arrows. Check "mappings.h" file for available mappings, or
// create your own by uncommenting the code below.
//
//const CRGB CUSTOM_ARROW_COLORS[] = {
//  CRGB::White, // Arrow 1
//  CRGB::White, // Arrow 2
//  CRGB::White, // Arrow 3
//  CRGB::White  // Arrow 4
//};
//#define ARROW_COLORS CUSTOM_ARROW_COLORS;
//
#define ARROW_COLORS PIU_ARROW_COLORS

#endif // This shouldn't be changed

// Arduino pins where the Data pin of each arrow's LEDs are connected to.
#define LED_PINS PIU_LED_PINS

// How many LEDs are there per arrow. The total current draw of the mat must be
// taken into account when choosing the numbe of LEDs.
//
// For example, if only USB power is going to be used, each arrow can only have
// a very limited number of LEDs, as typical current limit on USB 2 is 500mA, or
// 900mA for USB 3.
//
// For instance, for a PIU pad using WS2812 LEDs and the colours suggested
// below, each LED will draw a maximum of roughly 45mA, so using for instance,
// 4 leds at full brightness per arrow will result in a max current draw of
// 900mA, when all 5 arrows are pressed at the same time
// (45mA * 4 leds * 5 arrows). If more LEDs are required, an external power
// source is needed. The LEDs can also be operated at a lower brightness to
// limit the amount of current draw.
#define LEDS_PER_ARROW 8

// Duration in milliseconds for which the LEDs flash on when the pad is
// initialized. This can be used to make sure the LEDs are working, and also as
// an indicator that the pad is now online and ready for use.
#define INIT_INSPECT_DELAY 1000

/*
  ==============================================================================
  End of configurable settings. The rest of the file shouldn't be changed
  ==============================================================================
*/

#include "mappings.h"

#endif
