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

  // return 0 after 12000 microseconds which is appoximately 206cm
  unsigned long duration = pulseIn(EchoPin, HIGH, 12000);
  float distance = (duration/58);

  if (duration == 0) {
    Serial.println("no echo");
  } else {
    Serial.println(distance);
  }
  
  delay(60);
}
