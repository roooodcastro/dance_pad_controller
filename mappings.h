#ifndef MAPPINGS_H
#define MAPPINGS_H

#include <FastLED.h>

// Pump it Up pad layout:
//
// ╔═══════════════╗
// ║┌───┐     ┌───┐║
// ║│ 2 │     │ 3 │║
// ║└───┘┌───┐└───┘║
// ║     │ 4 │     ║
// ║┌───┐└───┘┌───┐║
// ║│ 5 │     │ 6 │║
// ║└───┘     └───┘║
// ╚═══════════════╝
const int PIU_SENSOR_PINS[] = {
  2, // Top Left
  3, // Top Right
  4, // Center
  5, // Bottom Left
  6  // Bottom Right
};

// Dance Dance Revolution pad layout:
//
// ╔═══════════════╗
// ║     ┌───┐     ║
// ║     │ 2 │     ║
// ║┌───┐└───┘┌───┐║
// ║│ 3 │     │ 4 │║
// ║└───┘┌───┐└───┘║
// ║     │ 5 │     ║
// ║     └───┘     ║
// ╚═══════════════╝
const int DDR_SENSOR_PINS[] = {
  2, // Top
  3, // Left
  4, // Right
  5  // Bottom
};

// Custom colours to match pad art.
// The three colours were chosen in such a way so each LED will draw roughly the
// same amount of current. If each colour value was divided by 64, these would
// be the rough "load amount" for each colour:
//
// Red:    1 + 4 + 1 = 6 "units of load"
// Blue:   1 + 1 + 4 = 6
// Yellow: 3 + 3 + 0 = 6
#define RED    CRGB(64, 255, 64)
#define BLUE   CRGB(64, 64, 255)
#define YELLOW CRGB(192, 192, 0)
#define PINK   CRGB(0, 255, 128)
#define CYAN   CRGB(128, 0, 255)

// Mappings for the PIU pads
const CRGB PIU_PAD_COLORS[] = {
  RED,    // Top left
  RED,    // Top right
  YELLOW, // Center
  BLUE,   // Bottom left
  BLUE    // Bottom right
};

// Mappings for the DDR pads
const CRGB DDR_PAD_COLORS[] = {
  PINK, // Top
  CYAN, // Left
  CYAN, // Right
  PINK  // Bottom
};

#endif