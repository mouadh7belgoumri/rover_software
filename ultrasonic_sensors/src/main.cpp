//TODO update pin set to match the circuit diagram

#include <Arduino.h>
#include <Servo.h>
#define BAUD_RATE 9600
#define SERVO_PIN 6
#define ECHO_PIN 7
#define TRIG_PIN 8
#define SERVO_PIN2 9
#define ECHO_PIN2 10
#define TRIG_PIN2 11

Servo mtr, mtr2;
uint64_t pulseDuration;
float distance, distance2;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  mtr.attach(SERVO_PIN);
  mtr2.attach(SERVO_PIN2);
  Serial.begin(BAUD_RATE);
}

void loop()
{
  for (int pos = 0; pos <= 180; pos++)
  {
    digitalWrite(TRIG_PIN, LOW);
    digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    pulseDuration = pulseIn(ECHO_PIN, HIGH);
    distance = (pulseDuration * 0.0343) / 2;
    Serial.print("distance at front :");
    Serial.println(distance);
    pulseDuration = pulseIn(ECHO_PIN2, HIGH);
    distance2 = (pulseDuration * 0.0343) / 2;
    Serial.print("Distance at back : ");
    Serial.println(distance2);
    mtr.write(pos);
    mtr2.write(pos);
    delay(10);
  }
  for (int pos = 180; pos >= 0; pos--)
  {
    digitalWrite(TRIG_PIN, LOW);
    digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    pulseDuration = pulseIn(ECHO_PIN, HIGH);
    distance = (pulseDuration * 0.0343) / 2;
    Serial.print("distance at front :");
    Serial.println(distance);
    pulseDuration = pulseIn(ECHO_PIN2, HIGH);
    distance2 = (pulseDuration * 0.0343) / 2;
    Serial.print("Distance at back : ");
    Serial.println(distance2);
    mtr.write(pos);
    mtr2.write(pos);
    delay(10);
  }
}