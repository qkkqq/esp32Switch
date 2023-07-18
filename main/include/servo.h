#ifndef __SERVO_H_
#define __SERVO_H_
#include "driver/ledc.h"
void Servo_Init(char gpioPin);
int Alculate_PWM(int degree);
void Senor_Control(int degree);
#define SWITCH_OPEN Senor_Control(180);
#define SWITCH_CLOSE Senor_Control(0);

#endif // !__SERVO_H_