#include "pwm.h"
void pwm_duty_handle(TIM_HandleTypeDef *tim, uint32_t channel, uint8_t duty) // XU LY PWM
{
	uint16_t ccr = (uint16_t) duty*(tim->Instance->ARR)/100;
	switch(channel)
	{
		case TIM_CHANNEL_1:
			tim->Instance->CCR1 = ccr;
			break;
		case TIM_CHANNEL_2:
			tim->Instance->CCR2 = ccr;
			break;
		case TIM_CHANNEL_3:
			tim->Instance->CCR3 = ccr;
			break;
		case TIM_CHANNEL_4:
			tim->Instance->CCR4 = ccr;
			break;
	}
}
