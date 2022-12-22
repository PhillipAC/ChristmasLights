// Led.h

#include <FastLED.h>

#define NUM_LEDS 150

class LedService
{
 protected:
     CRGB Leds[NUM_LEDS];
     int LedCount;

 public:
     LedService();
     void SetLed(int index, CRGB color);
     void Display();
     CRGB GetLedColor(int index);
};
