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
     
     void ShowColorSequence(CHSV color[], int arraySize, int offset, double duration);
};
