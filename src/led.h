#ifndef BARDUINO_LED_H
#define BARDUINO_LED_H

#include <Arduino.h>
#include "../lib/FastLED/FastLED.h"

static const int NUM_LEDS = 24;
static const int DATA_PIN_LED = 7;
static const int LED_BRIGHTNESS = 100;
extern CRGB leds[NUM_LEDS];

void ledLoading(int min, int max, int time);
void ledStarting();
void ledFinished();

#endif //BARDUINO_LED_H
