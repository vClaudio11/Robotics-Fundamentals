const int TrigPin = 7;
const int EchoPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  float time = pulseIn(EchoPin, HIGH, 30000);
  float distance = (time/58);
  Serial.println(distance);
  delay(60);
}
