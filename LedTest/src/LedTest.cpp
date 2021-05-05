#include <Arduino.h>
#include <BlinkLed2.h>

void setup()
{
  BlinkLed2::setupLed();
}

void loop()
{
  BlinkLed2::blinkLed(1000, 1000);
}
