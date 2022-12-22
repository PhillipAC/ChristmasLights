#include <FastLED.h>
#include "LedService.h"

LedService::LedService()
{
   LedCount = NUM_LEDS;
   LEDS.addLeds<WS2812, 7, RGB>(Leds, NUM_LEDS);
   LEDS.setBrightness(84);
};

void LedService::SetLed(int index, CRGB color)
{
  Leds[index] = color;
}

void LedService::Display()
{
  FastLED.show();
}

CRGB LedService::GetLedColor(int index)
{
  return Leds[index];
}
