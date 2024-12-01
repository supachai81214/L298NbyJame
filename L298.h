#ifndef L298_H 
#define L298_H

#include <Arduino.h>

// ค่าคงที่สำหรับทิศทาง
#define FORWARD  1
#define BACKWARD 2
#define STOP     0

class L298 {
  public:
    int in1, in2, en;  // มอเตอร์ 1
    int in3, in4, en2; // มอเตอร์ 2

    float maxRPS;      // รอบสูงสุดต่อวินาที
    int pwmFrequency;  // ความถี่ PWM

    // คอนสตรัคเตอร์
    L298(int pIn1, int pIn2, int pEn, int pIn3, int pIn4, int pEn2, float maxRPSMotor, int pwmFreq = 2000);

    // ฟังก์ชันการตั้งค่าพิน
    void setupPins();

    // ฟังก์ชันตั้งค่า Fast PWM
    void setupFastPWM();

    // ฟังก์ชันควบคุมมอเตอร์ 1 ด้วย RPS
    void controlMotor1(int direction, float rps);

    // ฟังก์ชันควบคุมมอเตอร์ 2 ด้วย RPS
    void controlMotor2(int direction, float rps);
};
#endif
