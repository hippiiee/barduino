#include <led.h>
#include "motor.h"

void pushBottle(){
    while(stepper2.currentPosition() < 2100){
        Serial.println(stepper2.currentPosition());
        stepper2.setSpeed(600);
        stepper2.runSpeed();
    }
    for(int i = 0; i < 4; i++){
        ledLoading(0,8,40);
        ledLoading(8,24,30);
    }
    while(stepper2.currentPosition() > 0) {
        Serial.println(stepper2.currentPosition());
        stepper2.setSpeed(-600);
        stepper2.runSpeed();
    }
};

void goHome(){
    bool stopHome = false;
    while(stepper1.currentPosition() > -100){
        stepper1.setSpeed(-200);
        stepper1.runSpeed();
    }
    stepper1.setSpeed(400);
    while(!stopHome){ //200 is one motor turn
        if(digitalRead(endSwitch) == HIGH){
            stopHome = true;
        }else{
            stepper1.runSpeed();
        }
    }
    stepper1.setCurrentPosition(0);
    while(stepper1.currentPosition() != -15){
        stepper1.setSpeed(-50);
        stepper1.runSpeed();
    }
//    ledFinished();
}

void goToBottle(int bottleNumber[],int size){
    int position = 0;
    stepper1.setAcceleration(200);
    stepper1.setSpeed(-400);
    for(int i = 0; i < size; i++){
        position = posBottle[bottleNumber[i]-1];
        if(stepper1.currentPosition() != position){ //200 is one motor turn
            if(digitalRead(endSwitch) == HIGH){
                goHome();
            }else{
                stepper1.moveTo(position);
                stepper1.runToPosition();
                delay(500);
                pushBottle();
            }
        }
    }
    goHome();
}