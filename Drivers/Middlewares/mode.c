#include "mode.h"

void waiting_mode(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, OFF);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, OFF);	
	
	for (int i = 0; i <= 15; i++) {
		usSRegInBuf[i] = 0;	
	}
}
void modeVD(void) {
	HAL_Delay(250);
	ISTD_OFF;
	HAL_Delay(5000);
		measuringVD(); 			  
	usSRegHoldBuf[1] = 0;
	ISTD_ON;
}

void modeVD_pulse(void) {
	HAL_Delay(250);
	id30min = 0; id30max = 0;

	HAL_TIM_Base_Start_IT(&htim2);
	PWMN_Start(&htim1, TIM_CHANNEL_2);
	HAL_Delay(500);
	HAL_TIM_Base_Stop_IT(&htim2);
	PWMN_Stop(&htim1, TIM_CHANNEL_2);
	
	ISTD_OFF;
	HAL_Delay(5000);
	measuringVD();
				  
	usSRegHoldBuf[1] = 0;

	ISTD_ON;
}

void modeVZ(void) {
	HAL_Delay(250);
	ISTZ_OFF;
	HAL_Delay(5000);
		measuringVZ();		  
	usSRegHoldBuf[1] = 0;
	ISTZ_ON;
}

void modeVZ_pulse(void) {
	HAL_Delay(250);
	iz30min = 0, iz30max = 0;
	
	HAL_TIM_Base_Start_IT(&htim3);
	PWMN_Start(&htim1, TIM_CHANNEL_3);	  
	HAL_Delay(500);
	HAL_TIM_Base_Stop_IT(&htim3);
	PWMN_Stop(&htim1, TIM_CHANNEL_3);
	
	ISTZ_OFF;
	HAL_Delay(5000);
	measuringVZ();
			  
	usSRegHoldBuf[1] = 0;
	
	ISTZ_ON;
}

void diagnostic(void) {
	HAL_Delay(250);
	id30min = 0, id30max = 0;
	
	HAL_TIM_Base_Start_IT(&htim2);
	PWMN_Start(&htim1, TIM_CHANNEL_2);	  
	HAL_Delay(2000);
	HAL_TIM_Base_Stop_IT(&htim2);
	PWMN_Stop(&htim1, TIM_CHANNEL_2);
	
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
}