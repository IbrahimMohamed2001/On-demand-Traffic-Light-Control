/*
 * _DIO.c
 *
 * Created: 8/28/2022 3:22:05 PM
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

#include "DIO.h"

EN_DIO_ERROR DIO_init(uint8_t port, uint8_t pin, uint8_t direction){
	/* Make sure that the Pin is in the valid range */
	if (pin <= PIN7) {
		if (direction == OUTPUT) {
			/* Check on the Required PORT Number */
			switch (port) {
				case PORTA: SET_BIT(DDRA_Reg, pin); break;
				case PORTB: SET_BIT(DDRB_Reg, pin); break;
				case PORTC: SET_BIT(DDRC_Reg, pin); break;
				case PORTD: SET_BIT(DDRD_Reg, pin); break;
				default: return INVALID_PORT;
			}
		} else if (direction == INPUT) {
			/* Check on the Required PORT Number */
			switch (port) {
				case PORTA: CLR_BIT(DDRA_Reg, pin); break;
				case PORTB: CLR_BIT(DDRB_Reg, pin); break;
				case PORTC: CLR_BIT(DDRC_Reg, pin); break;
				case PORTD: CLR_BIT(DDRD_Reg, pin); break;
				default: return INVALID_PORT;
			}
		} else return INVALID_DIR;
	} else return INVALID_PIN;

	return DIO_OK;
}

EN_DIO_ERROR DIO_write(uint8_t port, uint8_t pin, uint8_t value){
	/* Make sure that the Pin is in the valid range */
	if (pin <= PIN7) {
		if (value == HIGH) {
			/* Check on the Required PORT Number */
			switch (port) {
				case PORTA: SET_BIT(PORTA_Reg, pin); break;
				case PORTB: SET_BIT(PORTB_Reg, pin); break;
				case PORTC: SET_BIT(PORTC_Reg, pin); break;
				case PORTD: SET_BIT(PORTD_Reg, pin); break;
				default: return INVALID_PORT;

			}	
		} else if (value == LOW) {
			/* Check on the Required PORT Number */
			switch (port) {
				case PORTA: CLR_BIT(PORTA_Reg, pin); break;
				case PORTB: CLR_BIT(PORTB_Reg, pin); break;
				case PORTC: CLR_BIT(PORTC_Reg, pin); break;
				case PORTD: CLR_BIT(PORTD_Reg, pin); break;
				default: return INVALID_PORT;
			}
		} else return INVALID_VALUE;
	} else return INVALID_PIN;

	return DIO_OK;
}

EN_DIO_ERROR DIO_toggle(uint8_t port, uint8_t pin){
	/* Make sure that the Pin is in the valid range */
	if (pin <= PIN7){
		/* Check on the Required PORT Number */
		switch(port){
			case PORTA: TOG_BIT(PORTA_Reg, pin); break;
			case PORTB: TOG_BIT(PORTB_Reg, pin); break;
			case PORTC: TOG_BIT(PORTC_Reg, pin); break;
			case PORTD: TOG_BIT(PORTD_Reg, pin); break;
			default: return INVALID_PORT;
		}
	} else return INVALID_PIN;

	return DIO_OK;
}

EN_DIO_ERROR DIO_read(uint8_t port, uint8_t pin, uint8_t * valueRead){
	
	/* Make sure that the Port and Pin are in the valid range */
	if (pin <= PIN7){
		/* Check on the Required PORT Number */
		switch(port){
			case PORTA: *valueRead = READ_BIT(PINA_Reg, pin); break;
			case PORTB: *valueRead = READ_BIT(PINB_Reg, pin); break;
			case PORTC: *valueRead = READ_BIT(PINC_Reg, pin); break;
			case PORTD: *valueRead = READ_BIT(PIND_Reg, pin); break;
			default: return INVALID_PORT;
		}
	} else return INVALID_PIN; // wrong Port or Pin

	return DIO_OK;
}