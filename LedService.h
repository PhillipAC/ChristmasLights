// Led.h

#include <FastLED.h>

#define NUM_LEDS 150

class LedService
{
 protected:
     CRGB Leds[NUM_LEDS];
     int LedCount;

 public:
     LedService()
     {
         LedCount = NUM_LEDS;
         LEDS.addLeds<WS2812, 7, GRB>(Leds, NUM_LEDS);
         LEDS.setBrightness(84);
     };

     void ShowEveryNthColor(CHSV color, int n, double duration) {
         for (int i = 0; i < LedCount; i++) {
             if (i % n == 0) {
                 Leds[i] = color;
             }
             else {
                 Leds[i] = CRGB(0, 0, 0);
             }
         }
         FastLED.show();
         delay(round(duration * 1000));
     };

     void Fadeall() {
         for (int i = 0; i < NUM_LEDS; i++) {
             Leds[i].nscale8(250);
         }
     }

     void ShowSolidColor(CHSV color, double duration) {
         for (int i = 0; i < NUM_LEDS; i++) {
             Leds[i] = color;
         }
         FastLED.show();
         delay(round(duration * 1000));
     }

     void ShowEveryOtherColor(CHSV color1, CHSV color2, double duration) {
         for (int i = 0; i < NUM_LEDS; i++) {
             if (i % 2 == 0) {
                 Leds[i] = color1;
             }
             else {
                 Leds[i] = color2;
             }
         }
         FastLED.show();
         delay(round(duration * 1000));
     }

     void ShowColorSequence(CHSV color[], int offset, double duration) {
         for (int i = 0; i < NUM_LEDS; i++) {
             int index = (i+offset)%6;//(sizeof color/sizeof color[0]);
             Leds[i] = color[index];
         }
         FastLED.show();
         delay(round(duration * 1000));
     }
};
