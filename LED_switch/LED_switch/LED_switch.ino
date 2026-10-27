// LED + button
// Pin 9 -> 220 ohm resistor -> LED long leg; LED short leg -> GND
// Pin 2 -> button -> GND (INPUT_PULLUP, so pressed = LOW)

const int LED_PIN = 9;
const int BUTTON_PIN = 2;
const unsigned long DEBOUNCE_MS = 80;

bool ledOn = false;
bool lastReading = false;
bool stablePressed = false;
unsigned long lastChangeTime = 0;
int presses = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool reading = digitalRead(BUTTON_PIN) == LOW;
  // allows for a DEBOUNCE_MS length amount of time for debounce to occur
  bool stable = millis()-lastChangeTime > DEBOUNCE_MS;

  if (reading && !lastReading && stable) {
    ledOn = !ledOn;  
    presses = presses + 1;
    Serial.println(presses);
  }
  // handles both toggle on and off
  if (reading != lastReading) {
    lastChangeTime = millis(); 
  }
    lastReading = reading;
    digitalWrite(LED_PIN, ledOn);
}

