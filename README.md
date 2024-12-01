# L298NbyJame
# L298NbyJame

### Version: 1.0.0
### Author: Supachai
### Maintainer: Supachai81214@gmail.com

### Description
L298 Motor Driver Library with RPS control and Fast PWM.

This library is designed to control motors using the L298N motor driver module with precise RPS control and fast PWM functionality.

### Features
- Control motors using the L298N motor driver.
- RPS-based motor speed control.
- Fast PWM support for efficient motor operation.

### Installation
1. Download or clone this repository.
2. Copy the `L298NbyJame` folder into your Arduino `libraries` directory.

### Usage
```cpp
#include <L298NbyJame.h>

L298 motor(9, 8, 10, 11, 12, 13, 100, 2000);

void setup() {
  motor.setupPins();
}

void loop() {
  motor.controlMotor1(FORWARD, 50); // Motor 1 forward at 50 RPS
  motor.controlMotor2(BACKWARD, 30); // Motor 2 backward at 30 RPS
}
