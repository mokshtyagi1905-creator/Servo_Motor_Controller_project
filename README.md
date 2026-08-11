# 🎛️ Servo Motor Controller V1.0

An Arduino-based servo motor control system built in **Tinkercad** using a potentiometer, servo motor, LED indicators, and a buzzer. The potentiometer controls the servo angle from **0° to 180°**, while the LEDs and buzzer provide feedback based on the current servo position.

---

## 📌 Project Overview

This project demonstrates how an analog input can be used to control a servo motor.

The Arduino reads the potentiometer value using `analogRead()`, producing a value from **0 to 1023**. The `map()` function converts this value into a servo angle from **0° to 180°**.

Based on the servo angle, the system activates different LEDs and buzzer patterns.

---

## ✨ Features

- 🎛️ Potentiometer-based servo control
- 🔄 Converts **0–1023** analog input to **0–180°**
- 🟢 Green LED for 0–60°
- 🟡 Yellow LED for 61–120°
- 🔴 Red LED for 121–180°
- 🔕 No buzzer in the green region
- 🔔 Slow buzzer in the yellow region
- 🚨 Fast buzzer in the red region
- 💻 Serial Monitor displays potentiometer value and servo angle

---

## 🛠️ Components Used

- Arduino Uno
- Servo Motor
- Potentiometer
- Green LED
- Yellow LED
- Red LED
- Active Buzzer
- 3 × 220 Ω Resistors
- Breadboard
- Jumper Wires

---

## 📊 Control Zones

| Servo Angle | LED | Buzzer |
|------------:|-----|--------|
| 0–60° | 🟢 Green | OFF |
| 61–120° | 🟡 Yellow | Slow Beep |
| 121–180° | 🔴 Red | Fast Beep |

---

## ⚙️ Working Principle

1. Potentiometer provides analog input through `A0`.
2. `analogRead()` reads a value from **0–1023**.
3. `map()` converts **0–1023** into **0–180°**.
4. The servo moves to the calculated angle.
5. `if`, `else if`, and `else` determine the active region.
6. The corresponding LED is turned ON.
7. The buzzer provides different feedback for each region.
8. Potentiometer value and servo angle are displayed on the Serial Monitor.

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Red LED | D2 |
| Green LED | D3 |
| Yellow LED | D4 |
| Servo Signal | D5 |
| Buzzer | D6 |
| Potentiometer | A0 |

---

## 🎛️ Potentiometer Connections

- One outer pin → **5V**
- Middle pin → **A0**
- Other outer pin → **GND**

The outer pins can be swapped to reverse the potentiometer direction.

---

## 💡 LED Connections

Each LED uses a **220 Ω resistor**.

- Red LED anode → D2
- Green LED anode → D3
- Yellow LED anode → D4
- Each LED cathode → 220 Ω resistor → GND

---

## ⚙️ Servo Connections

- Signal → **D5**
- VCC → **5V**
- GND → **GND**

The servo is controlled using the `Servo.h` library.

---

## 🔔 Buzzer Connections

- Positive → **D6**
- Negative → **GND**

---

## 🧠 Concepts Practiced

- Arduino Programming
- Analog Input
- `analogRead()`
- 10-bit ADC
- Analog-to-Digital Conversion
- `map()`
- Servo Motor Control
- `Servo.h`
- `myServo.attach()`
- `myServo.write()`
- Digital Output
- LEDs
- Current-Limiting Resistors
- Buzzer Control
- `delay()`
- `if`, `else if`, `else`
- Logical Operators
- Serial Communication
- `Serial.begin()`
- `Serial.print()`
- `Serial.println()`
- Conditional Logic
- Embedded System Control

---

## 🧮 Analog Input and Mapping

The Arduino Uno uses a **10-bit ADC**:

**2¹⁰ = 1024 possible values**

Since counting starts from zero, the range is:

**0–1023**

The `map()` function converts:

**0–1023 → 0–180°**

| Potentiometer | Servo |
|--------------:|------:|
| 0 | 0° |
| ≈256 | ≈45° |
| ≈512 | ≈90° |
| ≈768 | ≈135° |
| 1023 | 180° |

---

## 🔄 Project Flow

Potentiometer → `analogRead()` → 0–1023 → `map()` → 0–180° → LED/Buzzer Region → Servo → Serial Monitor

---

## 💻 Serial Monitor Output

Example:

---------
Servo Motor Controller
---------

Potentiometer: 125 | Servo Angle: 22
Potentiometer: 512 | Servo Angle: 90
Potentiometer: 768 | Servo Angle: 135
Potentiometer: 1023 | Servo Angle: 180

## ⚠️ Current Limitation

The current version uses `delay()` for buzzer timing. During the delay, the Arduino temporarily pauses program execution, so the servo and Serial Monitor do not update continuously.

## 🚀 Future Improvements

- Replace `delay()` with `millis()` for non-blocking buzzer control
- Improve servo responsiveness while the buzzer is active
- Add an LCD or OLED display
- Add multiple operating modes
- Add manual servo control buttons
- Add adjustable angle thresholds
- Add servo position feedback

## 👨‍💻 Author

**Moksh**

Built as part of my Arduino and Robotics learning journey using **Tinkercad**.

