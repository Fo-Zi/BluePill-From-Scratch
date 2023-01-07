#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H
	
	#include "STM32F103xx.h"
	#include "generic.h"

	typedef struct{
		uint8_t Pin_Number;
		uint8_t Pin_Mode;
		uint8_t Pin_Speed;
		uint8_t Pin_PuPdControl;
		uint8_t Pin_OPType;
		uint8_t Pin_AltFunct_Mode;
	}GPIO_PinConfig_t;

	typedef struct{
		GPIO_RegStruct_t *pGPIO_X;
		GPIO_PinConfig_t GPIO_PinConfig;
	}GPIO_Handle_t;

	void GPIO_Init(GPIO_Handle_t *GPIO_X_Handle);
	void GPIO_Reset(GPIO_Handle_t *GPIO_X_Handle);
	void GPIO_Clock_Control(GPIO_RegStruct_t *pGPIO_X , State state );

	Logic_state GPIO_Read_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number );
	uint16_t GPIO_Read_Port( GPIO_RegStruct_t *pGPIO_X );
	void GPIO_Write_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number, Logic_state state );
	void GPIO_Write_Port( GPIO_RegStruct_t *pGPIO_X,  uint16_t states );
	void GPIO_Toggle_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number );
	void GPIO_Toggle_Port( GPIO_RegStruct_t *pGPIO_X );
	
	void GPIO_IRQ_Config(uint8_t IRQ_number, uint8_t IRQ_priority, State state);
	void GPIO_IRQ_Handling(uint8_t Pin_number);

#endif
