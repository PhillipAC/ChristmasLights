// Led.h

#include <FastLED.h>

#define NUM_LEDS 50

class LedService
{
 protected:
     CRGB Leds[NUM_LEDS];

 public:
     LedService();
     void SetLed(int index, CRGB color);
     void Display();
     CRGB GetLedColor(int index);
};
