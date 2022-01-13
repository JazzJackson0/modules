#include <stdint.h>
//#include <stdio.h>
#include "adc_ATmega328.h"


//Global Variables-------------------------------------------------------
//ADC
POWER_REDUCTION_ADC *const ADCPower = ADDR_POWER_REDUCTION_ADC;
ADCx *const ADC = ADDR_ADC;

/**
- Arduino Uno Clock Speed
		+ATmega defaults to 8MHz RC Prescaled to 1MHz
		+Arduino Uno Board overrides ATmega and defaults to 16MHz external xtal oscillator 
**/
void ADC_Init_and_Start(E_Channel channel, E_ADCClockDivide clockDivide, E_AutoTrigSrc autoTrigSrc) {
	
	ADCPower->adcOn0_adcOff1 = 0;
	
	ADC->MutexSelectReg.rw_AnalogChannel = channel;
	ADC->MutexSelectReg.rightAdjustedADCResult0_leftAdjustedADCResult1 = 0;
	ADC->ControlStatusAReg.rw_PrescalerValue = clockDivide;
	
	ADC->ControlStatusAReg.enable_ADC = 1;
	
	ADC->ControlStatusBReg.rw_AutoTriggerSource = autoTrigSrc;
	ADC->ControlStatusAReg.enable_ADCAutoTrigger = 1;
	
	ADC->ControlStatusAReg.start_ADCConversion = 1; //Starts the first conversion in Free Run Mode
}

int16_t ADC_Read(void) {

	while (ADC->ControlStatusAReg.start_ADCConversion == 1);
	uint8_t low = ADC->DataLowReg.RightAdjust.read_ADCConversionResult;
	uint8_t high = ADC->DataHighReg.RightAdjust.read_ADCConversionResult;
	
	return (uint16_t) high | low; //Test this type of return
}

