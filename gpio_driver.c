/****************************************************************************
* Title                 :	GPIO source  
* Filename              :   	gpio_driver.c
* Author                :  	Zingarelli Facundo 
* Origin Date           :   	87/01/2023
* Version               :   	1.0.0
* Compiler              :   	TBD
* Target                :   	TBD
* Notes                 :   	None
*
*****************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include "STM32F103xx.h"
#include "generic.h"
#include "gpio_driver.h"

/******************************************************************************
* Function Definitions
*******************************************************************************/

/******************************************************************************
* Function : ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
* @see GPIO_Modes
*
*******************************************************************************/
void GPIO_Init(GPIO_Handle_t *GPIO_X_Handle){
	uint8_t mode_temp = GPIO_X_Handle->GPIO_PinConfig.Pin_Mode ;
	uint8_t pinNumber_temp = GPIO_X_Handle->GPIO_PinConfig.Pin_Number ;
	if( pinNumber_temp < 7 ){
		 ( GPIO_X_Handle->pGPIO_X )->CRL |= mode_temp << ( 4 * (pinNumber_temp)) ; 					
	}else{
		 ( GPIO_X_Handle->pGPIO_X )->CRL |= mode_temp << ( 4 * ( pinNumber_temp - 8 )) ; 					
	}
	
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_DeInit(GPIO_Handle_t *GPIO_X_Handle){
	if( GPIO_X_Handle -> pGPIO_X==GPIO_A ){
		GPIO_A_REG_RESET();

	}else if(GPIO_X_Handle -> pGPIO_X==GPIO_B){
		GPIO_B_REG_RESET();

	}else if(GPIO_X_Handle -> pGPIO_X==GPIO_C){
		GPIO_C_CLK_ENABLE();
		
	}else if(GPIO_X_Handle -> pGPIO_X==GPIO_D){
		GPIO_D_CLK_ENABLE();

	}else if(GPIO_X_Handle -> pGPIO_X==GPIO_E){
		GPIO_E_CLK_ENABLE();

	}
};


/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_RegStruct_t
* @see Clock_Enable_Macros
* @see Clock_Disable_Macros
*
*******************************************************************************/
void GPIO_Clock_Control( GPIO_RegStruct_t *pGPIO_X , Functional_state state ){
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

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_RegStruct_t
*
*******************************************************************************/
Logic_state GPIO_Read_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number ){
	Logic_state ls = (uint8_t) ((( pGPIO_X -> IDR ) >> pin_number ) & 0x1 )  ;	
	return ls;
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	uint16_t -> An array of logical values expressed as an integer of 16 bits.
*
* @see GPIO_RegStruct_t
*
*******************************************************************************/
uint16_t GPIO_Read_Port( GPIO_RegStruct_t *pGPIO_X ){
	uint16_t LStates_arr = (uint16_t) ( pGPIO_X -> IDR )     ;	
	return LStates_arr;
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_Write_Pin( GPIO_RegStruct_t *pGPIO_X, uint8_t pin_number, Logic_state state ){
	if( state == 1 ){
		pGPIO_X -> ODR |= (uint16_t) ( 1 << pin_number  );	
	}else if(state == 0){
		pGPIO_X -> ODR &= (uint16_t) ~( 1 << pin_number  );	
	}
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_Write_Port( GPIO_RegStruct_t *pGPIO_X,  uint16_t states ){
	pGPIO_X -> ODR =  states;	
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_Toggle_Pin( GPIO_RegStruct_t *pGPIO_X, uint16_t pin_number ){
	pGPIO_X -> ODR ^= (uint16_t) ( 1 << pin_number ) ; 
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_Toggle_Port( GPIO_RegStruct_t *pGPIO_X ){
	pGPIO_X -> ODR ^= 0xFFFF;	
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
* This function initializes/configures the PORTx, given a pointer to its corresponding 
*  handle.
*  
* PRE-CONDITION: Configuration struct needs to populated in order to have some effect. <br>
*
* POST-CONDITION: The GPIO peripheral is setup with the configuration settings.
*
* @param  	GPIO_X_Handle is a pointer to the configuration struct that contains
*		a pointer to the struct registers common to all ports, and a pin config struct
*		that holds the operation modes and pin number.
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_IRQ_Config(uint8_t IRQ_number, uint8_t IRQ_priority, State state){
	//TODO
};

/******************************************************************************
* Function :  ()
*//** 
* \b Description:
*  
* PRE-CONDITION: 
*
* POST-CONDITION: 
*
* @param  	
*		
*		
*
* @return 	void
*
* @see GPIO_Handle_t 
* @see GPIO_PinConfig_t 
* @see GPIO_RegStruct_t
*
*******************************************************************************/
void GPIO_IRQ_Handling(uint8_t Pin_number){
	//TODO
};

/*** End of File **************************************************************/	
