
#pragma once
#ifndef __MOTOR_H__
#define __MOTOR_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "hal_defs.h"


/*-----------------------------------------------------------------------------------------------*/
/* types                                                                                         */
/*-----------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------*/
/* headers                                                                                       */
/*-----------------------------------------------------------------------------------------------*/

// config L298N pins + ledc periph
void motor_init();
// move left motor and right motor with the speeds in args
void motor_set_speeds(int left_speed, int right_speed);


#ifdef __cplusplus
}
#endif


#endif // __MOTOR_H__