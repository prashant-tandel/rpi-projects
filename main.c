#define ATTRIB(SEC) __attribute__ ((section (#SEC)))
#define ATTRIB_INIT ATTRIB(.init)
#define ATTRIB_TEXT ATTRIB(.text)
#define ATTRIB_DATA ATTRIB(.data)
#define WAIT_TIME (1000000)

#include "types.h"
#include "gpio.h"

extern void serial_putc(char);

void wait(unsigned int waitTime)
{
	unsigned int i=0;
	for (i=0; i<=waitTime; i++);
	return;
}

void main() 
{
	uart_gpio_init();
	uart_init(0);
	while (1)
		pprintf("Hello World from the Pi-Core!!!\n");
	while(1);
}
