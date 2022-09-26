/*
 * INTERRUPT_test.c
 *
 * Created: 25/09/2022 09:53:28 PM
 *  Author: Barhoom Ali
 */ 

#include "interrupt.h"

void EXT_INT_fun () {
    // some stuff
}

void EXT_INT_init_test () {
    ST_EXT_INT_t interrupt = {.interruptPinSelect = INTERRUPT0, .senseControl = RISING_EDGE, & EXT_INT_fun};
    EN_INTERRUPT_ERROR error = EXT_INT_init(& interrupt); // the right way

    // the wrong ways 

    interrupt.interruptPinSelect = 16; // interruptPinSelect exceeds the limits [INTERRUPT0, INTERRUPT1, INTERRUPT2]
    error = EXT_INT_init(& interrupt);

    interrupt.senseControl = 14;  // senseControl exceeds the limits [RISING_EDGE, FALLING_EDGE, LOW_LEVEL, ANY_LOGICAL_CHANGE]
    error = EXT_INT_init(& interrupt);
}