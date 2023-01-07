
#include "STM32F103xx.h"
#include "generic.h"
#include "gpio_driver.h"

void GPIO_Init(GPIO_Handle_t *GPIO_X_Handle){
	//TODO
};

void GPIO_Reset(GPIO_Handle_t *GPIO_X_Handle){
	//TODO
};

void GPIO_Clock_Control(GPIO_RegStruct_t *pGPIO_X , State state ){
	if(state == ENABLE){
		if( pGPIO_X==GPIO_A ){
			GPIO_A_CLK_ENABLE();
		}else if(pGPIO_X==GPIO_B){
			GPIO_B_CLK_ENABLE();
		}else if(pGPIO_X==GPIO_C){
			GPIO_C_CLK_ENABLE();
		}else if(pGPIO_X==GPIO_D){
			GPIO_D_CLK_ENABLE();
		}else if(pGPIO_X==GPIO_E){
			GPIO_E_CLK_ENABLE();
		}
	}else{
		if( pGPIO_X==GPIO_A ){
			GPIO_A_CLK_DISABLE();
		}else if(pGPIO_X==GPIO_B){
			GPIO_B_CLK_DISABLE();
		}else if(pGPIO_X==GPIO_C){
			GPIO_C_CLK_DISABLE();
		}else if(pGPIO_X==GPIO_D){
			GPIO_D_CLK_DISABLE();
		}else if(pGPIO_X==GPIO_E){
			GPIO_E_CLK_DISABLE();
		}
	}	
};

Logic_state GPIO_Read_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number ){
	//TODO
};

uint16_t GPIO_Read_Port( GPIO_RegStruct_t *pGPIO_X ){
	//TODO
};

void GPIO_Write_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number, Logic_state state ){
	//TODO
};

void GPIO_Write_Port( GPIO_RegStruct_t *pGPIO_X,  uint16_t states ){
	//TODO
};

void GPIO_Toggle_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number ){
	//TODO
};

void GPIO_Toggle_Port( GPIO_RegStruct_t *pGPIO_X ){
	//TODO
};

void GPIO_IRQ_Config(uint8_t IRQ_number, uint8_t IRQ_priority, State state){
	//TODO
};

void GPIO_IRQ_Handling(uint8_t Pin_number){
	//TODO
};
