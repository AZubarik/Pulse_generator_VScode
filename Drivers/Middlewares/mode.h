#ifndef __mode_H
#define __mode_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#include "mb.h"
#include "mbport.h"
#include "user_mb_app.h"

#include "measuring_vd_vz.h"

extern uint16_t usSRegInBuf[];
extern uint16_t usSRegHoldBuf[];

int id30min, id30max, iz30min, iz30max;
	
int eventVD, eventVZ, eventDiagnostic;	

void WaitingMode (void);

void StaticMeasurementMode_VD (void);
void StaticMeasurementMode_VZ (void);

void PulseMeasurementMode_VD (void);
void PulseMeasurementMode_VZ (void);
	
void diagnostic (void);

#ifdef __cplusplus
}
#endif
#endif 