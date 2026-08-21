
#include "motor.h"
#include "driver/gpio.h"





/*-----------------------------------------------------------------------------------------------*/
/* fns definitions                                                                             */
/*-----------------------------------------------------------------------------------------------*/

void motor_init()
{
    gpio_config_t io_conf =
    {
        .pin_bit_mask = (1ULL << GPIO_NUM_4) | (1ULL << GPIO_NUM_5) | 
                        (1ULL << GPIO_NUM_6) | (1ULL << GPIO_NUM_7),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0, 
        .pull_up_en = 0, 
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);
}
