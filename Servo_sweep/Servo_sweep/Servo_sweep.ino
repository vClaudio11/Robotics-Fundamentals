#include <Servo.h>

Servo myServo;
const int ServoPin = 6;
const int SensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int knob = analogRead(SensorPin);
  myServo.write(map(knob, 0, 1023, 0 , 180));
  Serial.println(map(knob, 0, 1023, 0 , 180));
  delay(50);
}
