#include "lcd.h"

void LCD_IntegerToString ( uint16_t data, char* str) 
{ 	uint8_t temp;
	uint8_t start;
    uint8_t end;
    int i = 0;  
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (data == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
    } 
  
    // Process individual digits 
    while (data != 0) 
    { 
        uint16_t rem = data % 10; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        data = data/10; 
    } 
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
		start = 0; 
    end = i -1; 
		
    while (start < end) 
    { 
			temp = *(str+start);
			*(str+start) = *(str+end);
			*(str+end) = temp;
			
		    start++; 
      end--; 
    }
} 

void LCD_Init (void)
{
	//initiallizing data port and control port and setting their pins as output
	Port_Init(LCD_CTRL_PORT);
	Port_Init(LCD_DATA_PORT);
	Port_SetPinDirection(LCD_CTRL_PORT,RS,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,RW,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_CTRL_PORT,E,PORT_PIN_OUT);
	Port_SetPinDirection(LCD_DATA_PORT,0xFF,PORT_PIN_OUT);
	//setting lcd to operate in two lines eight bits mode
	LCD_SendCommand(TwoLineEightBitMode);
	LCD_SendCommand(Cursor_Off);
	LCD_SendCommand(Clear_Command);
}