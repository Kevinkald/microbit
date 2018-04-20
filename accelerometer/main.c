#include "accel.h"
#include "twi.h"
#include "utility.h"
#include "../uart/uart.h"
#include "../uart/gpio.h"
#include "ubit_led_matrix.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	twi_init();
	accel_init();
	uart_init();
	ubit_led_matrix_init();
	
	int sleep = 0;

	uint8_t * data_buffer1;
	data_buffer1 = (uint8_t *)malloc(8 * sizeof(uint8_t));
	int registers_to_read = 8;
	uint8_t start_register = WHO_AM_I;
	uint8_t accelerometer_address = slave_address;
	
	twi_multi_read(accelerometer_address, start_register,registers_to_read, data_buffer1);
	
	free(data_buffer1);
		
	/*
	if (data_buffer[0] == 0x5A){
		GPIO->OUTSET = (1 << 13);
		GPIO->OUTSET = (1 << 14);
		GPIO->OUTSET = (1 << 15);
	} */
	



	int * data_buffer = (int *)malloc(3 * sizeof(int));
	//int data_buffer[3];
	 
	//int i = 0;
	while(1){
		
		
		accel_read_x_y_z(data_buffer);
		int x_acc = data_buffer[0];
		int y_acc = data_buffer[1];
		int z_acc = data_buffer[2];
	
		
		utility_print(&uart_send, "X: %6d Y: %6d Z: %6d\n\r", x_acc, y_acc, z_acc);
		//utility_print(&uart_send, "i: %6d\n\r ", i);
		//i++;
		
		/*
		int x_led = x_acc / 50;
		int y_led = - y_acc / 50;
		ubit_led_matrix_light_only_at(x_led, y_led);
		*/

		sleep = 10000;
		while(--sleep);
		
	}
	free(data_buffer);
	return 0;
}
