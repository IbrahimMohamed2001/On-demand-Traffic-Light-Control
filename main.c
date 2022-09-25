/*
 * dummy_project.c
 *
 * Created: 8/28/2022 2:28:13 PM
 * Author : Barhoom Ali
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

#include "./Application/app.h"

int main(void) {
	
    /* Replace with your application code */
	app_init();
	app_start();
  
}




// extern uint16_t sw_n_overflow; 

// void stopwacth_INT_fun(void);

// volatile ST_TIMER_t timer = {TIMER1, PRESCALER_1024, NONE, NULLPTR};
// volatile ST_TIMER_t stopwacth_timer = {TIMER0, PRESCALER_1024, OVF_MODE, &stopwacth_INT_fun};

// int main(void) {
// 	uint16_t sw_timer_value = 0;

// 	timer_init(&timer);
// 	timer_init(&stopwacth_timer);

// 	LED_init(PORTA, PIN0);
// 	LED_init(PORTA, PIN1);

// 	while(1){
// 		LED_ON(PORTA, PIN0);
// 		stopwatch_start(&stopwacth_timer);
// 		delay_start(timer.timerSelect, 500, timer.prescaler);
// 		delay_stop(timer.timerSelect);
// 		stopwatch_stop(&stopwacth_timer, &sw_timer_value);
// 		if(sw_timer_value > 500) {
// 			LED_ON(PORTA, PIN1);
// 		}else LED_OFF(PORTA, PIN1);
// 	}
  
// }

// void stopwacth_INT_fun(void){
// 	sw_n_overflow++;
// 	SET_BIT(TIFR_Reg, 0);
// }

