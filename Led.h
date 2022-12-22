#include <FastLED.h>
// Model of a Led that can transition

enum BrightnessMode
{
  BRIGHTEN,
  DIM
};

class Led
{
 protected:
     CRGB _color;
     CRGB _currentColor;
     BrightnessMode _brightnessMode = DIM;
     short _percentage = 0;

 public:
     Led();
     
     Led(CRGB color);

     bool ShiftColor(int increment);

     CRGB GetCurrentColor();

     void SetColor(CRGB color);
};
