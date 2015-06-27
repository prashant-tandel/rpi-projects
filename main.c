#define ATTRIB(SEC) __attribute__ ((section (#SEC)))
#define ATTRIB_INIT ATTRIB(.init)
#define ATTRIB_TEXT ATTRIB(.text)
#define ATTRIB_DATA ATTRIB(.data)
#define WAIT_TIME (1000000)

#include "types.h"
#include "gpio.h"

#define GPIO_FUNC_INPUT 	0x0
#define GPIO_FUNC_OUTPUT 	0x1
#define GPIO_FUNC_ALT0		0x4
#define GPIO_FUNC_ALT1		0x5
#define GPIO_FUNC_ALT2		0x6
#define GPIO_FUNC_ALT3		0x7
#define GPIO_FUNC_ALT4		0x3
#define GPIO_FUNC_ALT5		0x2


extern void serial_putc(char);

GPIO_REG *gpioReg ATTRIB_DATA = 0x20200000;

void wait(unsigned int waitTime)
{
	unsigned int i=0;
	for (i=0; i<=waitTime; i++);
	return;
}

void gpioFuncSelect(uint gpioNum, uint gpioFunc)
{
	uint bank = gpioNum/10;
	gpioReg->gpfSel[bank] &= ~(7 << ((gpioNum%10)*3)); 
	gpioReg->gpfSel[bank] |= (gpioFunc << ((gpioNum%10)*3)); 
}

void gpioSet(uint gpioNum)
{
	if (gpioNum <= 31)
		gpioReg->gpSet0 = (1 << gpioNum);
	else
		gpioReg->gpSet1 = 1 << (gpioNum%32);

}

void gpioClear(uint gpioNum)
{
	if (gpioNum <= 31)
		gpioReg->gpClr0 = (1 << gpioNum);
	else
		gpioReg->gpClr1 = 1 << (gpioNum%32);

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
//	gpioSet(16);
	char *temp = str;
	while (*temp != 0) {
		if(*temp == '\n')
			serial_putc('\r');
		serial_putc(*temp);
		temp++;
	}
//	gpioClear(16);
	return;
}

void main() 
{
//	gpioFuncSelect(16, GPIO_FUNC_OUTPUT);
//	gpioClear(16);		// On
	uart_gpio_init();
	uart_init(0);
	while (1)
		pprintf("abc\n");
	while(1);
}
