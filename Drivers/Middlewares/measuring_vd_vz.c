#include "measuring_vd_vz.h"
    // Setting the ADC(AD7682) and gain of operational amplifiers(AD8273)
uint16_t AD7682_IN0 = 0x3C49 << 2,          // 0x3C49   // 0x3849
         AD7682_IN1 = 0x3CC9 << 2,          // 0x3CC9   // 0x38C9
         AD7682_IN2 = 0x3D49 << 2,          // 0x3D49   // 0x3949
         AD7682_IN3 = 0x3DC9 << 2;          // 0x3DC9   // 0x39C9   
                    
float   IDOUT = 0.5,                        // coef usilenia po toky
	    IZOUT = 0.5,  
	    deltaADC = 0.0000625,               // delta ADC
	    Resistor = 0.25;                    // tokovi resistor dla zener diod R = 4 Om

int   UDOUT = 2,                            // coef usilenia po napryazheniyu
      UZOUT = 2;

float currentADC_vd, voltageADC_vd, currentADC_vz, voltageADC_vz;
int AverageADC;
uint16_t out;
uint16_t MassifADC[16];

uint16_t* tmp = 0;

extern uint16_t usSRegInBuf[];

void setConfigADC (uint16_t value) {
    for (int i = 0; i < 16; i++) {
        CNV_OFF;
	    HAL_Delay(2);
        HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&value, (uint8_t*)&out, 1, 10);
        HAL_Delay(2);	
        CNV_ON;
        
        MassifADC[i] = out;
        AverageCalculationADC();
    }
}

float AverageCalculationADC (void) {
    AverageADC = 0;
        for (int j = 4; j < 16; j++) {
            AverageADC += MassifADC[j];
        }
    return out = AverageADC / 12;
}

void dataTransferADC(int registr, float out) {
	tmp = (uint16_t*) &out;
    usSRegInBuf[registr] = *tmp;
    usSRegInBuf[registr + 1] = *(tmp + 1);
}

void measuringVD(void) { 
    setConfigADC(AD7682_IN3);
    voltageADC_vd = out * deltaADC  * UDOUT;
    dataTransferADC(0, voltageADC_vd);
    
    setConfigADC(AD7682_IN2);  
    currentADC_vd = out * deltaADC * IDOUT; 
    dataTransferADC(2, currentADC_vd);
}

void measuringVZ(void) {
    setConfigADC(AD7682_IN1);
    voltageADC_vz = out * deltaADC * UZOUT;
    dataTransferADC(4, voltageADC_vz);

    setConfigADC(AD7682_IN0); 
    currentADC_vz = out * deltaADC * IZOUT * Resistor;  
    dataTransferADC(6, currentADC_vz);
}