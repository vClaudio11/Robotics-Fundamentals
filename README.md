# Robotics Fundamentals
This repo is aimed to be a stored collection of minature beginner arduino projects to get me accustomed to the software and hardware aspects of arduino and C++.

## Scope
This repo aims to cover the following projects:

| # | Project | New skill introduced | Builds on |
|---|---------|----------------------|-----------|
| 0.1 | Blink an LED, read a button | Digital I/O, `pinMode`, `digitalWrite/Read` | — (first project) |
| 0.2 | Fade an LED, read a potentiometer | Analog I/O, PWM | 0.1 |
| 0.3 | Sweep a servo, print sensor values over serial | Servo control, serial communication | 0.1, 0.2 |
| 0.4 | Read HC-SR04 distance into serial monitor | Timing-based sensors (pulse width) | 0.3 |
| 0.5 | Log Arduino sensor data into Python via `pyserial` → CSV | Arduino↔Python bridge | 0.4 |
| 0.6 | Rewrite 0.1–0.4 using functions, then a `struct`/class wrapping a sensor | Code organization, OOP in C++ | All of the above |

**Milestone:** ultrasonic sensor streaming live readings into a Python-logged CSV. Proves sensing + the language bridge. No new hardware beyond the starter kit.

## Hardware
- Board: Arduino Uno R3 
- Kit: Elego UNO Project complete starter kit

## Repo structure
```
robotics-fundamentals/
├── LED_potentiometer/
│   └── LED_potentiometer.ino 
├── LED_switch/
│   └── LED_switch.ino
├── Servo_sweep/
│   └── Servo_sweep.ino
├── Ultrasonic_distance/
│   └── Ultrasonic_distance.ino 
├── .gitignore
└── README.md
```

## How to run a sketch
1. Open the .ino in the Arduino IDE (or VS Code)
2. Select board and port
3. Serial monitor baud rate, if the sketch prints, I used 9600

## Sketches

| Sketch | What it does | Key concepts |
|--------|--------------|--------------|
| LED_potentiometer | Either dims or increases the brightness of an LED by converting analog potentiometer data to digital to be read for the LED | .map() to cleanly convert analog to digital, analogRead/analogWrite |
| LED_Switch | Aimed to switch a light on and off using a button and a toggle system | Read and writing HIGH/LOW values |
| Servo_sweep | Turns a servo arm 0 to 180 degrees using a potentiometer knob | .map() to convert analog potentiometer data to degrees for the servo sweep |
| Ultrasonic_distance | Prints out the distance of an object (if detected) every 60ms | delayMicroseconds() between HIGH/LOW Trig & Echo calls, pulseIn to read the Echo time whilst HIGH |

---

### 1. <LED_Switch>
**Goal:** Aimed to switch a light on and off using a button and a toggle system

**Parts:**
- Arduino Uno R3
- Breadboard
- 1 × LED
- 1 × 220Ω resistor
- 1 × tactile push button
- Jumper wires
- USB cable

**Wiring:**
| From | To |
|------|----|
| Uno pin 9 | 220Ω resistor, one leg |
| 220Ω resistor, other leg | LED long leg |
| LED short leg | GND |
| Uno pin 2 | button, one leg |
| button, diagonally opposite leg | GND |

**How it works:**
- pinMode(LED_PIN, OUTPUT) and pinMode(BUTTON_PIN, INPUT_PULLUP) initialize the setup where INPUT_PULLUP sets button pressed = LOW. The debounce mechanism of millis()-lastChangeTime > DEBOUNCE_MS ensures that 10 button clicks means the light changes states 10 times. Only if the button is pressed and the debounce is negligble then only change the state of the LED.

**Concepts learned:**
digitalREAD() is used to read the value of a set digital I/O pint
millis() prints the exact number of milliseconds since the project began running as an unsigned long
Serial.println() to print out a value or text in the serial monitor
pinMode() sets the specific action a pin will carry out, and if not set, it is INPUT by default

**Results / measurements:**
I measured the number of actual button presses and compared it to my verbal count as I pressed the button until 10 real presses matched the serial monitor output

**Bug I hit and how I fixed it:**
The initial bug I encountered was before the debounce was added. Clicking the button too quickly or half-pressing the button toggled it off/on which is a state that should be accounted for, not just clean presses. By adding a 80ms debounce time, the code waits until the current action and an action 80ms prior are compared instead of instantaneous fluctuations. This means quick presses and half-presses are neglected because their switch time was lesss than 80ms during testing.

---

### 2. <LED_potentiometer>
**Goal:** Either dims or increases the brightness of an LED by converting analog potentiometer data to digital to be read for the LED

**Parts:**
- Arduino Uno R3
- Breadboard
- 1 × LED
- 1 × 220Ω resistor
- 1 × potentiometer
- Jumper wires
- USB cable

**Wiring:**
| From | To |
|------|----|
| Uno pin 9 (PWM) | 220Ω resistor, one leg |
| 220Ω resistor, other leg | LED long leg (anode) |
| LED short leg (cathode) | GND |
| Potentiometer outer leg 1 | 5V |
| Potentiometer outer leg 2 | GND |
| Potentiometer middle leg (wiper) | Uno A0 |

**How it works:**
<!-- 3-5 sentences in your own words: what the code does, step by step -->

**Concepts learned:**
<!-- bullets, e.g. a term you can now define and why it matters -->

**Results / measurements:**
<!-- numbers you actually measured: counts, ranges, accuracy -->

**Bug I hit and how I fixed it:**
<!-- what went wrong, the cause, the fix -->

### 3. <Servo_sweep>
**Goal:** Turns a servo arm 0 to 180 degrees using a potentiometer knob

**Parts:**
- Arduino Uno R3
- Breadboard
- SG90 micro servo
- 1 × potentiometer
- Male-to-male jumper wires 
- USB cable

**Wiring:**
| From | To |
|------|----|
| Servo brown (or black) wire | GND |
| Servo red wire | 5V |
| Servo signal wire (orange or yellow) | Uno pin 6 |
| Potentiometer outer leg 1 | 5V |
| Potentiometer outer leg 2 | GND |
| Potentiometer middle leg | Uno A0 |

**How it works:**
<!-- 3-5 sentences in your own words: what the code does, step by step -->

**Concepts learned:**
<!-- bullets, e.g. a term you can now define and why it matters -->

**Results / measurements:**
<!-- numbers you actually measured: counts, ranges, accuracy -->

**Bug I hit and how I fixed it:**
<!-- what went wrong, the cause, the fix -->

### 4. <Ultrasonic_distanc>
**Goal:** Prints out the distance of an object (if detected) every 60ms

**Parts:**
- Arduino Uno R3
- Breadboard
- HC-SR04 ultrasonic sensor
- Jumper wires
- USB cable

**Wiring:**
| From (HC-SR04 pin) | To |
|--------------------|----|
| VCC | 5V |
| Trig | Uno pin 7 |
| Echo | Uno pin 8 |
| GND | GND |

**How it works:**
<!-- 3-5 sentences in your own words: what the code does, step by step -->

**Concepts learned:**
<!-- bullets, e.g. a term you can now define and why it matters -->

**Results / measurements:**
<!-- numbers you actually measured: counts, ranges, accuracy -->

**Bug I hit and how I fixed it:**
<!-- what went wrong, the cause, the fix -->

---

## Next
After this repo is completed I aim to combine the technical aspects of the servo and ultrasonic sensor and create a moving rover with obstacle detection.