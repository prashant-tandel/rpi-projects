#include "types.h"
#include "serial.h"

UART1_REGS *uart_regs = 0x20201000;

void serial_putc(uchar c)
{
	while (uart_regs->fr & (UART01x_FR_TXFF));
	uart_regs->dr = (uint)c;
}

void uart_init(uint baud)
{
	int temp, div, rem, frac;

	temp = 1843200; //UART_BAUD << 4;	// 16 * baudrate
	div = 1; //UART0_CLOCK / temp;
	rem = 1156800; //UART0_CLOCK % temp;
	temp = 80; //(8 * rem) / UART_BAUD;
	frac = (temp >> 1) + (temp & 1);

	/* Make sure the UART is disabled before we start */
	uart_regs->cr = 0;
//	__raw_writel(0, BCM2708_UART_CR);

	/* Set the baud rate */
	uart_regs->ibrd = div;
	uart_regs->fbrd = frac;
//	__raw_writel(div, BCM2708_UART_IBRD);
//	__raw_writel(frac, BCM2708_UART_FBRD);

	/* Set the UART to 8n1, FIFO enabled */
	uart_regs->lcrh = UART01x_LCRH_WLEN_8;
	uart_regs->lcrh &= (uint)~UART01x_LCRH_FEN;
//	__raw_writel(UART01x_LCRH_WLEN_8 | UART01x_LCRH_FEN, BCM2708_UART_LCRH);

//	uart_regs->ifls = 0x4;

	/* Enable the UART */
	uart_regs->cr = UART01x_CR_UARTEN | UART011_CR_TXE;
//	__raw_writel(UART01x_CR_UARTEN | UART011_CR_TXE | UART011_CR_RXE,
//			BCM2708_UART_CR);
}
