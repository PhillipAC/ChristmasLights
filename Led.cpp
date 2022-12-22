#include <FastLED.h>
#include "Led.h"

Led::Led()
{
  _color = CHSV(0,0,0);
  _currentColor = CHSV(0,0,0);
}

Led::Led(CHSV color)
{
  _color = color;
  _currentColor = color;
}

bool Led::ShiftColor(int increment)
{
  _percentage += increment;
  if(_brightnessMode == DIM)
  {
    _currentColor.v = round(_color.v*(1 - _percentage/ 100.0));
  }
  if(_brightnessMode == BRIGHTEN)
  {
    _currentColor.v = round(_percentage * _color.v / 100.0);
  }
  if(_percentage >= 100)
  {
    _percentage = 0;
    if(_brightnessMode == DIM)
    {
        _currentColor = CHSV(0,0,0);
        _brightnessMode = BRIGHTEN;
    }
    else if(_brightnessMode == BRIGHTEN)
    {
        _currentColor = _color;
        _brightnessMode = DIM;
        return true;
    }
  }
  return false;
}

CHSV Led::GetCurrentColor()
{
  return _currentColor;
}

void Led::SetColor(CHSV color)
{
  _color = color;
}
