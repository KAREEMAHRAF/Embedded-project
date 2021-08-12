/*
 * Timer2.c
 *
 * Created: 7/26/2020 3:34:38 PM
 *  Author: kareem ashraf
 */ 

//normal mode 
#include "Timer2.h"
void timer2_normal_init()
{
    TCCR2 |= 1<<FOC2 | 1<<CS20 ;
	TIMSK |= 1<<TOIE2 ;
	sei();
}
void  timer2_normal_prescaler_inint()
{
	 TCCR2 |= 1<<FOC2 | 1<<CS20 | 1<<CS22 | 1<<CS21;
	 TIMSK |= 1<<TOIE2 ;
	 sei();
}

void timer2_compare_inint()
{
	TCCR2 |=1<<FOC2 | 1<<WGM21 |1<<CS20 ;
	TIMSK |= 1<< OCIE2 ;
	OCR2 = 250 ;
	sei();
}
void timer2_compare_prescaler_inint()
{
	TCCR2  |=1<<FOC2 | 1<<WGM21  | 1<<CS20 | 1<<CS22 | 1<<CS21;
	TIMSK  |= 1<<OCIE2;
	OCR2 = 250 ;
	sei();
	
}

void timer2_frequnce_inint()
{
	TCCR2 |= 1<<FOC0 | 1<<CS20 | 1<<WGM21 | 1<<COM20  ;
	OCR2 = 250 ;
	
	SET_BIT(DDRD,7);
	
	
}

void timer2_PWM_inint()
{
	TCCR2 |= 1<<CS20 | 1<<WGM20 | 1<<COM20 | 1<<COM21 | 1<<WGM21;
	SET_BIT(DDRD,7);
}

void timer2_duty(uint8_t duty)
{
	OCR2= duty * 2.55;
}


