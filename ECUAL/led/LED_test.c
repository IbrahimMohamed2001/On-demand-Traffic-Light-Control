/*
 * LED_test.c
 *
 * Created: 25/09/2022 09:53:28 PM
 *  Author: Barhoom Ali
 */ 

#include "led.h"

void LED_init_test () {
    EN_LED_ERROR error = LED_init(PORTB, PIN3); // the right way

    // the wrong ways

    error = LED_init(12, PIN3); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = LED_init(PORTB, 12); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}

void LED_ON_test () {
    EN_LED_ERROR error = LED_ON(PORTB, PIN3); // the right way

    // the wrong ways

    error = LED_ON(12, PIN3); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = LED_ON(PORTB, 12); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}

void LED_OFF_test () {
    EN_LED_ERROR error = LED_OFF(); // the right way

    // the wrong ways

    error = LED_OFF(12, PIN3); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = LED_OFF(PORTB, 12); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}

void LED_toggle_test () {
    EN_LED_ERROR error = LED_toggle(); // the right way

    // the wrong ways

    error = LED_toggle(12, PIN3); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = LED_toggle(PORTB, 12); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}
