#ifndef SERIAL_H
#define SERIAL_H

#include "types.h"

#define UART01x_FR_BUSY		(1 << 3)
#define UART01x_FR_TXFF		0x020
#define UART011_CR_CTSEN	0x8000	/* CTS hardware flow control */
#define UART011_CR_RTSEN	0x4000	/* RTS hardware flow control */
#define UART011_CR_OUT2		0x2000	/* OUT2 */
#define UART011_CR_OUT1		0x1000	/* OUT1 */
#define UART011_CR_RTS		0x0800	/* RTS */
#define UART011_CR_DTR		0x0400	/* DTR */
#define UART011_CR_RXE		0x0200	/* receive enable */
#define UART011_CR_TXE		0x0100	/* transmit enable */
#define UART011_CR_LBE		0x0080	/* loopback enable */
#define UART010_CR_RTIE		0x0040
#define UART010_CR_TIE 		0x0020
#define UART010_CR_RIE 		0x0010
#define UART010_CR_MSIE		0x0008
#define ST_UART011_CR_OVSFACT	0x0008	/* Oversampling factor */
#define UART01x_CR_IIRLP	0x0004	/* SIR low power mode */
#define UART01x_CR_SIREN	0x0002	/* SIR enable */
#define UART01x_CR_UARTEN	0x0001	/* UART enable */
 
#define UART011_LCRH_SPS	0x80
#define UART01x_LCRH_WLEN_8	0x60
#define UART01x_LCRH_WLEN_7	0x40
#define UART01x_LCRH_WLEN_6	0x20
#define UART01x_LCRH_WLEN_5	0x00
#define UART01x_LCRH_FEN	0x10
#define UART01x_LCRH_STP2	0x08
#define UART01x_LCRH_EPS	0x04
#define UART01x_LCRH_PEN	0x02
#define UART01x_LCRH_BRK	0x01

#define UART0_CLOCK     3000000
#define UART_BAUD 	115200

typedef struct _UART1_REGS {
	uint dr;	// 0x00
	uint rsrecr;	// 0x04
	uint res0[0x4];	// 0x08 - 0x14
	uint fr;	// 0x18
	uint res1;	// 0x1c
	uint ilpr;	// 0x20
	uint ibrd;	// 0x24
	uint fbrd;	// 0x28
	uint lcrh;	// 0x2c
	uint cr;	// 0x30
	uint ifls;	// 0x34
	uint imsc;	// 0x38
	uint ris;	// 0x3c
	uint mis;	// 0x40
	uint icr;	// 0x44
	uint dmacr;	// 0x48
	uint res2[0xE];	// Reserved
	uint itcr;	// 0x80
	uint itip;	// 0x84
	uint itop;	// 0x88
	uint tdr;	// 0x8c
} UART1_REGS;

#endif	// End of SERIAL_H
