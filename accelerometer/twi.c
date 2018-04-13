#include "twi.h"

#define i2c_address 0x1D
#define WHO_AM_I 0x0D

void twi_init(){

	//pins on nRF set to input
	GPIO->PIN_CNF[0] = 0;
	GPIO->PIN_CNF[0] |= (3 << 2);
	GPIO->PIN_CNF[0] |= (6 << 8);

	GPIO->PIN_CNF[30] = 0;
	GPIO->PIN_CNF[30] |= (3 << 2);
	GPIO->PIN_CNF[30] |= (6 << 8);

	//psel set to pins on accel
	TWI0->PSELSCL = 0;
	TWI0->PSELSDA = 30;

	//set enable and freq
	TWI0->ADDRESS = i2c_address;
	TWI0->FREQUENCY = 0x01980000;
	TWI0->ENABLE = 0x5;
}

uint8_t * data_buffer;
data_buffer = (uint8_t *)malloc(8 * sizeof(uint8_t));

void twi_multi_read(uint8_t slave_adress, uint8_t start_register,
	int registers_to_read, uint8_t * data_buffer) {
	
	TWI0->ADDRESS = slave_address; 
	TWI0->STARTTX = 1;
	TWI0->TXDSENT = 0;
	TWI0->TXD = start_register;

	while(!TWI0->TXDSENT);

	TWI0->RXDREADY = 0;
	TWI0->STARTRX = 1;
	
	for(int i = 0; i < registers_to_read-1 ; i++){
		while(!TWIO->RXD);
		data_buffer[i] = TWI0->RXD;
		TWI0->STARTRX = 0;

	}
	
	TWI0->STOP = 1;
}

free(data_buffer); 
