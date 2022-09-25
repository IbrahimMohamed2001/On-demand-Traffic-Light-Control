/*
 * interrupt.c
 *
 * Created: 9/3/2022 2:20:47 PM
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

#include "interrupt.h"

static void (* EXT_INT0_PTR_TO_FUN) (void) = NULLPTR;
static void (* EXT_INT1_PTR_TO_FUN) (void) = NULLPTR;
static void (* EXT_INT2_PTR_TO_FUN) (void) = NULLPTR;

//////////////////////////// private function ////////////////////////////

void set_INT_FUN(ST_EXT_INT_t * interrupt){
	switch (interrupt->interruptPinSelect) {
		case INTERRUPT0:
		EXT_INT0_PTR_TO_FUN = interrupt->callbackFunction;
		break;
		case INTERRUPT1:
		EXT_INT1_PTR_TO_FUN = interrupt->callbackFunction;
		break;
		case INTERRUPT2:
		EXT_INT2_PTR_TO_FUN = interrupt->callbackFunction;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////// public functions ////////////////////////////

EN_INTERRUPT_ERROR EXT_INT_init(ST_EXT_INT_t * interrupt){

    /* setting the global interrupt flag */
    sei();

    /* Make sure that the interrupt is in the valid range */
    switch (interrupt->interruptPinSelect) {
        case INTERRUPT0:
            SET_BIT(GICR_Reg, 6); // activating interrupt 0
            switch (interrupt->senseControl) {
                case LOW_LEVEL: MCUCR_Reg &= 0xFC; break;
                case ANY_LOGICAL_CHANGE: SET_BIT(MCUCR_Reg, 0); break;
                case FALLING_EDGE: SET_BIT(MCUCR_Reg, 1); break;
                case RISING_EDGE: MCUCR_Reg |= 0x03; break;
                default: return INVALID_SENSE_CONTROL;
            }
            break;
        case INTERRUPT1:
            SET_BIT(GICR_Reg, 7); // activating interrupt 1
            switch (interrupt->senseControl) {
                case LOW_LEVEL: MCUCR_Reg &= 0xF3; break;
                case ANY_LOGICAL_CHANGE: SET_BIT(MCUCR_Reg, 2); break;
                case FALLING_EDGE: SET_BIT(MCUCR_Reg, 3); break;
                case RISING_EDGE: MCUCR_Reg |= 0x0C; break;
                default: return INVALID_SENSE_CONTROL;
            }
            break;
        case INTERRUPT2:
            SET_BIT(GICR_Reg, 5); // activating interrupt 2
            switch (interrupt->senseControl) {
                case RISING_EDGE: SET_BIT(MCUCSR_Reg, 6); break;
                case FALLING_EDGE: CLR_BIT(MCUCSR_Reg, 6); break;
                default: return INVALID_SENSE_CONTROL;
            }
            break;
        default: return INVALID_INTERRUPT_SELECT;
    }
    set_INT_FUN(interrupt);
    return INTERRUPT_OK;
}

//////////////////////////////////////////////////////////////////////////

///////////////////////////// ISR functions //////////////////////////////


ISR(INT0_vect) {
    EXT_INT0_PTR_TO_FUN();
}

ISR(INT1_vect) {
    EXT_INT1_PTR_TO_FUN();
}

ISR(INT2_vect) {
    EXT_INT2_PTR_TO_FUN();
}