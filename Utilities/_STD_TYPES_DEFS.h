/*
 * _STD_TYPES_DEFS.h
 *
 * Created: 8/28/2022 3:33:41 PM
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

#ifndef _STD_TYPES_DEFS_H_
#define _STD_TYPES_DEFS_H_

//////////////////////////////////////////////////////////////////////////
///////////  Note: All these defs can be defined as enums,     ///////////
///////////  but enums will consume more memory and more time, ///////////
///////////  Although, defs will consume more program size,    ///////////
///////////  but it is more efficient                          ///////////
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///////////////////////////////  STD Types  //////////////////////////////
//////////////////////////////////////////////////////////////////////////

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short int uint16_t;
typedef signed short int int16_t;
typedef unsigned long int uint32_t;
typedef signed long int int32_t;
typedef unsigned long long int uint64_t;
typedef signed long long int int64_t;

/* Boolean Data Type */

typedef unsigned char bool;

/* Boolean Values */

#define FALSE 0
#define TRUE 1
#define NULLPTR ((void*)0)

//////////////////////////////////////////////////////////////////////////
///////////////////////////////  DIO Part  ///////////////////////////////
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                           Registers Define                           */
/************************************************************************/

#define AT_ADDRESS_OF(ADDRESS) *((volatile uint8_t*)(ADDRESS))

/************************************************************************/
/*                             Port Defines                             */
/************************************************************************/

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/************************************************************************/
/*                              PIN Defines                             */
/************************************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/************************************************************************/
/*                            PIN Directions                            */
/************************************************************************/

#define INPUT 0
#define OUTPUT 1

/************************************************************************/
/*                           PIN Value Options                          */
/************************************************************************/

#define HIGH 1
#define LOW 0

//////////////////////////////////////////////////////////////////////////
//////////////////////////////  Timers Part //////////////////////////////
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                               F_CPU Def                              */
/************************************************************************/

#define F_CPU 1000000UL

/************************************************************************/
/*                            Timers Defines                            */
/************************************************************************/

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

/************************************************************************/
/*                          Timers INT Options                          */
/************************************************************************/

#define OVF_MODE 0
#define CMP_MODE 1
#define NONE 3

/************************************************************************/
/*                       Prescaler Value Options                        */
/************************************************************************/

#define NO_PRESCALER 1
#define PRESCALER_2 2
#define PRESCALER_4 4
#define PRESCALER_8 8
#define PRESCALER_16 16
#define PRESCALER_32 32
#define PRESCALER_64 64
#define PRESCALER_128 128
#define PRESCALER_256 256
#define PRESCALER_1024 1024

//////////////////////////////////////////////////////////////////////////
///////////////////////////// Interrupts Part ////////////////////////////
//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                          Interrupts Defines                          */
/************************************************************************/

#define INTERRUPT0 0
#define INTERRUPT1 1
#define INTERRUPT2 2

/************************************************************************/
/*                       Interrupts Sense Control                       */
/************************************************************************/

#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

/************************************************************************/
/*                              IVT Defines                             */
/************************************************************************/

/* External Interrupt Request 0 */
#define INT0_vect __vector_1

/* External Interrupt Request 1 */
#define INT1_vect __vector_2

/* External Interrupt Request 2 */
#define INT2_vect __vector_3

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect __vector_4

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect	__vector_5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect __vector_6

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect __vector_7

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect __vector_8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect	__vector_9

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect __vector_10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect __vector_11

/* Serial Transfer Complete */
#define SPI_STC_vect __vector_12

/* USART, Rx Complete */
#define USART_RXC_vect __vector_13

/* USART Data Register Empty */
#define USART_UDRE_vect __vector_14

/* USART, Tx Complete */
#define USART_TXC_vect __vector_15

/* ADC Conversion Complete */
#define ADC_vect __vector_16

/* EEPROM Ready */
#define EEPROM_READY_vect __vector_17

/* Analog Comparator */
#define ANALOG_COMP_vect __vector_18

/* 2-wire Serial Interface */
#define TWI_vect __vector_19

/* Store Program Memory Ready */
#define SPM_READY_vect __vector_20

/************************************************************************/
/*                          ISR function Define                         */
/************************************************************************/

#define ISR(INT_VECT, ...)\
void INT_VECT (void) __attribute__ ((signal, used)) __VA_ARGS__; \
void INT_VECT (void)

/************************************************************************/
/*                   Global Interrupt Enable / Disable                  */
/************************************************************************/

#define sei()  __asm__ __volatile__ ("sei" ::: "memory")

#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#endif /* _STD_TYPES_DEFS_H_ */