#include "uart.h"
#include "gpio.h"
#include <stdio.h>

int main(void) {

	uart_init();
	
	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;
	
	int button_A = (1 << 17);
	int button_B = (1 << 26);

	//int sleep = 0;
	
	while(1){

		//Check if button A is pressed;
		if (!(GPIO->IN & button_A)) {
			uart_send('A');
		}

		//Check if button B is pressed;
		if (!(GPIO->IN & button_B)) {
			uart_send('B');
		}
		//uart_read();
		printf("hallo\n");
		

		//sleep = 10000;
		//while(--sleep);
	}
	return 0;
}
	



	