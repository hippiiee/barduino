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
    stepper2.setMaxSpeed(1000);/**
    stepper1.setEnablePin(stepPin1);
    stepper2.setEnablePin(stepPin2);
    stepper1.disableOutputs();
    stepper2.disableOutputs();**/
//    goHome();
}
void loop() {
    delay(2000);
    int drink[] = {3,2,5,4};
//   pushBottle();
//      ledLoading(0,8,40);
//      ledLoading(8,24,30);
  //    ledFinished();
  //    ledStarting();
    //  pushBottle();
    goHome();
    ledStarting();
    goToBottle(drink,4);
    ledFinished();
    delay(4000);
}

