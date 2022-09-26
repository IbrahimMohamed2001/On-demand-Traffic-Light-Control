/*
 * TIMERS_test.c
 *
 * Created: 25/09/2022 09:53:28 PM
 *  Author: Barhoom Ali
 */ 

#include "timer.h"

extern uint16_t sw_n_overflow;

void TIMER_INT_fun () {
    // some stuff
}

void STOPWATCH_INT_fun () {
    // some stuff
}

void timer_init_test () {
    ST_TIMER_t timer = {.timerSelect = TIMER0, .prescaler = NO_PRESCALER, .interrupt_mode = NONE, .callbackFunction = NULLPTR};
    EN_TIMER_ERROR error = timer_init(& timer); // the right way

    // the wrong ways

    timer.timerSelect = 30;
    error = timer_init(& timer); // timerSelect exceeds limits [TIMER0, TIMER1, TIMER2]

    timer.interrupt_mode = 13;
    error = timer_init(& timer); // interrupt_mode exceeds limits [OVF_MODE, CMP_MODE, NONE]

}

void delay_start_test () {
    EN_TIMER_ERROR error = delay_start(TIMER2, 1500, NO_PRESCALER); // the right way

    // the wrong ways

    error = delay_start(43, 1500, NO_PRESCALER); // timer select exceeds limits [TIMER0, TIMER1, TIMER2]

    error = delay_start(TIMER2, 1500, PRESCALER_128); // wrong prescaler option

    error = delay_start(TIMER2, 1500, 11); // wrong prescaler option

    // prescaler valid options for TIMERS [NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024]
    // prescaler valid options for ADC [NO_PESCALER, PRESCALER_2, PRESCALER_4, PRESCALER_8, PRESCALER_16, PRESCALER_32, PRESCALER_64, PRESCALER_128]
}

void delay_stop_test () {
    EN_TIMER_ERROR error = delay_stop(TIMER0); // the right way

    // the wrong way

    error = delay_stop(23); // timer select exceeds the limits [TIMER0, TIMER1, TIMER2]
}

void stopwatch_start_test () {
    ST_TIMER_t timer = {.timerSelect = TIMER0, .prescaler = NO_PRESCALER, .interrupt_mode = NONE, .callbackFunction = NULLPTR};
    EN_TIMER_ERROR error = stopwatch_start(& timer); // the right way

    // the wrong ways

    timer.timerSelect = 17; // timerSelect exceeds limits [TIMER0, TIMER1, TIMER2]
    error = stopwatch_start(& timer); 

    timer.prescaler = PRESCALER_32; // wrong prescaler option
    error = stopwatch_start(& timer);

    timer.prescaler = 44; // wrong prescaler option
    error = stopwatch_start(& timer);

    // prescaler valid options for TIMERS [NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024]
    // prescaler valid options for ADC [NO_PESCALER, PRESCALER_2, PRESCALER_4, PRESCALER_8, PRESCALER_16, PRESCALER_32, PRESCALER_64, PRESCALER_128]
}

void stopwatch_stop_test () {
    uint16_t valueRead;
    ST_TIMER_t timer = {.timerSelect = TIMER0, .prescaler = NO_PRESCALER, .interrupt_mode = NONE, .callbackFunction = NULLPTR};
    EN_TIMER_ERROR error = stopwatch_stop(& timer, & valueRead); // the right way

    // the wrong way

    timer.timerSelect = 13; // timerSelect exceeds limits [TIMER0, TIMER1, TIMER2]
    error = stopwatch_stop(& timer, & valueRead); 

}
