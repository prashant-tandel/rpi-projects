
#include "types.h"
#include "gpio.h"

void gpioFuncSelect(uint gpioNum, uint gpioFunc)
{
	uint bank = gpioNum/10;
	gpio_regs->gpfSel[bank] &= ~(7 << ((gpioNum%10)*3)); 
	gpio_regs->gpfSel[bank] |= (gpioFunc << ((gpioNum%10)*3)); 
}

void gpioSet(uint gpioNum)
{
	if (gpioNum <= 31)
		gpio_regs->gpSet0 |= (1 << gpioNum);
	else
		gpio_regs->gpSet1 |= 1 << (gpioNum%32);

}

void gpioClear(uint gpioNum)
{
	if (gpioNum <= 31)
		gpio_regs->gpClr0 |= (1 << gpioNum);
	else
		gpio_regs->gpClr1 |= 1 << (gpioNum%32);
}

