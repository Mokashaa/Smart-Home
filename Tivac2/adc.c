#include "adc.h"


void ADC0_SS3_Init (void)
{
	SYSCTL_RCGCADC_R |= (1<<0);			//enable ADC0 clock
	ADC0_ACTSS_R &= ~(1<<SS_num);				//disable sample sequncer during configuration
	ADC0_EMUX_R = (ADC0_EMUX_R& ~(0xF<<SS_num*4)) | (trigger_select<<SS_num*4) ; //choosing the triggering method
	ADC0_SSMUX3_R = 0x0;					//input from channel 0 i.e PE3
	ADC0_SSCTL3_R |= ( (ADC0_SSCTL3_TS0<<3) | (ADC0_SSCTL3_IE0<<2) | (ADC0_SSCTL3_END0<<1));  //configuring sample sequncer 3 control port
	if(ADC0_SSCTL3_IE0	==	0x1)
	{
		ADC0_IM_R |= (1<<3);
		NVIC_EN0_R |= (1<<17);
	}
	ADC0_ACTSS_R |= (1<<SS_num);				//enable sample sequncer during configuration
}
void ADC_Init_Potentiometer (void)
{
ADC0_SS3_Init ();
Port_AnalogOrDigital (PORTE, 0X08, 0);
//Port_AlternateFunction (PORTE,0X08,1, uint32_t pctl_mask);
GPIO_PORTE_AFSEL_R|=0x08;


}