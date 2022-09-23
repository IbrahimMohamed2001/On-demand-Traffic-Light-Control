/*
 * led.c
 *
 * Created: 8/28/2022 9:28:11 PM
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

#include "led.h"

EN_LED_ERROR LED_init(uint8_t ledPort, uint8_t ledPin){
	EN_DIO_ERROR error;

	error = DIO_init(ledPort, ledPin, OUTPUT);

	switch (error) {
		case INVALID_PORT: return INVALID_LED_PORT;
		case INVALID_PIN: return INVALID_LED_PIN;
		default: return LED_OK;
	}
}

EN_LED_ERROR LED_ON(uint8_t ledPort, uint8_t ledPin){
	EN_DIO_ERROR error;

	error = DIO_write(ledPort, ledPin, HIGH);

	switch (error) {
		case INVALID_PORT: return INVALID_LED_PORT;
		case INVALID_PIN: return INVALID_LED_PIN;
		default: return LED_OK;
	}
}

EN_LED_ERROR LED_OFF(uint8_t ledPort, uint8_t ledPin){
	EN_DIO_ERROR error;

	error = DIO_write(ledPort, ledPin, LOW);

	switch (error) {
		case INVALID_PORT: return INVALID_LED_PORT;
		case INVALID_PIN: return INVALID_LED_PIN;
		default: return LED_OK;
	}
}

EN_LED_ERROR LED_toggle(uint8_t ledPort, uint8_t ledPin){
	EN_DIO_ERROR error;

	error = DIO_toggle(ledPort, ledPin);

	switch (error) {
		case INVALID_PORT: return INVALID_LED_PORT;
		case INVALID_PIN: return INVALID_LED_PIN;
		default: return LED_OK;
	}
}