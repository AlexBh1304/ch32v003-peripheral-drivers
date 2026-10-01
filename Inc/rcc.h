#ifndef RCC_H
#define RCC_H
#include "ch32v003.h"

void GPIOxClockControl(GPIO_t* pGPIO);


#define RCC_APB2PCENR_IOPAEN    2
#define RCC_APB2PCENR_IOPCEN    4
#define RCC_APB2PCENR_IOPDEN    5

#endif
