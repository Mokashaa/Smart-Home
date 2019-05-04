#include "lcd.h"
#include "push_buttons.h"

void pushButtons_Init (void)
{
	Port_Init (PF);
	Port_SetPinDirection (PF, PF_pins_mask, PORT_PIN_IN);
	Port_AnalogOrDigital (PF,PF_pins_mask, Digital);
	Port_AlternateFunction (PF, PF_pins_mask, 0, PCTL_pins_mask);
	Port_SetPinPullUp (PF, PF_pins_mask, 1);
	GPIO_PORTF_IS_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_IBE_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_IEV_R &= ~GPIO_PF4_0_M;
	GPIO_PORTF_ICR_R |= GPIO_PF4_0_M;
	GPIO_PORTF_IM_R |= GPIO_PF4_0_M;
	NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | (GPIO_PF4_0_PRI << 21); // PRI7 bits 23:21
	NVIC_EN0_R |= (1 << 30); // EN0 bit 30
}
