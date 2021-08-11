/*
 * STD_MACROS.h
 *
 * Created: 12/11/2020 6:01:39 PM
 *  Author: kareem ashraf
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>
#define CPU = 16000000ul



#define  SET_BIT(PORT,PIN) (PORT |= (1<<PIN))
#define  CLE_BIT(PORT,PIN) (PORT &= ~ (1<<PIN))
#define  TOG_BIT(PORT,PIN) (PORT ^= (1<<PIN))
#define  READ_BIT(PORT,PIN)((PORT>>PIN) &1 )
                                                           



#endif /* STD_MACROS_H_ */