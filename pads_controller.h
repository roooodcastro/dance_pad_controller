#ifndef PADS_CONTROLLER_H
#define PADS_CONTROLLER_H

#include <Arduino.h>
#include <Joystick.h>

#include "configuration.h"
#include "pad.h"

extern Pad *pads[];

void setupPads();
void checkPads();
#endif
