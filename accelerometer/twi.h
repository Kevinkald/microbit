

#define TWI0 ((NRF_TWI_REG*)0x40003000)
typedef struct {
	//Tasks
	volatile uint32_t STARTRX;
	volatile uint32_t RESERVED[1];
	volatile uint32_t STARTTX;
	volatile uint32_t RESERVED[2];
	volatile uint32_t STOP;
	volatile uint32_t RESERVED[1];
	volatile uint32_t SUSPEND;
	volatile uint32_t SUSPEND;
	volatile uint32_t RESUME;
	volatile uint32_t RESERVED[56];

	//Events
	volatile uint32_t STOPPED;
	volatile uint32_t RXDREADY;
	volatile uint32_t RESERVED[4];
	volatile uint32_t TXDSENT;
	volatile uint32_t RESERVED[1];
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED[4];
	volatile uint32_t BB;
	volatile uint32_t RESERVED[49];

	//Registers
	volatile uint32_t SHORTS;
	volatile uint32_t RESERVED[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED[110];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED[14];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED[1];
	volatile uint32_t PSELSCL;
	volatile uint32_t PSELSDA;
	volatile uint32_t RESERVED[2];
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t RESERVED[1];
	volatile uint32_t FREQUENCY;
	volatile uint32_t RESERVED[24];
	volatile uint32_t ADDRESS;

} NRF_TWI_REG;