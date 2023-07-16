#ifndef __SERVO_H_
#define __SERVO_H_
#include "driver/ledc.h"
void Servo_Init(char gpioPin);
int Alculate_PWM(int degree);
void Senor_Control(int degree);

#endif // !__SERVO_H_