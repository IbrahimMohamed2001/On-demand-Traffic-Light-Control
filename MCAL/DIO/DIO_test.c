/*
 * DIO_test.c
 *
 * Created: 25/09/2022 09:53:28 PM
 *  Author: Barhoom Ali
 */ 

#include "DIO.h"

void DIO_init_test () {
    EN_DIO_ERROR error = DIO_init(PORTA, PIN0, OUTPUT); // the right way

    // the wrong ways

    error = DIO_init(10, PIN0, OUTPUT); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = DIO_init(PORTA, 10, OUTPUT); // pins exceeds limits [PIN0, PIN1, ... PIN7]

    error = DIO_init(PORTA, PIN0, 10); // wrong direction options [INPUT, OUTPUT]
}

void DIO_write_test () {
    EN_DIO_ERROR error = DIO_write(PORTA, PIN0, HIGH); // the right way

    // the wrong ways

    error = DIO_write(10, PIN0, HIGH); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = DIO_write(PORTA, 10, HIGH); // pins exceeds limits [PIN0, PIN1, ... PIN7]

    error = DIO_write(PORTA, PIN0, 10); // wrong value options [HIGH, LOW]
}

void DIO_read_test () {
    uint8_t valueRead;
    EN_DIO_ERROR error = DIO_read(PORTA, PIN0, &valueRead); // the right way

    // the wrong ways

    error = DIO_read(10, PIN0, &valueRead); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = DIO_read(PORTA, 10, &valueRead); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}
 
void DIO_toggle_test () {
    EN_DIO_ERROR error = DIO_toggle(PORTA, PIN0); // the right way

    // the wrong ways

    error = DIO_toggle(10, PIN0); // port exceeds limits [PORTA, PORTB, PORTC, PORTD]

    error = DIO_toggle(PORTA, 10); // pins exceeds limits [PIN0, PIN1, ... PIN7]
}
 