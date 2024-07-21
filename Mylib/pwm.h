#ifndef PWM_H
#define PWM_H
#include "stm32f1xx.h"
void pwm_duty_handle(TIM_HandleTypeDef *tim, uint32_t channel, uint8_t duty); // XU LY PWM
#endif
