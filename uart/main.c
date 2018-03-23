#include "uart.h"
#include "gpio.h"
#include <stdio.h>

int main(void) {

	uart_init();
	
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;
	
	
	int button_A = (1 << 17);
	int button_B = (1 << 26);


	//int sleep = 0;
	


	while(1){

		char letter = uart_read();

		uart_send(letter);

		//Check if button A is pressed;
		if (!(GPIO->IN & button_A)) {
			uart_send('A');
		}

		//Check if button B is pressed;
		if (!(GPIO->IN & button_B)) {
			uart_send('B');
		}
		
		if (letter != '\0'){
			led_lights();
		}

		sleep = 200000;
		//sleep = 10000;
		while(--sleep);
	}
	return 0;
}