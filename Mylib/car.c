#include "car.h"
#include "motor_handle.h"

motor_typedef MOTOR_LEFT;
motor_typedef MOTOR_RIGHT;

void car_control(CarState car_state, uint8_t speed) // dieu khien xe
{
	switch(car_state)
	{
		case CAR_STOP_STATE:
			motor_control(&MOTOR_LEFT, MOTOR_STOP, 0);
			motor_control(&MOTOR_RIGHT, MOTOR_STOP, 0);
			break;
		case CAR_FORWARD_STATE:
			motor_control(&MOTOR_LEFT, MOTOR_CW, speed);
			motor_control(&MOTOR_RIGHT, MOTOR_CW, speed);
			break;
		case CAR_BACKWARD_STATE:
			motor_control(&MOTOR_LEFT, MOTOR_CCW, speed);
			motor_control(&MOTOR_RIGHT, MOTOR_CCW, speed);
			break;
		case CAR_LEFT_STATE:
			motor_control(&MOTOR_LEFT, MOTOR_STOP, 0);
			motor_control(&MOTOR_RIGHT, MOTOR_CCW, speed);
			break;
		case CAR_RIGHT_STATE:
			motor_control(&MOTOR_LEFT, MOTOR_CCW, speed);
			motor_control(&MOTOR_RIGHT, MOTOR_STOP, 0);
			break;		
	}
}
void car_init(TIM_HandleTypeDef *htim) //khai bao cac gia tri cua xe
{
	motor_init(&MOTOR_LEFT,GPIOB, GPIO_PIN_14, htim , TIM_CHANNEL_1); // khai bao gia tri cua motor ben trai
	motor_init(&MOTOR_RIGHT,GPIOB, GPIO_PIN_15, htim , TIM_CHANNEL_2);// khai bao gia tri cua motor ben phai
	car_control(CAR_STOP_STATE,0);
	
}