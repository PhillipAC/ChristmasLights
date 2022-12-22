#include <FastLED.h>
#include <Arduino.h>

#include "Led.h"
#include "LedService.h"

#define NUM_FLASHING 10

CHSV Colors[] = {
  CHSV(00, 255, 255), //Red
  CHSV(46, 255, 255), //Yellow
  CHSV(170, 255, 255), //Blue
  CHSV(21, 255, 255), //Orange
  CHSV(85, 255, 255), //Green
  CHSV(213, 255, 255)}; //Purple

LedService ledService;

bool Results[NUM_FLASHING];
short Indexes[NUM_FLASHING];
float Increments[NUM_FLASHING];
Led Leds[NUM_FLASHING];

void setup() {
  for(short i = 0; i < NUM_LEDS; i++)
  {
    ledService.SetLed(i, Colors[i % 6]);
  }
  for(short i = 0; i < NUM_FLASHING; i++)
  {
    Results[i] = false;
    Increments[i] = 1.0;
  }
}

void loop() {
  for(short i = 0; i < NUM_FLASHING; i++)
  {
    if(Results[i])
    {
      Increments[i] = random(50,150)/100.0;
      bool newValue;
      short index;
      do
      {
        newValue = true;
        index = random(0, NUM_LEDS);
        for(short j = 0; j < NUM_FLASHING; j++)
        {
          if(index == Indexes[j])
          {
            newValue = false;
          }
        }
      }while(!newValue);
      Indexes[i] = index;
      Leds[i].SetColor(ledService.GetLedColor(Indexes[i]));
    }
    Results[i] = Leds[i].ShiftColor(Increments[i]);
    ledService.SetLed(Indexes[i], Leds[i].GetCurrentColor());
  }
  ledService.Display();  
}
