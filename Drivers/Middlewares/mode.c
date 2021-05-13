#include "mode.h"

void WaitingMode (void) {
	LED_Cathode_VZ_OFF;
	LED_Cathode_VD_OFF;
	LED_VD_OFF;
	LED_VZ_OFF;	
	
	for (int i = 0; i <= 15; i++) {
		usSRegInBuf[i] = 0;	
	}
}
void StaticMeasurementMode_VD (void) {
	HAL_Delay(250);
	ISTD_OFF;
	HAL_Delay(5000);
		measuringVD(); 			  
	usSRegHoldBuf[1] = 0;
	ISTD_ON;
}

void PulseMeasurementMode_VD (void) {
	HAL_Delay(250);
	id30min = 0; //id30max = 0;

//	HAL_TIM_Base_Start_IT(&htim2);
	PWMN_Start(&htim1, TIM_CHANNEL_2);
	HAL_Delay(500);
	HAL_TIM_Base_Stop_IT(&htim2);
	usSRegInBuf[8] = id30min;
	usSRegInBuf[9] = id30max;
	PWMN_Stop(&htim1, TIM_CHANNEL_2);
	
	ISTD_OFF;
	HAL_Delay(5000);
	measuringVD();
				  
	usSRegHoldBuf[1] = 0;

	ISTD_ON;
}

void StaticMeasurementMode_VZ (void) {
	HAL_Delay(250);
	ISTZ_OFF;
	HAL_Delay(5000);
		measuringVZ();		  
	usSRegHoldBuf[1] = 0;
	ISTZ_ON;
}

void PulseMeasurementMode_VZ (void) {
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