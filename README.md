# Dance Pad Controller

This is an Arduino based controller for home brew and DIY dance pads,
like DDR or PIU pads.

This code is used on my DIY hard PIU dance pad. For more information, please
check the following links:

* [PIU Dance Pad (part 5) - Arduino Programming](https://www.blowingstuff.com/blog/2020/08/24/piu-arduino-programming.html)
* [Pump it Up Dance Pad Overview](https://www.blowingstuff.com/projects/2020/06/06/piu-dance-pad.html)

## Features:

* Emulates a USB Game controller, by becoming a HID device (requires an Arduino
that supports HID natively)
* Supports PIU, DDR, and any other type of panel-based dance pad, as it can
control any number of arrows, from 1 to as many input pins the Arduino board has
* Supports **LED strips** to light up the arrows when a player steps on them
(requires the [FastLED library](https://github.com/FastLED/FastLED))
* Implements debouncing to mitigate double-stepping issues

## Setup

### Sensors

Each individual arrow on the dance pad should have one or more step sensors.
These sensors are typically made of two conductive plates separated by an air
gap. When the player steps on the pad, the gap closes and an electrical
connection is made. This is the equivalent to a simple momentary switch.

Multiple sensors on the same pad must be wired in parallel, as this controller
does not support detecting individual sensors on a single pad. Here's a rough
wiring schematic showing the connection of a Pump it Up pad to the Arduino
board:

<p align="center">
  <img src="./docs/piu_wiring.png" alt="Pump it Up Arduino wiring" width="458">
</p>

For a guide on how to build 3D-printed sensors, check out this post:
[PIU Dance Pad (part 3) - Pad Sensors](https://www.blowingstuff.com/blog/2020/06/13/piu-pad-sensors.html)

### LEDs

This controller can add LED support to the pad. It supports a variety of
addressable LED strips through the [FastLED](https://github.com/FastLED/FastLED)
library (**required**).

LEDs should be installed as described on
[PIU Dance Pad (part 4) - LEDs and Electronics](https://www.blowingstuff.com/blog/2020/08/21/piu-leds-and-electronics.html).

LED support features:

* Initialization sequence after pad power up, to indicate that the pad is ready
and all LEDs working
* Full RGB/HSV support through FastLED, with each arrow capable of having
different colours
* Easily configurable number of LEDs per arrow, strip chipset, and colour order

LED support limitations:

* Single, continuous strip for all arrows is not supported yet
* Only works with addressable LED strips
* Number of LEDs per arrow must be the same across all arrows

## Configuration

The file `configuration.h` contains all supported configuration values for the
controller (unless you fork this project and roll your own :) ). These are the
existing options:

### Arrows (sensors) configuration

* **DEBOUNCE_INTERVAL**: Debounce interval in milliseconds. This is to prevent
bouncing, which happens when the electrical contact is briefly lost on the
sensor due to physical bouncing. If absent, a single arrow step would usually
result in extra step inputs being sent to the controller, causing gameplay
issues.
*Defaults to `50`*
* **NUMBER_OF_ARROWS**: Number of arrows present in the dance pad.
This would be 4 for DDR, and 5 for PIU. *Defaults to `5`*
* **SENSOR_PINS**: Arduino pins where each arrow is connected to. Sensors will
be treated as momentary switches, and will be set in Arduino as `INPUT_PULLUP`.
*Defaults to using the pins 2, 4, 6, 8, and 10*

### LEDs configuration

* **ARROWS_HAVE_LEDS**: Flag that sets whether the dance pad has LEDs that light
up when the player steps on them. Comment to disable. *Defaults to `enabled`*

* **LED_CHIPSET**: The LED strip's chipset.
Refer to https://github.com/FastLED/FastLED#supported-led-chipsets
for a list of supported chipsets. *Defaults to `WS2812B`*

* **LED_RGB_ORDER**: The colour order of the LED chipset. Some strips may
interpret colours in different orders, such as RGB, GRB, BGR, etc.
*Defaults to `GRB`*

* **LED_PINS**: Arduino pins where the Data input (`Din`) pin of each arrow's
LEDs are connected to. Each arrow has its own respective LED `Din` pin.
*Defaults to `PIU_LED_PINS`*

* **LEDS_PER_ARROW**: How many LEDs are there per arrow. The total current draw
and power requirements of the pad should be taken into account when choosing
the amount of LEDs.
*Defaults to `8`*

* **INIT_INSPECT_DELAY**: Duration in milliseconds for which the LEDs stay on
when the pad is initialized. This can be used to make sure the LEDs are working,
and also as an indicator that the pad is now online and ready for use. Can be
disabled by setting it to zero.
*Defaults to `1000`*

* **ARROW_COLORS**: Maps colours to the arrows' LEDs. The file `mappings.h`
defines some standard mappings for PIU and DDR. *Defaults to `PIU_ARROW_COLORS`*

## License

[MIT](./LICENSE)