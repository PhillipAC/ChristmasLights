#include <FastLED.h>
#include "LedService.h"

LedService::LedService()
{
   LedCount = NUM_LEDS;
   LEDS.addLeds<WS2812, 7, GRB>(Leds, NUM_LEDS);
   LEDS.setBrightness(84);
};

void LedService::ShowColorSequence(CHSV colors[], int arraySize, int offset, double duration) 
{
   for (int i = 0; i < NUM_LEDS; i++) {
       int index = (i+offset)%arraySize;
       Leds[i] = colors[index];
   }
   FastLED.show();
   delay(round(duration * 1000));
}
