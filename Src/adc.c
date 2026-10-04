#include "adc.h"
#include "gpio.h"


void ADCInit(ADC_t* pADC, ADC_Config* AdcConfig)
{
    
    GPIO_Config gpioconfig;
    gpioconfig.Pin = GPIO_PIN_2;
    gpioconfig.Mode = INPUT_ANALOG;
    GPIOxClockControl(GPIOA);
    GPIOInit(GPIOA, &gpioconfig);
    

    RCC->APB2PCENR |= (1 << 9);

    pADC->RSQR1 |= (0b1 << 20);
    
    pADC->SAMPTR2 |= (AdcConfig->SampleTime << 0);

    pADC->CTRL2 |= (1 << 0);

    for(volatile uint32_t i = 0; i< 500000; i++);

}


uint16_t ADCRead(ADC_t* pADC)
{
    pADC->CTRL2 |= (1 << 0);

    while(!(pADC->STATR & 0b10));
    
    return (uint16_t)(ADC->RDATAR);

}
