#include <FastLED.h>
#include "LedService.h"

LedService::LedService()
{
   LedCount = NUM_LEDS;
   LEDS.addLeds<WS2812, 7, RGB>(Leds, NUM_LEDS);
   LEDS.setBrightness(84);
};

void LedService::SetLed(int index, CHSV color)
{
  Leds[index] = color;
}

void LedService::Display()
{
  FastLED.show();
}

CHSV LedService::GetLedColor(int index)
{
  return rgb2hsv_approximate(Leds[index]);
}
