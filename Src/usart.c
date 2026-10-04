
#include "usart.h"
#include "gpio.h"
#include "rcc.h"

void USARTInit(USART_t* pUSART, USART_Config* pConfig)
{
    //GPIO_Config RxGpio;

    GPIOxClockControl(GPIOD);

    GPIO_Config TxGpio;
    
    GPIOxClockControl(GPIOD);
    TxGpio.Pin = GPIO_PIN_5;
    TxGpio.Mode = AF_PUSH_PULL;
    TxGpio.Speed = GPIO_SPEED_30MHZ;
    
    GPIOInit(GPIOD, &TxGpio);
    
    GPIOD->CFGLR &= ~(0xF << 24);
    GPIOD->CFGLR |= (0b0100 << 24);
    
    
    USARTClockControl(USART);
    
    
    //Data bits
    USART->CTLR1 &= ~(0x1 << 12);
    USART->CTLR1 |= (pConfig->DataSize << 12);
    

    //Parity
    if(pConfig->Parity == EVEN_PARITY || pConfig->Parity == ODD_PARITY)
    {
        USART->CTLR1 |= (0x1 << 10);
        USART->CTLR1 &= ~(0x1 << 9);
        USART->CTLR1 |= (pConfig->Parity << 9);
    }
    else
    {

        USART->CTLR1 &= ~(0x1 << 10);
    }


    //NoStopBits
    USART->CTLR2 &= ~(0x3 << 12);
    USART->CTLR2 |= (pConfig->NoStopBits << 12);
    
    
    //Baudrate
    USART->BRR = pConfig->Baudrate;   

    //Tx Enable
    USART->CTLR1 |= (0x1 << 3);

    //Rx Enable
    USART->CTLR1 |= (0x1 << 2);

    //Usart Enable
    USART->CTLR1 |= (0x1 << 13);
}

void UsartSendByte(uint8_t* pByte, USART_t* pUSART)
{
    while(!(UsartFlagStatus(USART_TXE_FLAG, USART)));

    pUSART->DATAR = *pByte;

}

void UsartRxByte(uint8_t* byte,USART_t* pUSART)
{
    while(!(UsartFlagStatus(USART_RXNE_FLAG, USART)));
    *byte = pUSART->DATAR;
}
uint8_t UsartFlagStatus(uint8_t usartflag,USART_t* pUSART)
{
    if(pUSART->STATR & usartflag)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

