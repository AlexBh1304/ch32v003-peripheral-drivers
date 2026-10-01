#ifndef GPIO_H
#define GPIO_H

#include "ch32v003.h"


typedef struct
{
 
    uint8_t Pin;
    uint8_t Mode;
    uint8_t Speed;
    uint8_t PullOption;

}GPIO_Config;

void GPIOInit(GPIO_t* pGPIO, GPIO_Config* gpioconfig);
void GPIOSet(GPIO_t* pGPIO, uint8_t Pin);
void GPIOReset(GPIO_t* pGPIO, uint8_t Pin);
void GPIOToggle(GPIO_t* pGPIO, uint8_t Pin);

//Values for Pin parameter

#define GPIO_PIN_0  0
#define GPIO_PIN_1  1
#define GPIO_PIN_2  2
#define GPIO_PIN_3  3
#define GPIO_PIN_4  4
#define GPIO_PIN_5  5
#define GPIO_PIN_6  6
#define GPIO_PIN_7  7


//Values for Mode parameter

#define INPUT_ANALOG        0b000000
#define INPUT_FLOATING      0b000100
#define INPUT_PP            0b101000

#define OUTPUT_PUSH_PULL    0b10000 //BIT IN THIRD POSITION IS TO LATER KNOW IF ITS AN OUTPUT OR AN INPUT
#define OUTPUT_OPEN_DRAIN   0b10100
#define AF_PUSH_PULL        0b11000
#define AF_OPEN_DRAIN       0b11100



//Values for Output speed
#define GPIO_SPEED_10MHZ    0b01
#define GPIO_SPEED_2MHZ     0b10
#define GPIO_SPEED_30MHZ    0b11

//Mask for CFRLG register
#define CFGLR_MASK              0xF

//Nibbles for modes
#define INPUT_ANALOG_NIBBLE     0b0000
#define INPUT_FLOATING_NIBBLE   0b0001
#define INPUT_PP_NIBBLE         0b0010

#define PULLDOWN                0b0
#define PULLUP                  0b1

#endif
