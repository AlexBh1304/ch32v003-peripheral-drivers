#ifndef CH32V003_H
#define CH32V003_H

#include <stdint.h>


#define RCC_BASE_ADDRESS   0x40021000

typedef struct
{
    volatile uint32_t CTLR;
    volatile uint32_t CFGR0;
    volatile uint32_t INTR;
    volatile uint32_t APB2PRSTR;
    volatile uint32_t APB1PRSTR;
    volatile uint32_t AHBCENR;
    volatile uint32_t APB2PCENR;
    volatile uint32_t APB1PCENR;
    volatile uint32_t RSTSCKR;
}RCC_t;

#define RCC ((RCC_t*)(RCC_BASE_ADDRESS))

    
#define GPIOA_BASE_ADDRESS  0x40010800
#define GPIOC_BASE_ADDRESS  0x40011000
#define GPIOD_BASE_ADDRESS  0x40011400

typedef struct
{
    volatile uint32_t CFGLR;
    volatile uint32_t INDR;
    volatile uint32_t OUTDR;
    volatile uint32_t BSHR;
    volatile uint32_t BCR;
    volatile uint32_t LCKR;

}GPIO_t;


#define GPIOA ((GPIO_t*)(GPIOA_BASE_ADDRESS))
#define GPIOC ((GPIO_t*)(GPIOC_BASE_ADDRESS))
#define GPIOD ((GPIO_t*)(GPIOD_BASE_ADDRESS))

#define ADC_BASE_ADDRESS  0x40012400

typedef struct
{
    volatile uint32_t STATR;
    volatile uint32_t CTRL1;
    volatile uint32_t CTRL2;
    volatile uint32_t SAMPTR1;
    volatile uint32_t SAMPTR2;
    volatile uint32_t IOFR1;
    volatile uint32_t IOFR2;
    volatile uint32_t IOFR3;
    volatile uint32_t IOFR4;
    volatile uint32_t WDHTR;
    volatile uint32_t WDLTR;
    volatile uint32_t RSQR1;
    volatile uint32_t RSQR2;
    volatile uint32_t RSQR3;
    volatile uint32_t ISQR;
    volatile uint32_t IDATAR1;
    volatile uint32_t IDATAR2;
    volatile uint32_t IDATAR3;
    volatile uint32_t IDATAR4;
    volatile uint32_t RDATAR;
    volatile uint32_t DLYR;
}ADC_t;

#define ADC     ((ADC_t*)(ADC_BASE_ADDRESS))

#include "gpio.h"
#include "rcc.h"




#endif
