/*
 * timer.h
 *
 * Created: 8/29/2022 2:47:19 PM
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

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/_BIT_MATH.h"
#include "../../Utilities/_REG.h"
#include "../../Utilities/_STD_TYPES_DEFS.h"

typedef struct ST_TIMER_t {
    uint8_t timerSelect;
    uint16_t prescaler;
    uint8_t interrupt_mode;
    void (* callbackFunction) (void);
} ST_TIMER_t;

typedef enum EN_TIMER_ERROR {
    TIMER_OK = 0,
    INVALID_TIMER_SELECT,
    INVALID_PRESCALER
} EN_TIMER_ERROR;

void timer_init(ST_TIMER_t * timer);

void delay_start(uint8_t timer, uint16_t delay_ms, uint16_t prescaler);

void delay_stop(uint8_t timer);

uint16_t get_timer_value(uint8_t timer);

#endif /* TIMER_H_ */
