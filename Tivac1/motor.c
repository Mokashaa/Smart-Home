#include "motor.h"
const char steps[ ] = {0x9, 0x3, 0x6, 0xC};
int cnt =8;
void Motor_Clockwise (void)
{
	
}

void Motor_AntiClockwise (void)
{// assume step angle =5 degree
	// (30 degree/ angle for one step)
 for (int i=0;i<6;i++)
  {
   GPIO_PORTB_DATA_R &= ~ 0xF;
   GPIO_PORTB_DATA_R |= steps[cnt-- & 3];
   delay(10);
  }
}
