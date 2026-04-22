#include <Arduino.h>
#include <Servo.h>
#define BAUD_RATE 9600
#define ECHO_PIN 10
#define TRIG_PIN 11
#define SERVO_PIN 9

Servo mtr;
uint64_t pulseDuration;
uint64_t distance;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
  mtr.attach(SERVO_PIN);
}

void loop()
{
  for (int pos; pos <= 180; pos++)
  {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10),
    pulseDuration = pulseIn(ECHO_PIN, HIGH);
    distance = (pulseDuration * .0343) / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
    mtr.write(pos);
    delay(10);
    Serial.println("position : ");
    Serial.print(pos);
  }
}