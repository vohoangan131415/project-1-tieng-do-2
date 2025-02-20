#ifndef CAR_H
#define CAR_H
#include "stm32f1xx.h"
typedef enum // khai bao state cua xe
{
	CAR_STOP_STATE,
	CAR_FORWARD_STATE,
	CAR_BACKWARD_STATE,
	CAR_LEFT_STATE,
	CAR_RIGHT_STATE,
}CarState;
void car_control(CarState car_state, uint8_t speed);
void car_init(TIM_HandleTypeDef *htim);
#endif