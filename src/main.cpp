#include "led.h"
#include "motor.h"
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
    Serial.begin(9600);
    LEDS.addLeds<WS2812,DATA_PIN_LED,RGB>(leds,NUM_LEDS);
    LEDS.setBrightness(LED_BRIGHTNESS);
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);
    pinMode(endSwitch, INPUT);
    stepper1.setMaxSpeed(1000);
    stepper2.setMaxSpeed(1000);
}
void loop() {
    delay(2000);
    int drink[] = {3,2,5,4}; // the position of the bottle you want to use in your cocktail
    goHome(); // go to the home position
    ledStarting(); // start the led animation
    goToBottle(drink,4); // go to the bottle position and push the bottle, the number of bottle is 4
    ledFinished(); // finish the led animation
    delay(4000);
}
