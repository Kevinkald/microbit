#ifndef TWI_H
#define TWI_H
#include <stdint.h>
#include <stdlib.h> 

#define slave_address 0x1D
#define WHO_AM_I 0x0D


#define TWI0 ((NRF_TWI_REG*)0x40003000)
typedef struct {
	//Tasks
	volatile uint32_t STARTRX;
	volatile uint32_t RESERVED0[1];
	volatile uint32_t STARTTX;
	volatile uint32_t RESERVED1[2];
	volatile uint32_t STOP;
	volatile uint32_t RESERVED2[1];
	volatile uint32_t SUSPEND;
	volatile uint32_t RESUME;
	volatile uint32_t RESERVED3[56];

	//Events
	volatile uint32_t STOPPED;
	volatile uint32_t RXDREADY;
	volatile uint32_t RESERVED4[4];
	volatile uint32_t TXDSENT;
	volatile uint32_t RESERVED5[1];
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED6[4];
	volatile uint32_t BB;
	volatile uint32_t RESERVED7[49];

	//Registers
	volatile uint32_t SHORTS;
	volatile uint32_t RESERVED8[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED9[110];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED10[14];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED11[1];
	volatile uint32_t PSELSCL;
	volatile uint32_t PSELSDA;
	volatile uint32_t RESERVED12[2];
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t RESERVED13[1];
	volatile uint32_t FREQUENCY;
	volatile uint32_t RESERVED14[24];
	volatile uint32_t ADDRESS;

} NRF_TWI_REG;

/*#define GPIO ((NRF_GPIO_REGS*)0x50000000)
typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t RESERVED1[120];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;*/

void twi_init();

void twi_multi_read(uint8_t slave_adress,
					uint8_t start_register,
					int registers_to_read,
					uint8_t * data_buffer
					);

void twi_multi_write(uint8_t slave_adress,
					uint8_t start_register,
					int registers_to_write,
					uint8_t * data_buffer
					);

#endif //TWI_H