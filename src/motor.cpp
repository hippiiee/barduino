#include "motor.h"

void pushBottle(){
    //clockwise
    digitalWrite(dirPin, HIGH);

    for(int x = 0; x < 2000; x++){ // 200 is one turn
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000); // Wait a second
    digitalWrite(dirPin, LOW);

    // Spin motor
    for(int x = 0; x < 2000; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000); // Wait a second
};

void goToBottle(int bottleNumber){
    //clockwise
    digitalWrite(dirPin, HIGH);

    for(int x = 0; x < 2000; x++){ // 200 is one turn
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000); // Wait a second
    digitalWrite(dirPin, LOW);

    // Spin motor
    for(int x = 0; x < 2000; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(stepDelay);
    }
    delay(1000); // Wait a second

};
