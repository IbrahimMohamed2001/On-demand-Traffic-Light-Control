/*
 * button.c
 *
 * Created: 8/28/2022 9:42:09 PM
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

#include "button.h"

EN_BUTTON_ERROR BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	EN_DIO_ERROR error;

	error = DIO_init(buttonPort, buttonPin, INPUT);

	switch (error) {
		case INVALID_PORT: return INVALID_BUTTON_PORT;
		case INVALID_PIN: return  INVALID_BUTTON_PIN;
		default: return BUTTON_OK;
	}
}

EN_BUTTON_ERROR BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t * buttonState){
	EN_DIO_ERROR error;

	error = DIO_read(buttonPort, buttonPin, buttonState);

	switch (error) {
		case INVALID_PORT: return INVALID_BUTTON_PORT;
		case INVALID_PIN: return  INVALID_BUTTON_PIN;
		default: return BUTTON_OK;
	}
}

EN_BUTTON_ERROR internalPullUp(uint8_t buttonPort, uint8_t buttonPin){
	EN_DIO_ERROR error;

	error = DIO_write(buttonPort, buttonPin, HIGH);

	switch (error) {
		case INVALID_PORT: return INVALID_BUTTON_PORT;
		case INVALID_PIN: return  INVALID_BUTTON_PIN;
		default: return BUTTON_OK;
	}
}
