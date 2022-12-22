#include <FastLED.h>
#include "Led.h"

Led::Led()
{
  _color = CRGB(0,0,0);
  _currentColor = CRGB(0,0,0);
}

Led::Led(CRGB color)
{
  _color = color;
  _currentColor = color;
}

bool Led::ShiftColor(int increment)
{
  _percentage += increment;
  if(_brightnessMode == DIM)
  {
    _currentColor.r = round(_color.r*(1 - _percentage/ 100.0));
    _currentColor.g = round(_color.g*(1 - _percentage/ 100.0));
    _currentColor.b = round(_color.b*(1 - _percentage/ 100.0));
  }
  if(_brightnessMode == BRIGHTEN)
  {
    _currentColor.r = round(_percentage * _color.r / 100.0);
    _currentColor.g = round(_percentage * _color.g / 100.0);
    _currentColor.b = round(_percentage * _color.b / 100.0);
  }
  if(_percentage >= 100)
  {
    _percentage = 0;
    if(_brightnessMode == DIM)
    {
        _currentColor = CRGB(0,0,0);
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

CRGB Led::GetCurrentColor()
{
  return _currentColor;
}

void Led::SetColor(CRGB color)
{
  _color = color;
}
