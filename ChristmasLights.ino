#include <FastLED.h>
#include <Arduino.h>

#include "Led.h"
#include "LedService.h"

CHSV Colors[] = {
  CHSV(00, 255, 255), //Red
  CHSV(46, 255, 255), //Yellow
  CHSV(170, 255, 255), //Blue
  CHSV(21, 255, 255), //Orange
  CHSV(85, 255, 255), //Green
  CHSV(213, 255, 255)}; //Purple

Led LED1;
Led LED2;

LedService ledService;

bool result1 = false;
short index1 = 0;

bool result2 = false;
short index2 = 0;

void setup() {
  for(short i = 0; i < 150; i++)
  {
    ledService.SetLed(i, Colors[i % 6]);
  }
}

void loop() {
  if(result1)
  {
    index1 = floor(random(0, 150));
    LED1.SetColor(ledService.GetLedColor(index1));
  }
  if(result2)
  {
    index2 = floor(random(0, 150));
    LED2.SetColor(ledService.GetLedColor(index2));
  }
  result1 = LED1.ShiftColor(1);
  result2 = LED2.ShiftColor(2);
  ledService.SetLed(index1, LED1.GetCurrentColor());
  ledService.SetLed(index2, LED2.GetCurrentColor());
  ledService.Display();  
}
