// LED + button
// Pin 9 -> 220 ohm resistor -> LED long leg; LED short leg -> GND
// Pin 2 -> button -> GND (INPUT_PULLUP, so pressed = LOW)

const int LED_PIN = 9;
const int BUTTON_PIN = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(BUTTON_PIN));
  bool pressed = digitalRead(BUTTON_PIN) == LOW;
  if (pressed) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
