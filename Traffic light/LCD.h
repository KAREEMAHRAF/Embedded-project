/*
 * LCD.h
 *
 * Created: 12/11/2020 6:01:17 PM
 *  Author: kareem ashraf
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD_MACROS.h"
#define DDR_PORTA  DDRA |=0b11110000 
#define DDR_PORTB  DDRB |=0b00001110 



#define RS(X) if(X==0)CLE_BIT(PORTB,1); else SET_BIT(PORTB,1);
#define EN(X) if(X==0)CLE_BIT(PORTB,3); else SET_BIT(PORTB,3);
#define RW(X) if(X==0)CLE_BIT(PORTB,2); else SET_BIT(PORTB,2);

#define PIN4(X) if(X==0)CLE_BIT(PORTA,4); else SET_BIT(PORTA,4);
#define PIN5(X) if(X==0)CLE_BIT(PORTA,5); else SET_BIT(PORTA,5);
#define PIN6(X) if(X==0)CLE_BIT(PORTA,6); else SET_BIT(PORTA,6);
#define PIN7(X) if(X==0)CLE_BIT(PORTA,7); else SET_BIT(PORTA,7);

 
// init
//write command
//write char
//write string
//write number

void LCD_INIT(void);
void LCD_CMD(uint8_t );
void LCD_CHAR(uint8_t data);
void LCD_STRING(uint8_t data[]);
void LCD_NUMBER(uint32_t number);



#endif /* LCD_H_ */