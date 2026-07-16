#include <Arduino.h>

#define led_pin 9
#define pot_pin A4

unsigned long last_time;

void setup()
{
  pinMode(led_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}

void loop()
{
  int val;
  val = analogRead(pot_pin);
  val = map(val, 0, 1023, 0, 255);
  val = constrain(val, 0, 255);

  if (millis() - last_time > 500)
  {
    last_time = millis();
    analogWrite(led_pin, val);
  }
}
