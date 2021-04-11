#ifndef __FunctionsTxRx_H
#define __FunctionsTxRx_H
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

// #include "mb.h"
// #include "mbport.h"
// #include "user_mb_app.h"

float dataReception(int registr);
void dataTransfer(int registr, float out);

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */