#include "uart.h"
#include "gpio.h"
#include <stdint.h>

#define UART ((NRF_UART_REG*)0x40002000)

typedef struct {
	//Tasks
	volatile uint32_t STARTRX;
	volatile uint32_t STOPRX;
	volatile uint32_t STARTTX;
	volatile uint32_t STOPTX;
	volatile uint32_t RESERVED[3];
	volatile uint32_t SUSPEND;
	volatile uint32_t RESERVED1[56];

	//Events
	volatile uint32_t CTS;
	volatile uint32_t NCTS;
	volatile uint32_t RXDRDY;
	volatile uint32_t RESERVED2[4];
	volatile uint32_t TXDRDY;
	volatile uint32_t RESERVED3[1];
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED4[7];
	volatile uint32_t RXTO;
	volatile uint32_t RESERVED5[110];

	//Registers
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED6[93];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED7[31];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED8[1];
	volatile uint32_t PSELRTS;
	volatile uint32_t PSELTXD;
	volatile uint32_t PSELCTS;
	volatile uint32_t PSELRXD;
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t RESERVED9[1];
	volatile uint32_t BAUDRATE;
	volatile uint32_t RESERVED10[17];
	volatile uint32_t CONFIG;

} NRF_UART_REG;

void uart_init() {
	
    //Set TX to output and RX to input
    //PIN_TXD = 24;
    //PIN_RXD = 25;

    GPIO->PIN_CNF[24] = 1;
    GPIO->PIN_CNF[25] = 0;
    
    	//Set UART tx/rx to tx/tx pin
	UART->PSELTXD = 24;
   	UART->PSELRXD = 25;

	//Max sendingsrate 9600 DEC -> 0x30 HEX
	UART->BAUDRATE = 0x00275000;

	//Deaktiverer CTS og RTS
	UART->PSELCTS = 0xFFFFFFFF;
	UART->PSELRTS = 0xFFFFFFFF;

	//Starter UART og klar til å ta i mot meldinger RX
	UART->ENABLE = 0x4;
	UART->STARTRX = 0x1;

}

void uart_send(char letter) {
	
	UART->STARTTX = 0x1;
	UART->TXDRDY = 0;
	UART->TXD = letter;

	while (!(UART->TXDRDY)){
	}

	UART->STOPTX = 0x1;

}

char uart_read() {
			
	if(UART->RXDRDY){
		UART-> STARTRX = 1;
		char letter = UART->RXD;
		UART->STOPRX = 1;
		return letter;
	}

	else {
		return '\0';
	}
	
}

int a = 0;

void led_lights() {
	if(a){
		GPIO->OUTCLR = (1 << 13);
		GPIO->OUTCLR = (1 << 14);
		GPIO->OUTCLR = (1 << 15);
		a = 0;
	}
	else {
		GPIO->OUTSET = (1 << 13);
		GPIO->OUTSET = (1 << 14);
		GPIO->OUTSET = (1 << 15);
		a = 1;
	}
}	
