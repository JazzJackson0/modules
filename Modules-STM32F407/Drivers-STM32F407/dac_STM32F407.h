//STM32F407 Driver
#ifndef DAC_H_
#define DAC_H_

#include <stdint.h>

void DAC_Init(uint8_t dacNum);
int16_t DAC_Out(uint8_t dacNum, int16_t digitalData);


#define CLOCK 0x40023800
#define APB1 0x40
#define DAC 0x40007400

//CLOCK
#define ADDR_DAC_CLOCK ( (DAC_CLOCK*) ((CLOCK) + APB1) )

#define ADDR_DAC_CONTROL ( (DAC_CONTROL*) ((DAC) + 0x00) )
#define ADDR_DAC_SOFTWARE_TRIGGER ( (DAC_SOFTWARE_TRIGGER*) ((DAC) + 0x04) )
//ch1
#define ADDR_DAC_CH1_12BIT_RIGHTALIGNED_DATAHOLD ( (DAC_CHx_12BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x08) )
#define ADDR_DAC_CH1_12BIT_LEFTALIGNED_DATAHOLD ( (DAC_CHx_12BIT_LEFTALIGNED_DATAHOLD*) ((DAC) + 0x0C) )
#define ADDR_DAC_CH1_8BIT_RIGHTALIGNED_DATAHOLD ( (DAC_CHx_8BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x10) )
#define ADDR_DAC_CH1_DATA_OUTPUT ( (DAC_CH1_DATA_OUTPUT*) ((DAC) + 0x2C) )
//ch2
#define ADDR_DAC_CH2_12BIT_RIGHTALIGNED_DATAHOLD ( (DAC_CHx_12BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x14) )
#define ADDR_DAC_CH2_12BIT_LEFTALIGNED_DATAHOLD ( (DAC_CHx_12BIT_LEFTALIGNED_DATAHOLD*) ((DAC) + 0x18) )
#define ADDR_DAC_CH2_8BIT_RIGHTALIGNED_DATAHOLD ( (DAC_CHx_8BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x1C) )
#define ADDR_DAC_CH2_DATA_OUTPUT ( (DAC_CH2_DATA_OUTPUT*) ((DAC) + 0x30) )

#define ADDR_DAC_DUAL_12BIT_RIGHTALIGNED_DATAHOLD ( (DAC_DUAL_12BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x20) )
#define ADDR_DAC_DUAL_12BIT_LEFTALIGNED_DATAHOLD ( (DAC_DUAL_12BIT_LEFTALIGNED_DATAHOLD*) ((DAC) + 0x24) )
#define ADDR_DAC_DUAL_8BIT_RIGHTALIGNED_DATAHOLD ( (DAC_DUAL_8BIT_RIGHTALIGNED_DATAHOLD*) ((DAC) + 0x28) )
#define ADDR_DAC_STATUS ( (DAC_STATUS*) ((DAC) + 0x34) )

//DAC_CONTROL Register
/*DAC Trigger Type*/
#define DAC_TIM6_TRGO 0x00
#define DAC_TIM8_TRGO 0x01
#define DAC_TIM7_TRGO 0x02
#define DAC_TIM5_TRGO 0x03
#define DAC_TIM2_TRGO 0x04
#define DAC_TIM4_TRGO 0x05
#define DAC_EXTERNAL_LINE9 0x06
#define DAC_SOFTWARE_TRIG 0x07

/*Wave Generation*/
#define WAVE_DISABLED 0x00
#define NOISE_WAVE 0x01
#define TRIANGLE_WAVE 0x02

/*Mask Selector Amplitude Selector*/
#define UNMASKBIT0_TRIANGLEAMP1 0x00
#define UNMASKBIT0_1_TRIANGLEAMP3 0x01
#define UNMASKBIT0_2_TRIANGLEAMP7 0x02
#define UNMASKBIT0_3_TRIANGLEAMP15 0x03
#define UNMASKBIT0_4_TRIANGLEAMP31 0x04
#define UNMASKBIT0_5_TRIANGLEAMP63 0x05
#define UNMASKBIT0_6_TRIANGLEAMP127 0x06
#define UNMASKBIT0_7_TRIANGLEAMP255 0x07
#define UNMASKBIT0_8_TRIANGLEAMP511 0x08
#define UNMASKBIT0_9_TRIANGLEAMP1023 0x09
#define UNMASKBIT0_10_TRIANGLEAMP2047 0x0A
#define UNMASKBIT0_11_TRIANGLEAMP4095 0x0B


typedef struct {
	const uint32_t reserved0:29;
	volatile uint32_t dac_StartTick:1;
	const uint32_t reserved1:2;
}DAC_CLOCK;

typedef struct {
	volatile uint32_t enable_DACChannel1:1;
	volatile uint32_t disable_Channel1OutputBuffer:1;
	volatile uint32_t enable_Channel1Trigger:1;
	volatile uint32_t rw_Channel1Trigger:3;
	volatile uint32_t enable_Channel1NoiseWaveTriangleWave:2;
	volatile uint32_t rw_Channel1MaskSelectorAmpSelector:4;
	volatile uint32_t enable_Channel1DMA:1;
	volatile uint32_t enable_Channel1UnderrunInterrupt:1;
	volatile uint32_t reserved0:2;
	
	volatile uint32_t enable_DACChannel2:1;
	volatile uint32_t disable_Channel2OutputBuffer:1;
	volatile uint32_t enable_Channel2Trigger:1;
	volatile uint32_t rw_Channel2Trigger:3;
	volatile uint32_t enable_Channel2NoiseWaveTriangleWave:2;
	volatile uint32_t rw_Channel2MaskSelectorAmpSelector:4;
	volatile uint32_t enable_Channel2DMA:1;
	volatile uint32_t enable_Channel2UnderrunInterrupt:1;
	volatile uint32_t reserved1:2;
}DAC_CONTROL;


typedef struct {
	volatile uint32_t enable_Channel1SoftwareTrigger:1;
	volatile uint32_t enable_Channel2SoftwareTrigger:1;
	const uint32_t reserved:30;
}DAC_SOFTWARE_TRIGGER;


typedef struct {
	volatile uint32_t rw_RightAlignedData12Bit:12;
	const uint32_t reserved:20;
}DAC_CHx_12BIT_RIGHTALIGNED_DATAHOLD;


typedef struct {
	const uint32_t reserved0:4;
	volatile uint32_t rw_LeftAlignedData12Bit:12;
	const uint32_t reserved1:16;
}DAC_CHx_12BIT_LEFTALIGNED_DATAHOLD;


typedef struct {
	volatile uint32_t rw_RightAlignedData8Bit:8;
	const uint32_t reserved:24;
}DAC_CHx_8BIT_RIGHTALIGNED_DATAHOLD;


typedef struct {
	volatile uint32_t rw_Channel1RightAlignedData12Bit:12;
	const uint32_t reserved0:4;
	volatile uint32_t rw_Channel2RightAlignedData12Bit:12;
	const uint32_t reserved1:4;
}DAC_DUAL_12BIT_RIGHTALIGNED_DATAHOLD;


typedef struct {
	const uint32_t reserved0:4;
	volatile uint32_t rw_Channel1LeftAlignedData12Bit:12;
	const uint32_t reserved1:4;
	volatile uint32_t rw_Channel2LefttAlignedData12Bit:12;
}DAC_DUAL_12BIT_LEFTALIGNED_DATAHOLD;


typedef struct {
	volatile uint32_t rw_Channel1RightAlignedData8Bit:8;
	volatile uint32_t rw_Channel2RightAlignedData8Bit:8;
	const uint32_t reserved:16;
}DAC_DUAL_8BIT_RIGHTALIGNED_DATAHOLD;


typedef struct {
	volatile uint32_t read_Channel1DataOutput:12;
	const uint32_t reserved:20;
}DAC_CH1_DATA_OUTPUT;


typedef struct {
	volatile uint32_t read_Channel2DataOutput:12;
	const uint32_t reserved:20;
}DAC_CH2_DATA_OUTPUT;


typedef struct {
	const uint32_t reserved0:13;
	volatile uint32_t channel1UnderrunOccurred:1;
	const uint32_t reserved1:15;
	volatile uint32_t channel2UnderrunOccurred:1;
	const uint32_t reserved2:2;
}DAC_STATUS;


#endif
