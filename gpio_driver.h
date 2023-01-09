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

/*
 * @see GPIO_Modes				// --------------------------------------------------------------------------- //
 */						// 		The mode for x pin depends on both: CNF register & MODEy reg:
// CNF register modes. If MODEy = 0		// --------------------------------------------------------------------------- //	
#define GPIO_CNF_IN_ANALOG		0	//		MODEy_IN && CNF ANALOG  		== 0000 = 0
#define GPIO_CNF_IN_FLOAT		1	//		MODEy_IN && CNF FLOAT   		== 0100 = 4 
#define GPIO_CNF_IN_PULL_UD		2	//		MODEy_IN && CNF PULL_UD 		== 1000 = 8 
#define GPIO_CNF_RESERVED		3	//		MODEy_IN && RESERVED 			== 1100 = 12    -------> This config shouldn't be set	
// CNF register modes. If MODEy > 0		//		
#define GPIO_CNF_OUT_PPULL		0	//		
#define GPIO_CNF_OUT_ODRAIN		1	//		MODEy_OUT 10Mhz && CNF OUT_PPULL  	== 0001 = 1
#define GPIO_CNF_ALTFN_PPULL		2	// -------	MODEy_OUT 10Mhz && CNF OUT_ODRAIN   	== 0101 = 5 
#define GPIO_CNF_ALTFN_ODRAIN		3	// -------      MODEy_OUT 10Mhz && CNF ALTFN_PPULL 	== 1001 = 9 
						// -------	MODEy_OUT 10Mhz && CNF ALTFN_ODRAIN 	== 1101 = 13 
// MODEy register modes				// -------              
#define GPIO_MODEy_IN			0	// -------      MODEy_OUT 2Mhz && CNF OUT_PPULL  	== 0010 = 2
#define GPIO_MODEy_OUT_10MHz		1	//              MODEy_OUT 2Mhz && CNF OUT_ODRAIN   	== 0110 = 6 
#define GPIO_MODEy_OUT_2MHz		2	//              MODEy_OUT 2Mhz && CNF ALTFN_PPULL 	== 1010 = 10
#define GPIO_MODEy_OUT_50MHz		3	//	        MODEy_OUT 2Mhz && CNF ALTFN_ODRAIN 	== 1110 = 14 
						//	
						//		MODEy_OUT 50Mhz && CNF OUT_PPULL  	== 0011 = 3 
						//              MODEy_OUT 50Mhz && CNF OUT_ODRAIN   	== 0111 = 7 
						//              MODEy_OUT 50Mhz && CNF ALTFN_PPULL 	== 1011 = 11 
       						//		MODEy_OUT 50Mhz && CNF ALTFN_ODRAIN 	== 1111 = 15
						// --------------------------------------------------------------------------- //	
						
#define MODE_IN_ANALOG				0
#define MODE_IN_FLOAT				4
#define MODE_IN_PULL_UD				8
#define RESERVED				12 // -------> This config shouldn't be set

#define MODE_OUT_2MHz_PPULL			2
#define MODE_OUT_2MHz_ODRAIN			6
#define MODE_OUT_2MHz_ALTFN_PPULL		10
#define MODE_OUT_2MHz_ALTFN_ODRAIN		14

#define MODE_OUT_10MHz_PPULL			1
#define MODE_OUT_10MHz_ODRAIN			5
#define MODE_OUT_10MHz_ALTFN_PPULL 		9
#define MODE_OUT_10MHz_ALTFN_ODRAIN		13

#define MODE_OUT_50MHz_PPULL			3
#define MODE_OUT_50MHz_ODRAIN			7
#define MODE_OUT_50MHz_ALTFN_PPULL		11
#define MODE_OUT_50MHz_ALTFN_ODRAIN		15

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/
/*
 * @see GPIO_PinConfig_t	
 */			
typedef struct{
	uint8_t 	Pin_Number;
	uint16_t 	Pin_Mode;
}GPIO_PinConfig_t;

/*
 * @see GPIO_Handle_t	
 */			
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
void GPIO_DeInit 		( GPIO_Handle_t *GPIO_X_Handle 						);
void GPIO_Reset			( GPIO_Handle_t *GPIO_X_Handle 						);
void GPIO_Clock_Control		( GPIO_RegStruct_t *pGPIO_X , Functional_state state 			);

// Read/Write functions
Logic_state GPIO_Read_Pin 	( GPIO_RegStruct_t *pGPIO_X , uint8_t pin_number 			);
uint16_t GPIO_Read_Port 	( GPIO_RegStruct_t *pGPIO_X 						);
void GPIO_Write_Pin 		( GPIO_RegStruct_t *pGPIO_X , uint8_t pin_number, Logic_state state 	);
void GPIO_Write_Port 		( GPIO_RegStruct_t *pGPIO_X , uint16_t states 				);
void GPIO_Toggle_Pin 		( GPIO_RegStruct_t *pGPIO_X , uint16_t pin_number 			);
void GPIO_Toggle_Port 		( GPIO_RegStruct_t *pGPIO_X 						);

// Interrput functions
void GPIO_IRQ_Config 		( uint8_t IRQ_number , uint8_t IRQ_priority, Functional_state state	);
void GPIO_IRQ_Handling 		( uint8_t Pin_number 							);

/*** End of File **************************************************************/	
#endif



