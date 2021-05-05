#include <Arduino.h>

#ifndef BlinkLed2_h
#define BlinkLed2_h

class BlinkLed2
{
public:
    static void blinkLed(int onSeconds);
    static void blinkLed(int onSeconds, int offSeconds);
    static void setupLed();
};


#endif // BlinkLed_h