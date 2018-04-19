#include <twi.h>
#include <stdint.h>
#include <stdio.h>


int main(){
for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	twi_init();
	
	int sleep = 0;
	int registers_to_read = 1;
	uint8_t start_register = WHO_AM_I;
	
	twi_multi_read(slave_adress, start_register,registers_to_read, &data_buffer);

	if (data[0] = 0x5A){
		GPIO->OUTSET = (1 << 13);
		GPIO->OUTSET = (1 << 14);
		GPIO->OUTSET = (1 << 15);
	} 

	while(1){

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
