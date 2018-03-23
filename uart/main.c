#include "uart.h"
#include "gpio.h"
#include <stdio.h>


int main(void) {

	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;
	
	int button_A = (1 << 17);
	int button_B = (1 << 26);

	int sleep = 0;
	uart_init();

	while(1){

		// to check uart use: picocom -b 9600 /dev/ttyACM0
		//Check if button A is pressed;
		if (!(GPIO->IN & button_A)) {
			uart_send('A');
		}

		//Check if button B is pressed;
		if (!(GPIO->IN & button_B)) {
			uart_send('B');
		}
		
		//toggle led lights 
		if (uart_read() != '\0'){
			led_lights();
		}

		sleep = 200000;
		while(--sleep);
	}
	return 0;
}
