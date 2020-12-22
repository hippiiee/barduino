#ifndef BARDUINO_MOTOR_H
#define BARDUINO_MOTOR_H

#include <Arduino.h>

    static const int dirPin = 2;
    static const int stepPin = 3;
    static const int stepDelay = 500;

    void pushBottle();
    void goToBottle(int bottleNumber);


#endif //BARDUINO_MOTOR_H
