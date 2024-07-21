#ifndef MOTOR_HANDLE_H
#define MOTOR_HANDLE_H
#include "stm32f1xx.h"
typedef enum
{
	MOTOR_STOP,
	MOTOR_CW, // cung chieu kim dong ho
	MOTOR_CCW, // nguoc chieu kim dong ho
}motorstate;
typedef struct
{
	GPIO_TypeDef *io_port;
	uint16_t io_pin;
	TIM_HandleTypeDef *tim;
	uint16_t tim_channel;
	uint8_t speed;
	motorstate motor_state;
}motor_typedef;
void motor_control(motor_typedef *motor,motorstate motor_state, uint8_t speed); // XU LI MOTOR 
void motor_init(motor_typedef *motor, GPIO_TypeDef *io_port,uint16_t io_pin,TIM_HandleTypeDef *tim,	uint16_t tim_channel); // khoi tao motor 
#endif