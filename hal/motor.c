
#include "motor.h"
#include "driver/gpio.h"
#include "driver/ledc.h"




/*-----------------------------------------------------------------------------------------------*/
/* fns definitions                                                                             */
/*-----------------------------------------------------------------------------------------------*/

// config L298N pins + ledc periph
void motor_init()
{
    //config pins IN1, IN2, IN3, IN4
    gpio_config_t io_conf =
    {
        .pin_bit_mask = (1ULL<<IN1)|(1ULL<<IN2)|(1ULL<<IN3)|(1ULL<<IN4),
        .mode = GPIO_MODE_OUTPUT
    };
    gpio_config(&io_conf);

    // ledc periph config (pwm) ; pins ENA, ENB
    ledc_timer_config_t ledc_timer =
    {
        .speed_mode = LEDC_LOW_SPEED_MODE, .duty_resolution = LEDC_TIMER_8_BIT,
        .timer_num = LEDC_TIMER_0, .freq_hz = 5000
    };
    ledc_timer_config(&ledc_timer);
    ledc_channel_config_t ch_conf = // same ledc channel cfg for ENA and ENB
    {
        .channel = LEDC_CHANNEL_0, .duty = 0, .gpio_num = ENA,
        .speed_mode = LEDC_LOW_SPEED_MODE, .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ch_conf);
    ch_conf.channel = LEDC_CHANNEL_1; ch_conf.gpio_num = ENB;
    ledc_channel_config(&ch_conf);
}


/// @brief move left motor and right motor with the corresponding speeds
///        if x_speed > 0 : move forward with speed |x_speed|*2.55
///        if x_speed > 0 : move backward with speed |x_speed|*2.55
/// @param left_speed 
/// @param right_speed 
void motor_set_speeds(int left_speed, int right_speed)
{
    // left motor speed
    // if speed > 0 : set IN1 to 1 and IN2 to 0 : move forward
    // if speed < 0 : set IN1 to 0 and IN2 to 1 : move backward
    pio_set_level(IN1, left_speed > 0); gpio_set_level(IN2, left_speed < 0);
    // set ENA to speed 
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, abs(left_speed) * 2.55);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

    // right motor speed
    gpio_set_level(IN3, right_speed > 0); gpio_set_level(IN4, right_speed < 0);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, abs(right_speed) * 2.55);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
}
