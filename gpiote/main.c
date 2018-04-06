#include "gpiote.h"
#include "gpio.h"
#include "ppi.h"

int main(void) {

	enum mode {DISABLED, EVENT, TASK = 3};
	enum polarity {None, LoToHi, HiToLo, Toggle};

	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	//GPIOTE

	//Channel 0
	GPIOTE->CONFIG[0] |= EVENT;
	GPIOTE->CONFIG[0] |= (17 << 8);
	GPIOTE->CONFIG[0] |= (HiToLo << 16);

	//Channel 1
	GPIOTE->CONFIG[1] |= TASK;
	GPIOTE->CONFIG[1] |= (13 << 8);
	GPIOTE->CONFIG[1] |= (Toggle << 16);
	GPIOTE->CONFIG[1] |= (0 << 20);

	//Channel 2
	GPIOTE->CONFIG[2] |= TASK;
	GPIOTE->CONFIG[2] |= (14 << 8);
	GPIOTE->CONFIG[2] |= (Toggle << 16);
	GPIOTE->CONFIG[2] |= (0 << 20);

	//Channel 3
	GPIOTE->CONFIG[3] |= TASK;
	GPIOTE->CONFIG[3] |= (15 << 8);
	GPIOTE->CONFIG[3] |= (Toggle << 16);
	GPIOTE->CONFIG[3] |= (0 << 20);


	//PPI

	//Setup PPI
	//PPI->CHEN 		|= 0b111;
	PPI->CHENSET 	|= 0b111;

	//Channel 0
	PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->OUT[1]);

	//Channel 1
	PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[2]);

	//Channel 2
	PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[3]);
	
	int sleep = 0;
	

	while(1){

		
		sleep = 200000;
		while(--sleep);
	}
	return 0;
}