#include "rcc.h"

void GPIOxClockControl(GPIO_t* pGPIO)
{
    switch((uint32_t)(pGPIO))
    {
        case((uint32_t)GPIOA):
            RCC->APB2PCENR |= (1 << RCC_APB2PCENR_IOPAEN);
            break;

        case((uint32_t)GPIOC):
            RCC->APB2PCENR |= (1 << RCC_APB2PCENR_IOPCEN);
            break;

        case((uint32_t)GPIOD):
            RCC->APB2PCENR |= (1 << RCC_APB2PCENR_IOPDEN);
            break;
    }
}

void USARTClockControl(USART_t* pUSART)
{
    switch((uint32_t)(pUSART))
    {
        case((uint32_t)USART):
            RCC->APB2PCENR |= (1 << RCC_APB2PCENR_USARTEN);
            break;

    }

}
