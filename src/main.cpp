#include "led.h"
#include "motor.h"
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
    Serial.begin(9600);
//    LEDS.addLeds<WS2812,DATA_PIN_LED,RGB>(leds,NUM_LEDS);
//    LEDS.setBrightness(LED_BRIGHTNESS);
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(endSwitch, INPUT);
    stepper.setMaxSpeed(1000);
    goHome();
    int drink[] = {3,4,6,1};
    goToBottle(drink,4);
}
// bouteille 1 = -500
// boutei@lle 2 = -1035
// bouteille 2 = -1525
// bouteille 2 = -2030
// bouteille 2 = -2535
// bouteille 2 = -3040
void loop() {
    //    ledLoading(0,8,50);
//    ledLoading(8,24,30);
//    ledFinished();
//    ledStarting();
//    pushBottle();
//    goToBottle(1);
}

