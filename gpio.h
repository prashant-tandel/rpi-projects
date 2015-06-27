#ifndef GPIO_H
#define GPIO_H

#include "types.h"

#define GPIO_REG_BASE		0x20200000

#define GPIO_FUNC_INPUT 	0x0
#define GPIO_FUNC_OUTPUT 	0x1
#define GPIO_FUNC_ALT0		0x4
#define GPIO_FUNC_ALT1		0x5
#define GPIO_FUNC_ALT2		0x6
#define GPIO_FUNC_ALT3		0x7
#define GPIO_FUNC_ALT4		0x3
#define GPIO_FUNC_ALT5		0x2

typedef struct _GPIO_REG {
	uint gpfSel[6];
	uint res0;
	uint gpSet0;
	uint gpSet1;
	uint res1;
	uint gpClr0;
	uint gpClr1;
	uint res2;
	uint gplev0;
	uint gplev1;
	uint res3;
	uint gpeds0;
	uint gpeds1;
	uint res4;
	uint gpren0;
	uint gpren1;
	uint res5;
	uint gpfen0;
	uint gpfen1;
	uint res6;
	uint gphen0;
	uint gphen1;
	uint res7;
	uint gplen0;
	uint gplen1;
	uint res8;
	uint gparen0;
	uint gparen1;
	uint res9;
	uint gpafen0;
	uint gpafen1;
	uint res10;
	uint gppud;
	uint gppudclk0;
	uint gppudclk1;
	uint res11;
	uint test;
} GPIO_REG;

#define gpio_regs ((GPIO_REG*)GPIO_REG_BASE)

#endif
