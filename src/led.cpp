#include "led.h"

CRGB leds[NUM_LEDS];

void ledLoading(int min, int max, int time) {
    static uint8_t hue = 0;
    for(int i = min; i < max; i++) {
        leds[i] = CHSV(hue++,255,255);
        FastLED.show();
        delay(time);
    }
    for(int i = min; i < max; i++){
        delay(time);
        leds[i] = CRGB::Black;
        FastLED.show();
    }
}

void ledStarting(){
    for(int i=0; i < 256; i++) {
        fill_rainbow(leds, NUM_LEDS, i, 7);
        FastLED.show();
    }
}

void ledFinished() {
    for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CHSV(255,255,255);
    }
    FastLED.show();
    for(int k = 255; k > 0; k-=15){
        for(int j = 0; j < NUM_LEDS; j++){
            leds[j].setHSV(255,255,k);
            FastLED.show();
        }
    }
    for(int k = 1; k < 256; k+=15){
        for(int j = 0; j < NUM_LEDS; j++){
            leds[j].setHSV(255,255,k);
            FastLED.show();
        }
    }
}

