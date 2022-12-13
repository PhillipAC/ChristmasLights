#include <FastLED.h>
#include <Arduino.h>

#include "LedService.h"

LedService ledService; //Service to handle the lightshow

CHSV Colors[] = {
  CHSV(160, 255, 255),
  CHSV(32, 255, 255),
  CHSV(64, 255, 255),
  CHSV(192, 255, 255),
  CHSV(96, 255, 255),
  CHSV(0, 255, 255)};
int Offset = 0;

void setup() {}

void loop() {
  ledService.ShowColorSequence(Colors, Offset, 1);
  Offset++;
  if (Offset == 6){
    Offset = 0;
  }
}
