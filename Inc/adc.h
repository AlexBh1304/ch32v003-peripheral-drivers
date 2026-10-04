#ifndef ADC_H
#define ADC_H

#include "ch32v003.h"

typedef struct
{
    uint8_t SampleTime;
    uint8_t DataAlignment;
    uint8_t ContinuousConversion;
    uint8_t ExternalTrigger;

}ADC_Config;



void ADCInit(ADC_t* pADC, ADC_Config* AdcConfig);
uint16_t ADCRead(ADC_t* pADC);

#define EXTSEL_TRGO_T1     0b000   
#define EXTSEL_CC1_T1      0b001   
#define EXTSEL_CC2_T1      0b010   
#define EXTSEL_TRGO_T2     0b011   
#define EXTSEL_CC1_T2      0b100   
#define EXTSEL_CC2_T2      0b101   
#define EXTSEL_PD3_PC2     0b110   
#define EXTSEL_SWSTART     0b111

#define DATA_RIGHT_ALIGNED      0   
#define DATA_LEFT_ALIGNED       1   

#define SAMPLE_TIME_3_CYCLES      0b000   
#define SAMPLE_TIME_9_CYCLES      0b001   
#define SAMPLE_TIME_15_CYCLES     0b010   
#define SAMPLE_TIME_30_CYCLES     0b011   
#define SAMPLE_TIME_43_CYCLES     0b100   
#define SAMPLE_TIME_57_CYCLES     0b101   
#define SAMPLE_TIME_73_CYCLES     0b110   
#define SAMPLE_TIME_241_CYCLES    0b111   


#endif
