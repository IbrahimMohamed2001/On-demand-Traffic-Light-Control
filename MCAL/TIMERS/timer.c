/*
 * timer.c
 *
 * Created: 8/29/2022 2:47:38 PM
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

#include "timer.h"
#include <math.h>

bool timer_flag = TRUE; // global flag for the timer
uint16_t sw_n_overflow = 0; // global counter for stopwatch timer counting number of overflows

static void (* T0_OVF_PTR_TO_FUN) (void) = NULLPTR;
static void (* T1_OVF_PTR_TO_FUN) (void) = NULLPTR;
static void (* T2_OVF_PTR_TO_FUN) (void) = NULLPTR;

static void (* T0_CMP_PTR_TO_FUN) (void) = NULLPTR;
static void (* T1_CMPA_PTR_TO_FUN) (void) = NULLPTR;
static void (* T1_CMPB_PTR_TO_FUN) (void) = NULLPTR;
static void (* T2_CMP_PTR_TO_FUN) (void) = NULLPTR;

//////////////////////////// private functions ///////////////////////////

void set_TIMER_OVF_INT_fun(ST_TIMER_t * timer){
	switch (timer->timerSelect) {
		case TIMER0:
			T0_OVF_PTR_TO_FUN = timer->callbackFunction;
			break;
		case TIMER1:
			T1_OVF_PTR_TO_FUN = timer->callbackFunction;
			break;
		case TIMER2:
			T2_OVF_PTR_TO_FUN = timer->callbackFunction;
			break;
	}
}

void set_TIMER_CMP_INT_fun(ST_TIMER_t * timer){
	switch (timer->timerSelect) {
		case TIMER0:
			T0_CMP_PTR_TO_FUN = timer->callbackFunction;
			break;
		case TIMER1:
			T1_CMPA_PTR_TO_FUN = timer->callbackFunction;
			T1_CMPB_PTR_TO_FUN = timer->callbackFunction;
			break;
		case TIMER2:
			T2_CMP_PTR_TO_FUN = timer->callbackFunction;
			break;
	}
}

void set_timer_init_value(uint8_t timer, uint16_t value) {
	
	/* Make sure that the timer is in the valid range */
	switch (timer) {
		case TIMER0:
		TCNT0_Reg = (uint8_t) value;
		break;
		case TIMER1:
		TCNT1H_Reg = (uint8_t) (value >> 8);
		TCNT1L_Reg = (uint8_t) value;
		break;
		case TIMER2:
		TCNT2_Reg = (uint8_t) value;
		break;
	}
}

void T0_TIMSK_init(uint8_t interrupt_mode){
	if (interrupt_mode == OVF_MODE) SET_BIT(TIMSK_Reg, 0);
	else if (interrupt_mode == CMP_MODE) SET_BIT(TIMSK_Reg, 1);
	else {
		CLR_BIT(TIMSK_Reg, 0);
		CLR_BIT(TIMSK_Reg, 1);
	}
}

void T1_TIMSK_init(uint8_t interrupt_mode){
	if (interrupt_mode == OVF_MODE) {
		SET_BIT(TIMSK_Reg, 2);
	}else if (interrupt_mode == CMP_MODE) {
		SET_BIT(TIMSK_Reg, 3);
		SET_BIT(TIMSK_Reg, 4);
	}else {
		CLR_BIT(TIMSK_Reg, 2);
		CLR_BIT(TIMSK_Reg, 3);
		CLR_BIT(TIMSK_Reg, 4);
	}
}

void T2_TIMSK_init(uint8_t interrupt_mode){
	if (interrupt_mode == OVF_MODE) {
		SET_BIT(TIMSK_Reg, 6);
	}else if (interrupt_mode == CMP_MODE) {
		SET_BIT(TIMSK_Reg, 7);
	}else {
		CLR_BIT(TIMSK_Reg, 6);
		CLR_BIT(TIMSK_Reg, 7);
	}
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////// public functions ////////////////////////////

EN_TIMER_ERROR timer_init(ST_TIMER_t * timer) {

	if (timer->interrupt_mode == OVF_MODE) {
		sei();
		set_TIMER_OVF_INT_fun(timer);
	}else if(timer->interrupt_mode == CMP_MODE) {
		sei();
		set_TIMER_CMP_INT_fun(timer);
	}else if (timer->interrupt_mode != NONE) return INVALID_INTERRUPT_MODE;

	/* Activating normal mode */
	switch (timer->timerSelect) {
		case TIMER0: 
			TCCR0_Reg = 0x00;
			T0_TIMSK_init(timer->interrupt_mode);
			break;
		case TIMER1: 
			TCCR1A_Reg = 0x00;
			TCCR1B_Reg = 0x00;
			T1_TIMSK_init(timer->interrupt_mode);
			break;
		case TIMER2: 
			TCCR2_Reg = 0x00;
			T2_TIMSK_init(timer->interrupt_mode);
			break;
		default: return INVALID_TIMER_SELECT;
	}

	return TIMER_OK;
}

EN_TIMER_ERROR delay_start(uint8_t timer, uint16_t delay_ms, uint16_t prescaler) {
	/* Make sure that the prescaler is in the valid range */
	switch (prescaler) {
		case NO_PRESCALER: break;
		case PRESCALER_8: break;
		case PRESCALER_64: break;
		case PRESCALER_256: break;
		case PRESCALER_1024: break;
		default: return INVALID_PRESCALER; // wrong prescaler
	}

	 /* getting the number of overflows */
	double t_max_delay = 0.0, t_tick = (1000.0 * prescaler) / F_CPU; // t_tick [ in milli seconds ]
	uint16_t n_overflows = 0, t_initial = 0;
	timer_flag = TRUE;

	/* Make sure that the timer is in the valid range */
	switch (timer) {
		case TIMER0:
		case TIMER2: 
			t_max_delay = 256.0 * t_tick; // 2^8 = 256
			n_overflows = ceil(delay_ms / t_max_delay);
			t_initial = (int) (256.0 - delay_ms / (t_tick * n_overflows));// 2^8 = 256
			break;
		case TIMER1:
			t_max_delay = 65536.0 * t_tick; // 2^16 = 65536
			n_overflows = ceil(delay_ms / t_max_delay);
			t_initial = (int) (65536.0 - delay_ms / (t_tick * n_overflows)); // 2^16 = 65536
			break;
		default: return INVALID_TIMER_SELECT; /* ERROR invalid input (timer) */ 
	}
	
	/* setting the initial value */
	set_timer_init_value(timer, t_initial);
	
	switch (timer) {
		case TIMER0:
			switch (prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR0_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR0_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR0_Reg, 0); SET_BIT(TCCR0_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR0_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR0_Reg, 0); SET_BIT(TCCR0_Reg, 2); break;
			}
			for (uint16_t i = 0; (i < n_overflows); i++) {
				while((READ_BIT(TIFR_Reg, 0) == 0) && timer_flag); 
				SET_BIT(TIFR_Reg, 0);
				timer_flag = TRUE;
			}
			break;
		case TIMER1:
			switch (prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR1B_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR1B_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR1B_Reg, 0); SET_BIT(TCCR1B_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR1B_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR1B_Reg, 0); SET_BIT(TCCR1B_Reg, 2); break;
			}
			for (uint16_t i = 0; (i < n_overflows); i++) {
				while((READ_BIT(TIFR_Reg, 2) == 0) && timer_flag); 
				SET_BIT(TIFR_Reg, 2);
				timer_flag = TRUE;
			}
			break;
		case TIMER2:
			switch (prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR2_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR2_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR2_Reg, 0); SET_BIT(TCCR2_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR2_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR2_Reg, 0); SET_BIT(TCCR2_Reg, 2); break;
			}
			for (uint16_t i = 0; (i < n_overflows); i++) {
				while((READ_BIT(TIFR_Reg, 6) == 0) && timer_flag); 
				SET_BIT(TIFR_Reg, 6);
				timer_flag = TRUE;
			}
			break;
		default: return INVALID_TIMER_SELECT; /* ERROR invalid input (timer) */
	}
	return TIMER_OK;
}

EN_TIMER_ERROR delay_stop(uint8_t timer) {

		/* Reseting to normal mode */
		switch (timer) {
			case TIMER0: 
				TCCR0_Reg = 0x00; 
				TCNT0_Reg = 0x00;
				break;
			case TIMER1: 
				TCCR1A_Reg = 0x00; 
				TCCR1B_Reg = 0x00; 
				TCNT1H_Reg = 0x00;
				TCNT1L_Reg = 0x00;
				break;
			case TIMER2: 
				TCCR2_Reg = 0x00; 
				TCNT2_Reg = 0x00;
				break;
			default: return INVALID_TIMER_SELECT;
		}
		return TIMER_OK;
}

uint16_t get_timer_value(uint8_t timer) {
	
	uint16_t result = 0, M = 0, L = 0;
	
	/* Make sure that the timer is in the valid range */
	if (timer <= TIMER2) {
		switch (timer) {
			/* getting the value */
			case TIMER0: result = (uint16_t) TCNT0_Reg & 0x00FF; break;
			case TIMER1: 
				M = TCNT1H_Reg & 0x00FF;
				L = TCNT1L_Reg & 0x00FF;
				result = (M << 8) | L;
				break;
			case TIMER2: result = (uint16_t) TCNT2_Reg & 0x00FF; break;
		}
	} else { /* ERROR invalid input (timer) */ }
	return result;
}

EN_TIMER_ERROR stopwatch_start(ST_TIMER_t * timer){
	switch (timer->timerSelect) {
		case TIMER0:
			switch (timer->prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR0_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR0_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR0_Reg, 0); SET_BIT(TCCR0_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR0_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR0_Reg, 0); SET_BIT(TCCR0_Reg, 2); break;
				default: return INVALID_PRESCALER; // wrong prescaler
			}
			break;
		case TIMER1:
			switch (timer->prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR1B_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR1B_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR1B_Reg, 0); SET_BIT(TCCR1B_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR1B_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR1B_Reg, 0); SET_BIT(TCCR1B_Reg, 2); break;
				default: return INVALID_PRESCALER; // wrong prescaler
			}
			break;
		case TIMER2:
			switch (timer->prescaler) {
				case NO_PRESCALER: SET_BIT(TCCR2_Reg, 0); break;
				case PRESCALER_8: SET_BIT(TCCR2_Reg, 1); break;
				case PRESCALER_64: SET_BIT(TCCR2_Reg, 0); SET_BIT(TCCR2_Reg, 1); break;
				case PRESCALER_256: SET_BIT(TCCR2_Reg, 2); break;
				case PRESCALER_1024: SET_BIT(TCCR2_Reg, 0); SET_BIT(TCCR2_Reg, 2); break;
				default: return INVALID_PRESCALER; // wrong prescaler
			}
			break;
		default: return INVALID_TIMER_SELECT;
	}
	return TIMER_OK;
}

EN_TIMER_ERROR stopwatch_stop(ST_TIMER_t * timer, uint16_t * valueRead){

	uint16_t timer_value = get_timer_value(timer->timerSelect);
	double t_max_delay = 0.0, t_tick = (1000.0 * (timer->prescaler)) / F_CPU; // t_tick [ in milli seconds ]

	switch (timer->timerSelect) {
		case TIMER0: 
			TCCR0_Reg = 0x00; 
			TCNT0_Reg = 0x00;
			t_max_delay = 256.0 * t_tick; // 2^8 = 256
			* valueRead = (uint16_t) (sw_n_overflow * t_max_delay + t_tick * timer_value);
			break;
		case TIMER1: 
			TCCR1A_Reg = 0x00; 
			TCCR1B_Reg = 0x00; 
			TCNT1H_Reg = 0x00;
			TCNT1L_Reg = 0x00;
			t_max_delay = 65536.0 * t_tick; // 2^16 = 65536
			* valueRead = (uint16_t) (sw_n_overflow * t_max_delay + t_tick * timer_value);
			break;
		case TIMER2: 
			TCCR2_Reg = 0x00; 
			TCNT2_Reg = 0x00;
			t_max_delay = 256.0 * t_tick; // 2^8 = 256
			* valueRead = (uint16_t) (sw_n_overflow * t_max_delay + t_tick * timer_value);
			break;
		default: return INVALID_TIMER_SELECT;  /* ERROR invalid input (timer) */
	}
	sw_n_overflow = 0;
	return TIMER_OK;
}

//////////////////////////////////////////////////////////////////////////

/////////////////////////// ISR OVF functions ////////////////////////////

ISR(TIMER0_OVF_vect) {
    T0_OVF_PTR_TO_FUN();
}

ISR(TIMER1_OVF_vect) {
    T1_OVF_PTR_TO_FUN();
}

ISR(TIMER2_OVF_vect) {
    T2_OVF_PTR_TO_FUN();
}

/////////////////////////// ISR CMP functions ////////////////////////////

ISR(TIMER0_COMP_vect) {
    T0_CMP_PTR_TO_FUN();
}

ISR(TIMER1_COMPA_vect) {
    T1_CMPA_PTR_TO_FUN();
}

ISR(TIMER1_COMPB_vect) {
    T1_CMPB_PTR_TO_FUN();
}

ISR(TIMER2_COMP_vect) {
    T2_CMP_PTR_TO_FUN();
}