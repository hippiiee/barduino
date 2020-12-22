#include "led.h"
#include "motor.h"

void setup() {
    Serial.begin(57600);
//    LEDS.addLeds<WS2812,DATA_PIN_LED,RGB>(leds,NUM_LEDS);
//    LEDS.setBrightness(LED_BRIGHTNESS);
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop() {
//    ledLoading(0,8,50);
//    ledLoading(8,24,30);
//    ledFinished();
//    ledStarting();
    pushBottle();
}

