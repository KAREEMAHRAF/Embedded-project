/*
 * Timer2.h
 *
 * Created: 7/26/2020 3:34:59 PM
 *  Author: kareem ashraf
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_
#include "std_macros.h"


void timer2_normal_init();
void timer2_normal_prescaler_inint();

void timer2_compare_inint();
void timer2_compare_prescaler_inint();

void timer2_frequnce_inint();


void timer2_PWM_inint();
void timer2_duty(uint8_t duty);

	


#endif /* TIMER2_H_ */