/*
 * @Description: test motor
 * @Author: your name
 * @Date: 2019-07-21 12:35:48
 * @LastEditTime: 2019-07-21 21:40:21
 * @LastEditors: Please set LastEditors
 */

#include "motor_dc.h"

void irosbot_motor_dc_test(int argc, char *argv[])
{
    motor_t left_motor = motor_dc_create("pwm2", 2, "pwm2", 3);

    motor_execute(left_motor, MOTOR_INIT, (0));
    motor_execute(left_motor, MOTOR_ENABLE, (0));

    rt_int8_t speed = 0;
    for (speed=-100; speed < 100; speed+=5)
    {
        motor_execute(left_motor, MOTOR_RUN, (void *) &speed);
        rt_thread_mdelay(500);
    }
}
MSH_CMD_EXPORT(irosbot_motor_dc_test, irosbot motor dc test);
