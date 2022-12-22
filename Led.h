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
     CHSV _color;
     CHSV _currentColor;
     BrightnessMode _brightnessMode = DIM;
     short _percentage = 0;

 public:
     Led();
     
     Led(CHSV color);

     bool ShiftColor(int increment);

     CHSV GetCurrentColor();

     void SetColor(CHSV color);
};
