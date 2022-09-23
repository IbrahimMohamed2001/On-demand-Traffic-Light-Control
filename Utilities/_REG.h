/*
 * _REG.h
 *
 * Created: 8/28/2022 2:51:38 PM
 *  Author: Barhoom Ali
 */ 

// ┏┓ ┏┓                      ┏┓                              ┏┓  ┏┓             ┏┓
//┏┛┗┓┃┃                      ┃┃                             ┏┛┗┓┏┛┗┓            ┃┃
//┗┓┏┛┃┗━┓┏┓┏━━┓    ┏━━┓┏━━┓┏━┛┃┏━━┓    ┏┓┏━━┓    ┏┓┏┓┏┓┏━┓┏┓┗┓┏┛┗┓┏┛┏━━┓┏━┓     ┃┗━┓┏┓ ┏┓
// ┃┃ ┃┏┓┃┣┫┃━━┫    ┃┏━┛┃┏┓┃┃┏┓┃┃┏┓┃    ┣┫┃━━┫    ┃┗┛┗┛┃┃┏┛┣┫ ┃┃  ┃┃ ┃┏┓┃┃┏┓┓    ┃┏┓┃┃┃ ┃┃
// ┃┗┓┃┃┃┃┃┃┣━━┃    ┃┗━┓┃┗┛┃┃┗┛┃┃┃━┫    ┃┃┣━━┃    ┗┓┏┓┏┛┃┃ ┃┃ ┃┗┓ ┃┗┓┃┃━┫┃┃┃┃    ┃┗┛┃┃┗━┛┃
// ┗━┛┗┛┗┛┗┛┗━━┛    ┗━━┛┗━━┛┗━━┛┗━━┛    ┗┛┗━━┛     ┗┛┗┛ ┗┛ ┗┛ ┗━┛ ┗━┛┗━━┛┗┛┗┛    ┗━━┛┗━┓┏┛
//                                                                                   ┏━┛┃
//                                                                                   ┗━━┛
// Ibrahim Mohamed Hamdy Hassan

#ifndef _REG_H_
#define _REG_H_

#include "_STD_TYPES_DEFS.h"

//////////////////////////////////////////////////////////////////////////
///////////////////////////////  DIO Part  ///////////////////////////////
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                            Group A Registers                         */
/************************************************************************/

#define PORTA_Reg AT_ADDRESS_OF(0x3B) // Data Register - PORTA

#define DDRA_Reg AT_ADDRESS_OF(0x3A) // Data Direction Register A

#define PINA_Reg AT_ADDRESS_OF(0x39) // Input Pins Address Register - PINA

/************************************************************************/
/*                            Group B Registers                         */
/************************************************************************/

#define PORTB_Reg AT_ADDRESS_OF(0x38) // Data Register - PORTB

#define DDRB_Reg AT_ADDRESS_OF(0x37) // Data Direction Register B

#define PINB_Reg AT_ADDRESS_OF(0x36) // Input Pins Address Register - PINB

/************************************************************************/
/*                            Group C Registers                         */
/************************************************************************/

#define PORTC_Reg AT_ADDRESS_OF(0x35) // Data Register - PORTC

#define DDRC_Reg AT_ADDRESS_OF(0x34) // Data Direction Register C

#define PINC_Reg AT_ADDRESS_OF(0x33) // Input Pins Address Register - PINC

/************************************************************************/
/*                            Group D Registers                         */
/************************************************************************/

#define PORTD_Reg AT_ADDRESS_OF(0x32) // Data Register - PORTD

#define DDRD_Reg AT_ADDRESS_OF(0x31) // Data Direction Register D

#define PIND_Reg AT_ADDRESS_OF(0x30) // Input Pins Address Register - PIND

//////////////////////////////////////////////////////////////////////////
//////////////////////////////  Timers Part //////////////////////////////
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                            Timers Registers                         */
/************************************************************************/

#define TIFR_Reg AT_ADDRESS_OF(0x58) // Timer/Counter Interrupt Flag Register

#define TIMSK_Reg AT_ADDRESS_OF(0x59) // Timer/Counter Interrupt Mask Register

/************************************************************************/
/*                            Timer 0 Registers                         */
/************************************************************************/

#define TCCR0_Reg AT_ADDRESS_OF(0x53) // Timer0/Counter0 Control Register

#define TCNT0_Reg AT_ADDRESS_OF(0x52) // Timer0/Counter0 Register 

#define OCR0_Reg AT_ADDRESS_OF(0x5C) // Output Compare Register

/************************************************************************/
/*                            Timer 1 Registers                         */
/************************************************************************/

#define TCCR1A_Reg AT_ADDRESS_OF(0x4F) // Timer1/Counter1 Control Register A
#define TCCR1B_Reg AT_ADDRESS_OF(0x4E) // Timer1/Counter1 Control Register B

#define TCNT1H_Reg AT_ADDRESS_OF(0x4D) // Timer1/Counter1 Register HIGH Bytes
#define TCNT1L_Reg AT_ADDRESS_OF(0x4C) // Timer1/Counter1 Register LOW Bytes

#define OCR1AH_Reg AT_ADDRESS_OF(0x4B) // Output Compare Register A HIGH Bytes
#define OCR1AL_Reg AT_ADDRESS_OF(0x4A) // Output Compare Register A LOW Bytes

#define OCR1BH_Reg AT_ADDRESS_OF(0x49) // Output Compare Register B HIGH Bytes
#define OCR1BL_Reg AT_ADDRESS_OF(0x48) // Output Compare Register B LOW Bytes

/************************************************************************/
/*                            Timer 2 Registers                         */
/************************************************************************/

#define TCCR2_Reg AT_ADDRESS_OF(0x45) // Timer2/Counter2 Control Register

#define TCNT2_Reg AT_ADDRESS_OF(0x44) // Timer2/Counter2 Register

#define OCR2_Reg AT_ADDRESS_OF(0x43) // Output Compare Register

//////////////////////////////////////////////////////////////////////////
////////////////////////////  Interrupts Part ////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define SREG_Reg AT_ADDRESS_OF(0x5F) // Status Register

#define GICR_Reg AT_ADDRESS_OF(0x5B) // General Interrupt Control Register

#define GIFR_Reg AT_ADDRESS_OF(0x5A) // General Interrupt Flag Register

#define MCUCR_Reg AT_ADDRESS_OF(0x55) // MCU Control Register

#define MCUCSR_Reg AT_ADDRESS_OF(0x54) // MCU Control and Status Register

#endif /* _REG_H_ */