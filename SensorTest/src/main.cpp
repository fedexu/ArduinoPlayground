#include <Arduino.h>
#include "pins_espressif.h"

int output_value = 0;

int value = 0;
char printBuffer[128];

// moisture sensor calibration values
const int airValue = 3650;   // value in the air
const int waterValue = 1350; // value in a cup full of water
int soilMoisturePercentage = 0;

void setup()
{

  Serial.begin(9600);
  //DIGITAL SETUP
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // ANALOG SETUP
  // pinMode(2, INPUT);
  // pinMode(4, INPUT);
  // pinMode(36, INPUT);
  // pinMode(34, INPUT);
  // pinMode(38, INPUT);
  // pinMode(39, INPUT);
}

void loop()
{
  // Serial.println("Start Loop");
  // put your main code here, to run repeatedly:
  //LED CHECK
  // digitalWrite(ledPin, HIGH);
  // delay(1000);
  // digitalWrite(ledPin, LOW);
  // delay(1000);
  //LED CHECK

  // output_value = analogRead(2); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 2: ");
  // Serial.println(output_value);

  // output_value = analogRead(4); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 4: ");
  // Serial.println(output_value);

  // output_value = analogRead(36); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 36: ");
  // Serial.println(output_value);

  // output_value = analogRead(34); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 34: ");
  // Serial.println(output_value);

  // output_value = analogRead(38); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 38: ");
  // Serial.println(output_value);

  // output_value = analogRead(39); //gets the value from the soil moisture sensor
  // Serial.print("Analog value 39: ");
  // Serial.println(output_value);

  // // DIGITAL WRITE TEST
  // digitalWrite(26, HIGH);
  // digitalWrite(25, HIGH);
  // digitalWrite(17, HIGH);
  // digitalWrite(16, HIGH);
  // digitalWrite(27, HIGH);
  // digitalWrite(14, HIGH);
  // digitalWrite(12, HIGH);
  // digitalWrite(13, HIGH);
  // delay(1000);
  // digitalWrite(26, LOW);
  // digitalWrite(25, LOW);
  // digitalWrite(17, LOW);
  // digitalWrite(16, LOW);
  // digitalWrite(27, LOW);
  // digitalWrite(14, LOW);
  // digitalWrite(12, LOW);
  // digitalWrite(13, LOW);

  delay(1000);

  digitalWrite(12, HIGH); // Turn the sensor ON
  delay(1000);            // wait 1000 milliseconds

  value = analogRead(34); // get adc value
  sprintf(printBuffer, "Value: %d", value);
  Serial.println(printBuffer);

  // Do not power the sensor constantly, but power it only when you take the readings.
  digitalWrite(12, LOW); // Turn the sensor OFF

  soilMoisturePercentage = map(value, airValue, waterValue, 0, 100);
  sprintf(printBuffer, "%d%%", soilMoisturePercentage);

  Serial.println(printBuffer);
}
