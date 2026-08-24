
#pragma once
#ifndef __HAL_DEFS_H__
#define __HAL_DEFS_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "gpio_num.h"






// motors : (PINS L298N)
// - L298N
#define IN1 4 // IN1, IN2 : left wheel command (stop, move forward, move backward)
#define IN2 5
#define ENA 10 // must be PWM (ledc) // speed of left wheel
#define IN3 6 // IN3, IN4 : right wheel command (stop, move forward, move backward)
#define IN4 7 
#define ENB 11 // must be PWM (ledc) // speed of right wheel
// - motors (wheels)
#define LEFT_MOTOR_CMD_1_PIN IN1
#define LEFT_MOTOR_CMD_2_PIN IN2
#define RIGHT_MOTOR_CMD_1_PIN IN3
#define RIGHT_MOTOR_CMD_2_PIN IN4
#define LEFT_MOTOR_SPEED_PIN ENA
#define RIGHT_MOTOR_SPEED_PIN ENB













#ifdef __cplusplus
}
#endif


#endif // __HAL_DEFS_H__