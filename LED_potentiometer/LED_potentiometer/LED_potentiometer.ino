int LedPin = 9;
int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int knob = analogRead(sensorPin);
  int knob_converted = (knob / 4);
  analogWrite(LedPin, map(knob, 0, 1023, 0 ,255));
  Serial.println(knob);
  delay(50);
}
