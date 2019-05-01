#include "adc.h"


void ADC0_SS3_Init (void)
{
	SYSCTL_RCGCADC_R |= (1<<0);			//enable ADC0 clock
	ADC0_ACTSS_R &= ~(1<<SS_num);				//disable sample sequncer during configuration
	ADC0_EMUX_R = (ADC0_EMUX_R& ~(0xF<<SS_num*4)) | (trigger_select<<SS_num*4) ; //choosing the triggering method
	ADC0_SSMUX3_R = 0x0;
	ADC0_SSCTL3_R |= ( (ADC0_SSCTL3_TS0<<3) | (ADC0_SSCTL3_IE0<<2) | (ADC0_SSCTL3_END0<<1));  //configuring sample sequncer 3 control port
	ADC0_ACTSS_R |= (1<<SS_num);				//enable sample sequncer during configuration
}