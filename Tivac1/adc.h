#ifndef ADC_H_
#define ADC_H_

#include "port.h"
#include "DIO.h"


#define trigger_select 0x0F
#define SS_num 3
#define ADC0_SSCTL3_IE0		0x1
#define ADC0_SSCTL3_END0	0x1
#define ADC0_SSCTL3_TS0   0x1


void ADC0_SS3_Init (void);

#endif