#include "L298NbyJame.h"

// คอนสตรัคเตอร์
L298::L298(int pIn1, int pIn2, int pEn, int pIn3, int pIn4, int pEn2, float maxRPSMotor, int pwmFreq) {
  in1 = pIn1;
  in2 = pIn2;
  en = pEn;
  in3 = pIn3;
  in4 = pIn4;
  en2 = pEn2;
  maxRPS = maxRPSMotor;
  pwmFrequency = pwmFreq;
}

// ฟังก์ชันตั้งค่าพิน
void L298::setupPins() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en2, OUTPUT);
  setupFastPWM();
}

// ฟังก์ชันตั้งค่า Fast PWM
void L298::setupFastPWM() {
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11);
  ICR1 = (F_CPU / (pwmFrequency * 8)) - 1;
}

// ฟังก์ชันควบคุมมอเตอร์ 1 ด้วย RPS
void L298::controlMotor1(int direction, float rps) {
  int dutyCycle = constrain((rps / maxRPS) * 255, 0, 255);
  switch (direction) {
    case FORWARD:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      OCR1A = map(dutyCycle, 0, 255, 0, ICR1);
      break;
    case BACKWARD:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      OCR1A = map(dutyCycle, 0, 255, 0, ICR1);
      break;
    case STOP:
    default:
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      OCR1A = 0;
      break;
  }
}

// ฟังก์ชันควบคุมมอเตอร์ 2 ด้วย RPS
void L298::controlMotor2(int direction, float rps) {
  int dutyCycle = constrain((rps / maxRPS) * 255, 0, 255);
  switch (direction) {
    case FORWARD:
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      OCR1B = map(dutyCycle, 0, 255, 0, ICR1);
      break;
    case BACKWARD:
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      OCR1B = map(dutyCycle, 0, 255, 0, ICR1);
      break;
    case STOP:
    default:
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      OCR1B = 0;
      break;
  }
}
