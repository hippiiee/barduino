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

void goHome(){
    bool stopHome = false;
    while(stepper.currentPosition() > -100){
        stepper.setSpeed(-200);
        stepper.runSpeed();
    }
    stepper.setSpeed(400);
    while(!stopHome){ //200 is one motor turn
        if(digitalRead(endSwitch) == HIGH){
            stopHome = true;
        }else{
            stepper.runSpeed();
        }
    }
    stepper.setCurrentPosition(0);
    while(stepper.currentPosition() != -15){
        stepper.setSpeed(-50);
        stepper.runSpeed();
    }
}

void goToBottle(int bottleNumber[],int size){
    int position = 0;
    stepper.setAcceleration(200);
    stepper.setSpeed(-400);
    Serial.println(sizeof(bottleNumber));
    for(int i = 0; i < size; i++){
        Serial.println(i);
        position = posBottle[bottleNumber[i]-1];
        if(stepper.currentPosition() != position){ //200 is one motor turn
            if(digitalRead(endSwitch) == HIGH){
                goHome();
            }else{
                stepper.moveTo(position);
                stepper.runToPosition();
                delay(1000);
            }
        }
    }
    goHome();
}
