#ifndef LEDS_CONTROLLER_H
#define LEDS_CONTROLLER_H

#include <Arduino.h>

#include "configuration.h"
#include "pad_leds.h"

extern PadLeds *padLeds[];

void setupLeds();
void setPadLedsState(int padIndex, bool onOff);

#endif
