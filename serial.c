#include "types.h"
#include "serial.h"
#include "gpio.h"

void serial_putc(uchar c)
{
	while (uart0_regs->fr & (UART01x_FR_TXFF));
	uart0_regs->dr = (uint)c;
}

void uart_gpio_init()
{
#if 0
	gpioReg->gppud = 1;
	wait(WAIT_TIME/2);
	gpioReg->gppudclk0 = ((1 << 14) | (1 << 15));
	wait(WAIT_TIME/2);
	gpioReg->gppud = 0;
	gpioReg->gppudclk0 = ((1 << 14) | (1 << 15));
#endif
	gpioFuncSelect(14, GPIO_FUNC_ALT0);
	gpioFuncSelect(15, GPIO_FUNC_ALT0);
}

void pprintf(char *str)
{
	char *temp = str;
	while (*temp != 0) {
		if(*temp == '\n')
			serial_putc('\r');
		serial_putc(*temp);
		temp++;
	}
	return;
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
	uart0_regs->cr = 0;

	/* Set the baud rate */
	uart0_regs->ibrd = div;
	uart0_regs->fbrd = frac;

	/* Set the UART to 8n1, FIFO enabled */
	uart0_regs->lcrh = UART01x_LCRH_WLEN_8;
	uart0_regs->lcrh &= (uint)~UART01x_LCRH_FEN;

	/* Enable the UART */
	uart0_regs->cr = UART01x_CR_UARTEN | UART011_CR_TXE;
}
