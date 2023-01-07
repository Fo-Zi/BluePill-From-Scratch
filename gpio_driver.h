/****************************************************************************
* Title                 :	GPIO header  
* Filename              :   	gpio_driver.h
* Author                :  	Zingarelli Facundo 
* Origin Date           :   	07/01/2023
* Version               :   	1.0.0
* Compiler              :   	TBD
* Target                :   	TBD
* Notes                 :   	None
*
*****************************************************************************/

/*****************************************************************************/
/** @file gpio_driver.h
 *  @brief API definition of GPIO driver.
 * 
 *  This is the header file for the definition of the GPIO driver interface. 
 */

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "STM32F103xx.h"
#include "generic.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

// General operational modes
#define GPIO_MODE_IN			 0
#define GPIO_MODE_OUT			 1
#define GPIO_MODE_ALTFN			 2
#define GPIO_MODE_ANALOG		 3
#define GPIO_MODE_IT_FALL	 	 4
#define GPIO_MODE_IT_RISI	 	 5
#define GPIO_MODE_IT_RF		 	 6

//#define GPIO_OUT_TYPE_PPULL 	0
//#define GPIO_OUT_TYPE_ODRAIN 	1

//#define GPIO_OUT_SPEED_MEDIUM 	0
//#define GPIO_OUT_SPEED_LOW 	1
//#define GPIO_OUT_SPEED_HIGH 	2

// CNF register modes -> Depends on MODEy reg.
#define GPIO_CNF_IN_ANALOG	0
#define GPIO_CNF_IN_FLOAT	1
#define GPIO_CNF_IN_PULL_UD	2

#define GPIO_CNF_OUT_PPULL	0
#define GPIO_CNF_OUT_ODRAIN	1
#define GPIO_CNF_ALTFN_PPULL	2
#define GPIO_CNF_ALTFN_ODRAIN	3

// MODEy register modes
#define GPIO_MODEy_IN			0
#define GPIO_MODEy_OUT_10MHz		1
#define GPIO_MODEy_OUT_2MHz		2
#define GPIO_MODEy_OUT_50MHz		3

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/

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

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

// Config functions
void GPIO_Init 			( GPIO_Handle_t *GPIO_X_Handle 						);
void GPIO_Reset			( GPIO_Handle_t *GPIO_X_Handle 						);
void GPIO_Clock_Control		( GPIO_RegStruct_t *pGPIO_X , Functional_state state 			);

// Read/Write functions
Logic_state GPIO_Read_Pin 	( GPIO_RegStruct_t *pGPIO_X , uint8_t pin_number 			);
uint16_t GPIO_Read_Port 	( GPIO_RegStruct_t *pGPIO_X 						);
void GPIO_Write_Pin 		( GPIO_RegStruct_t *pGPIO_X , uint8_t pin_number, Logic_state state 	);
void GPIO_Write_Port 		( GPIO_RegStruct_t *pGPIO_X , uint16_t states 				);
void GPIO_Toggle_Pin 		( GPIO_RegStruct_t *pGPIO_X , uint8_t pin_number 			);
void GPIO_Toggle_Port 		( GPIO_RegStruct_t *pGPIO_X 						);

// Interrput functions
void GPIO_IRQ_Config 		( uint8_t IRQ_number , uint8_t IRQ_priority, Functional_state state	);
void GPIO_IRQ_Handling 		( uint8_t Pin_number 							);

/*** End of File **************************************************************/	
#endif



