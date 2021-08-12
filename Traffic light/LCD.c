/*
 * LCD.c
 *
 * Created: 12/11/2020 6:01:00 PM
 *  Author: kareem ashraf
 */ 
#include "LCD.h"



void LCD_INIT(void)
{

	DDR_PORTA;
	DDR_PORTB;
    
    LCD_CMD(0x3);
    LCD_CMD(0x2);
    LCD_CMD(0x28);
    LCD_CMD(0x08);
    LCD_CMD(0x01);
    LCD_CMD(0x06);
    LCD_CMD(0x0c);	 
    _delay_ms(20);
	
}
void LCD_CMD(uint8_t cmd)
{
	RS(0);
	//RW(0);
	
    PIN4 (READ_BIT(cmd,4));
	PIN5 (READ_BIT(cmd,5));
	PIN6 (READ_BIT(cmd,6));
	PIN7 (READ_BIT(cmd,7));
	
	EN(1);
	_delay_ms(2);
	EN(0);
	
	PIN4 (READ_BIT(cmd,0));
	PIN5 (READ_BIT(cmd,1));
	PIN6 (READ_BIT(cmd,2));
	PIN7 (READ_BIT(cmd,3));
	
	EN(1);
	_delay_ms(2);
	EN(0);
}
void LCD_CHAR(uint8_t data)
{
	RS(1);
	
	   PIN4 (READ_BIT(data,4));
	   PIN5 (READ_BIT(data,5));
	   PIN6 (READ_BIT(data,6));
	   PIN7 (READ_BIT(data,7));
	   
	   EN(1);
	   _delay_ms(2);
	   EN(0);
	   
	   PIN4 (READ_BIT(data,0));
	   PIN5 (READ_BIT(data,1));
	   PIN6 (READ_BIT(data,2));
	   PIN7 (READ_BIT(data,3));
	   
	   EN(1);
	   _delay_ms(2);
	   EN(0);

}
void LCD_STRING(uint8_t data[])    //"kareem\0"
{
	
    for(int i=0 ; data[i]!= '\0' ;i++)
	{
	     LCD_CHAR(data[i]);
	
	}
}
void LCD_NUMBER(uint32_t number)
   {
        uint8_t txt[10] = {0};
        int8_t i = 0;
        if(number == 0) {
        	LCD_CHAR('0');
        	return;
        }
        for (i = 0; number != 0; i++ )
        {
        	txt[i] = number%10 + 48;
        	number = number  / 10 ;
        }
        i--;
        while(i >= 0){
        	LCD_CHAR(txt[i]);
        	i--;
    }
}


