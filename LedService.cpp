#include <FastLED.h>
#include "LedService.h"

LedService::LedService()
{
   LedCount = NUM_LEDS;
   LEDS.addLeds<WS2812, 7, GRB>(Leds, NUM_LEDS);
   LEDS.setBrightness(84);
};

void LedService::ShowColorSequence(CHSV colors[], int arraySize, int offset, int skip, double duration) 
{
   int j = 0;
   for (int i = 0; i < NUM_LEDS; i+= skip) {
       j++;
       int index = (j+offset)%arraySize;
       Leds[i] = colors[index];
   }
   FastLED.show();
   delay(round(duration * 1000));
}
