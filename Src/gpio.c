#include "gpio.h"


void GPIOInit(GPIO_t* pGPIO, GPIO_Config* gpioconfig)
{
    /*If output*/
    if(gpioconfig->Mode & 0x10)
    {
        pGPIO->CFGLR &= ~(CFGLR_MASK << gpioconfig->Pin);
        pGPIO->CFGLR |= (((gpioconfig->Mode | gpioconfig->Speed) & ~(0x10)) << gpioconfig->Pin);
    }
    //Input
    else
    {
        //PullUp or PullDown
        if(gpioconfig->Mode & 0x20)
        {
            pGPIO->CFGLR &= ~(CFGLR_MASK << gpioconfig->Pin);
            pGPIO->CFGLR |= (((gpioconfig->Mode) & ~(0x20)) << gpioconfig->Pin);

            if(gpioconfig->PullOption == PULLUP)
            {
                pGPIO->OUTDR |= (1 << Pin);
            }
            else
            {
                pGPIO->OUTDR &= ~(1 << Pin);
            }
        }
        else
        {
            pGPIO->CFGLR &= ~(CFGLR_MASK << gpioconfig->Pin);
            pGPIO->CFGLR |= (gpioconfig->Mode << gpioconfig->Pin);
        }
    }
}
void GPIOSet(GPIO_t* pGPIO, uint8_t Pin)
{
    pGPIO->BSHR = (1 << Pin);
}
void GPIOReset(GPIO_t* pGPIO, uint8_t Pin)
{

    pGPIO->BSHR = (1 << Pin);

}

void GPIOToggle(GPIO_t* pGPIO, uint8_t Pin)
{
    if(pGPIO->OUTDR & (1 << Pin))
    {
        GPIOReset(pGPIO,Pin);
    }
    else
    {
        GPIOSet(pGPIO,Pin);
    }
}

