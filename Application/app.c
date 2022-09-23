/*
 * app.c
 *
 * Created: 8/28/2022 4:26:46 PM
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

#include "app.h"

#define GREEN PIN0
#define YELLOW PIN1
#define RED	PIN2

#define CARS PORTA
#define PEDESTRIANS PORTB

#define CARS_MODE 0
#define PEDESTRIANS_MODE 1

#define CARS_GREEN_STATE 0
#define CARS_RED_STATE 1

#define DEBUG_LED_PORT PORTC
#define DEBUG_LED_PIN PIN2

uint8_t mode = CARS_MODE;
extern bool timer_flag;
uint8_t cars_state = CARS_GREEN_STATE;

void button_INT_fun(void); // interrupt function of the button
void blinking_leds(); // blinking function => blinks a yellow leds for 5 seconds

volatile ST_TIMER_t timer1 = {TIMER1, PRESCALER_1024, NONE};
volatile ST_EXT_INT_t interrupt = {INTERRUPT0, RISING_EDGE, &button_INT_fun};

void app_init() {
	LED_init(CARS, GREEN);
	LED_init(CARS, YELLOW);
	LED_init(CARS, RED);

	LED_init(PEDESTRIANS, GREEN);
	LED_init(PEDESTRIANS, YELLOW);
	LED_init(PEDESTRIANS, RED);

	LED_init(DEBUG_LED_PORT, DEBUG_LED_PIN);

	timer_init(& timer1);

	EXT_INT_init(& interrupt);
}

void app_start() {
	while(1) {
		if (mode == CARS_MODE){
			LED_ON(DEBUG_LED_PORT, DEBUG_LED_PIN);

			LED_ON(CARS, GREEN);
			LED_OFF(CARS, YELLOW);
			LED_OFF(CARS, RED);

			LED_OFF(PEDESTRIANS, GREEN);
			LED_OFF(PEDESTRIANS, YELLOW);
			LED_ON(PEDESTRIANS, RED);

			delay_start(TIMER1, 5000, PRESCALER_1024);
			delay_stop(TIMER1);
			
			LED_OFF(CARS, GREEN);
			LED_OFF(PEDESTRIANS, RED);

			if (mode != CARS_MODE) continue;

			cars_state = CARS_RED_STATE;

			blinking_leds();

			LED_OFF(CARS, GREEN);
			LED_OFF(CARS, YELLOW);
			LED_ON(CARS, RED);

			LED_ON(PEDESTRIANS, GREEN);
			LED_OFF(PEDESTRIANS, YELLOW);
			LED_OFF(PEDESTRIANS, RED);

			delay_start(TIMER1, 5000, PRESCALER_1024);
			delay_stop(TIMER1);
			
			LED_OFF(CARS, RED);
			LED_OFF(PEDESTRIANS, GREEN);
			
			cars_state = CARS_GREEN_STATE;

			blinking_leds();
			
			if (mode != CARS_MODE) continue;
			
		} else {
			if (cars_state == CARS_GREEN_STATE) {
				LED_OFF(DEBUG_LED_PORT, DEBUG_LED_PIN);

				LED_OFF(CARS, GREEN);
				LED_OFF(CARS, YELLOW);
				LED_OFF(CARS, RED);

				LED_OFF(PEDESTRIANS, GREEN);
				LED_OFF(PEDESTRIANS, YELLOW);
				LED_OFF(PEDESTRIANS, RED);

				blinking_leds();

				LED_OFF(CARS, GREEN);
				LED_OFF(CARS, YELLOW);
				LED_ON(CARS, RED);

				LED_ON(PEDESTRIANS, GREEN);
				LED_OFF(PEDESTRIANS, YELLOW);
				LED_OFF(PEDESTRIANS, RED);

				cars_state = CARS_RED_STATE;

				delay_start(TIMER1, 5000, PRESCALER_1024);
				delay_stop(TIMER1);

				LED_OFF(CARS, RED);
				LED_OFF(PEDESTRIANS, GREEN);

				blinking_leds();
						
			}
		}
		mode = CARS_MODE;
		cars_state = CARS_GREEN_STATE;

	}
}

void button_INT_fun(void){
	if(mode == PEDESTRIANS_MODE || cars_state == CARS_RED_STATE) return;
	timer_flag = FALSE;
	mode = PEDESTRIANS_MODE;
	return;
}

void blinking_leds() {
	for(int i = 0; (i < 10); i++){
		LED_toggle(CARS, YELLOW);
		LED_toggle(PEDESTRIANS, YELLOW);
		delay_start(TIMER1, 500, PRESCALER_1024);
		delay_stop(TIMER1);
	}
}