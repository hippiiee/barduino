#ifndef BARDUINO_MOTOR_H
#define BARDUINO_MOTOR_H

#include <Arduino.h>
#include "../lib/AccelStepper/src/AccelStepper.h"

#define dirPin1 2
#define stepPin1 3
#define dirPin2 4
#define stepPin2 5
#define motorInterfaceType 1

static const int endSwitch = 8; // the pin of your end switch
static const int posBottle[6] = {-520,-1055,-1535,-2050,-2555,-3040}; // the position of your bottle based on the number of steps needed by your stepper motor 
extern AccelStepper stepper1;
extern AccelStepper stepper2;

void pushBottle();
void goToBottle(int bottleNumber[], int size);
void goHome();


#endif //BARDUINO_MOTOR_H
