/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __measuring_vd_vz_H
#define __measuring_vd_vz_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "mode.h"

#include "mb.h"
#include "mbport.h"
#include "user_mb_app.h"

void setConfigADC(uint16_t );
float AverageCalculationADC(void);
//void configurationADC(void);

void MeasuringVD(void);
void MeasuringVZ(void);

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */