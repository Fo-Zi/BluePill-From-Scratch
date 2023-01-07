
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
	//TODO
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
