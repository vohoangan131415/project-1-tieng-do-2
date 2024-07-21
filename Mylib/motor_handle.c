#include "motor_handle.h"
#include "pwm.h"
void motor_control(motor_typedef *motor,motorstate motor_state, uint8_t speed) // XU LI MOTOR 
{
	switch(motor_state)
	{
		case MOTOR_STOP:
			HAL_GPIO_WritePin(motor->io_port, motor->io_pin, GPIO_PIN_RESET);
			pwm_duty_handle(motor->tim, motor->tim_channel, 0);
			break;
		case MOTOR_CW:
			HAL_GPIO_WritePin(motor->io_port, motor->io_pin, GPIO_PIN_RESET);
			pwm_duty_handle(motor->tim, motor->tim_channel, speed);
			break;
		case MOTOR_CCW:
			HAL_GPIO_WritePin(motor->io_port, motor->io_pin, GPIO_PIN_SET);
			pwm_duty_handle(motor->tim, motor->tim_channel, 100 - speed);
			break;
		
	}
}
void motor_init(motor_typedef *motor, GPIO_TypeDef *io_port,uint16_t io_pin,TIM_HandleTypeDef *tim,	uint16_t tim_channel)// khai bao cac gia tri cua motor
{
	motor->io_port = io_port;
	motor->io_pin = io_pin;
	motor->tim = tim;
	motor->tim_channel = tim_channel;
	HAL_TIM_PWM_Start(motor->tim,motor->tim_channel);
}