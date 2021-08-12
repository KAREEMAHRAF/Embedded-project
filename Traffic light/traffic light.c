/*
 * traffic_light.c
 *
 * Created: 8/6/2021 10:45:43 AM
 *  Author: kareem ashraf
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "Timer2.h"
#include "STD_MACROS.h"
#include "STD_TYPE.h"

volatile uint8_t second = 0 ;
      
int main(void)
{
	timer2_normal_init();
	LCD_INIT();
    LCD_CMD(0x81);
    LCD_STRING("sttttttoooooop");
	LCD_CMD(0x0E);
	LCD_CMD(0x0c);

    while(1)
    {
		 	
		SET_BIT(DDRD,7);
		SET_BIT(DDRD,6);
		SET_BIT(DDRD,5);
		
		
		LCD_CMD(0xC0);
		LCD_NUMBER(second);
	
        //TODO:: Please write your application code 
	   
		
		if (second==10)
		{
			SET_BIT(PORTD,7);
			
			LCD_CMD(0x01);
			_delay_ms(20);
			LCD_CMD(0x85);
			LCD_STRING("GREEN");
			
			LCD_CMD(0xC0);
			LCD_NUMBER(second);
		
			 
			 
			CLE_BIT(PORTD,6);
			CLE_BIT(PORTD,5);
		}
		else if (second==20)
		{
			SET_BIT(PORTD,6);
			
			LCD_CMD(0x01);
			_delay_ms(10);
			LCD_CMD(0x85);
			LCD_STRING("YELLOW");
		
			
			LCD_CMD(0XC0);
			LCD_NUMBER(second);
		
			CLE_BIT(PORTD,7);
			CLE_BIT(PORTD,5);
		}
		else if (second==30)
		{
			SET_BIT(PORTD,5);
		    LCD_CMD(0x01);
		    _delay_ms(10);
			
		
		
			LCD_CMD(0XC0);
			LCD_NUMBER(second);
			
			CLE_BIT(PORTD,7);
			CLE_BIT(PORTD,6);
			LCD_CMD(0x01);
			_delay_ms(10);
			second = 0 ;
			LCD_CMD(0x85);
			LCD_STRING("RED");
		}
		else
		{
			
		}
					
    }
}

ISR(TIMER2_OVF_vect)
{
	    static uint32_t count =0 ;
     	count ++ ;
	 	if(count==62745)
	 	{
			    
			    second ++ ; 	 		
		 		count = 0 ;
	 	}
}