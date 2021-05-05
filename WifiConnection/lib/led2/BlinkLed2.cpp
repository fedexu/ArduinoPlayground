#include "BlinkLed2.h"

int ledPin = 2;

void BlinkLed2::blinkLed(int onSeconds){
  digitalWrite(ledPin, HIGH);
  delay(onSeconds);
  digitalWrite(ledPin, LOW);
}

void BlinkLed2::blinkLed(int onSeconds, int offSeconds){
  digitalWrite(ledPin, HIGH);
  delay(onSeconds);
  digitalWrite(ledPin, LOW);
  delay(offSeconds);
}

void BlinkLed2::setupLed(){
      pinMode(ledPin, OUTPUT);
}
