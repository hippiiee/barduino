# Barduino
<p align="center">
  An automated cocktail machine based on arduino.
  <br>
  <a href="https://twitter.com/intent/follow?screen_name=hiippiiie" title="Follow"><img src="https://img.shields.io/twitter/follow/hiippiiie?label=hiippiiie&style=social"></a>
  <br>
</p>

![barduino-animation](images/demo.gif)


The objective of the project was to build a home-made automatic bar, the idea is not revolutionary and was also to improve myself in 3D modeling.

I created an article on my blog that I recommend you to follow to be able to recreate this project or have a better understanding of it.

## How to use this project ?
To be able to use the project you will need: 
- Install [platformio](https://platformio.org/) on your IDE with an arduino UNO (I recommend using CLion or VSCode)
- or copy the source files to the Arduino IDE

### Dependencies
To run the project you will need these two libraries :
- [AccelStepper](http://www.airspayce.com/mikem/arduino/AccelStepper/)
- [FastLED](https://fastled.io/)

### Hardware
Here is the list of components used to build this project:
- Nema 17 stepper motor
- Arduino UNO
- 12V power supply
- Dupont cables
- 6 bottle rack
- Belt and pulleys
- Linear guide 1000mm + carriages
- Stepper motor driver
- 3D printing pieces
- Individually programmable LED rings

### Code edit

You will need to edit a few values in the project to be able to run it with your hardware :

**include/led.h**
```c++
static const int NUM_LEDS = 24; // your number of leds on the ring
static const int DATA_PIN_LED = 7; // your data pin
static const int LED_BRIGHTNESS = 100; // the brightness of the leds
```

**include/motor.h**
```c++
static const int endSwitch = 8; // the pin of your end switch
static const int posBottle[6] = {-520,-1055,-1535,-2050,-2555,-3040}; // the position of your bottle based on the number of steps needed by your stepper motor 
```
You will also need to edit all the pin in these two files based on your connections to your arduino.

**src/main.cpp**
```c++
int drink[] = {3,2,5,4}; // the position of the bottle you want to use in your cocktail
goHome(); // go to the home position
ledStarting(); // start the led animation
goToBottle(drink,4); // go to the bottle position and push the bottle, the number of bottle is 4
ledFinished(); // finish the led animation
```

The code is not the cleaner code you can find but it's modular and working. I will continue to work on this project when I'll have more free time to upgrade it and have a more stable/usable version of it.
