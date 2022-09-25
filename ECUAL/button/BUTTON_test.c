/*
 * BUTTON_test.c
 *
 * Created: 25/09/2022 09:53:28 PM
 *  Author: Barhoom Ali
 */

#include "button.h"

void BUTTON_init_test () {
    EN_BUTTON_ERROR error = BUTTON_init(PORTC, PIN7); // the right way 

    //the wrong ways 

    error = BUTTON_init(20, PIN7); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = BUTTON_init(PORTC, 20); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}

void internalPullUp_test () {
    EN_BUTTON_ERROR error = internalPullUp(PORTC, PIN7); // the right way 

    //the wrong ways 

    error = internalPullUp(20, PIN7); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = internalPullUp(PORTC, 20); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}

void BUTTON_read_test () {
    uint8_t valueRead;
    EN_BUTTON_ERROR error = BUTTON_read(PORTC, PIN7, &valueRead); // the right way 

    //the wrong ways 

    error = BUTTON_read(20, PIN7,  &valueRead); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = BUTTON_read(PORTC, 20,  &valueRead); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}
