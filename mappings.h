
#ifndef MAPPINGS_H
#define MAPPINGS_H

#include "configuration.h"

struct CRGB;

#ifdef ARROWS_HAVE_LEDS
#include <FastLED.h>
#endif

/*
  ==============================================================================
  LED-related mappings (ignore if your pad does not have LEDs)
  ==============================================================================
*/

// Custom colours to match arrow art.
// The three colours were chosen in such a way so each LED will draw roughly the
// same amount of current. If each colour value was divided by 64, these would
// be the rough "load amount" for each colour:
//
// Red:    4 + 2 + 2 = 8 "units of load", out of a possible 12 (66% power)
// Blue:   2 + 2 + 4 = 8
// Yellow: 4 + 4 + 0 = 8
#define RED    CRGB(255, 128, 128)
#define BLUE   CRGB(128, 128, 255)
#define YELLOW CRGB(255, 255, 0)
#define PINK   CRGB(255, 0, 128)
#define CYAN   CRGB(0, 128, 255)

// Mappings for PIU LED pins
constexpr int PIU_LED_PINS[] = {
  3, // Top Left
  5, // Top Right
  7, // Center
  9, // Bottom Left
  11 // Bottom Right
};

#ifdef ARROWS_HAVE_LEDS

// Mappings for a PIU pad
const CRGB PIU_ARROW_COLORS[] = {
  RED,    // Top left
  RED,    // Top right
  YELLOW, // Center
  BLUE,   // Bottom left
  BLUE    // Bottom right
};

// Mappings for DDR LED pins
const int DDR_LED_PINS[] = {
  3, // Top
  5, // Left
  7, // Right
  9  // Bottom
};

// Mappings for a DDR pad
const CRGB DDR_ARROW_COLORS[] = {
  PINK, // Top
  CYAN, // Left
  CYAN, // Right
  PINK  // Bottom
};
#endif
#endif
