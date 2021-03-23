#ifndef BARDUINO_MOTOR_H
#define BARDUINO_MOTOR_H

#include <Arduino.h>
#include "../lib/AccelStepper/src/AccelStepper.h"

#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

static const int endSwitch = 4;
static const int stepDelay = 1000;
static const int posBottle[6] = {-500,-1035,-1525,-2030,-2535,-3040};
extern AccelStepper stepper;

void pushBottle();
void goToBottle(int bottleNumber[], int size);
void goHome();


#endif //BARDUINO_MOTOR_H
