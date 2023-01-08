#ifndef STM32F103XX_H
#define STM32F103XX_H
	
	/*--------------- INCLUDES AND READABILITY DEFINES  ---------------*/
	#include <stdint.h>
	
	#define __vo volatile


	/*--------------- MEMORY AND BUSES BASE ADDRESSES  ---------------*/
	/*
         * @see Memory_Base_Addresses	
         */
	#define FLASH_BASE_ADDR 	0x08000000UL
	#define SRAM_BASE_ADDR		0x20000000UL
	#define ROM_BASE_ADDR		0x1FFFF000UL

	/*
	 * @see Buses_Base_Addresses	
	 */
	#define AHB_BASE_ADDR		0x40020000UL
	#define APB_1_BASE_ADDR		0x40000000UL
	#define APB_2_BASE_ADDR		0x40010000UL
	
	/*--------------- AHB PERIPHERALS BASE ADDRESSES  ---------------*/
	/*
	 * @see AHB_Peripherals_Base_Addresses	
	 */
	#define DMA_1_BASE_ADDR		AHB_BASE_ADDR 
	#define RCC_BASE_ADDR		( AHB_BASE_ADDR + 0x1000U ) 
	#define FLASH_INTERF_BASE_ADDR	( AHB_BASE_ADDR + 0x2000U ) 
	#define CRC_BASE_ADDR		( AHB_BASE_ADDR + 0x3000U ) 

	
	/*--------------- APB1 PERIPHERALS BASE ADDRESSES  ---------------*/
	/*
	 * @see APB1_Peripherals_Base_Addresses	
	 */
	#define TIM_2_BASE_ADDR		APB_1_BASE_ADDR	
	#define TIM_3_BASE_ADDR		( APB_1_BASE_ADDR + 0x400U )
	#define TIM_4_BASE_ADDR		( APB_1_BASE_ADDR + 0x800U )
	#define TIM_6_BASE_ADDR		( APB_1_BASE_ADDR + 0x1000U )
	#define TIM_7_BASE_ADDR		( APB_1_BASE_ADDR + 0x1400U )
	#define RTC_BASE_ADDR		( APB_1_BASE_ADDR + 0x2800U )
	#define WWDG_BASE_ADDR		( APB_1_BASE_ADDR + 0x2C00U )
	#define IWDG_BASE_ADDR		( APB_1_BASE_ADDR + 0x3000U )
	#define SPI_2_BASE_ADDR		( APB_1_BASE_ADDR + 0x3800U )
	#define USART_2_BASE_ADDR	( APB_1_BASE_ADDR + 0x4400U )
	#define USART_3_BASE_ADDR	( APB_1_BASE_ADDR + 0x4800U )
	#define I2C_1_BASE_ADDR		( APB_1_BASE_ADDR + 0x5400U )
	#define I2C_2_BASE_ADDR		( APB_1_BASE_ADDR + 0x5800U )
	#define BKP_BASE_ADDR		( APB_1_BASE_ADDR + 0x6C00U )
	#define PWR_BASE_ADDR		( APB_1_BASE_ADDR + 0x7000U )
	#define DAC_BASE_ADDR		( APB_1_BASE_ADDR + 0x7400U )
	#define CEC_BASE_ADDR		( APB_1_BASE_ADDR + 0x7800U )
	
	/*--------------- APB2 PERIPHERALS BASE ADDRESSES  ---------------*/
	/*
	 * @see APB2_Peripherals_Base_Addresses	
	 */
	#define AFIO_BASE_ADDR 		APB_2_BASE_ADDR 
	#define EXTI_BASE_ADDR 		( APB_2_BASE_ADDR + 0x0400U ) 
	#define GPIO_A_BASE_ADDR 	( APB_2_BASE_ADDR + 0x0800U ) 
	#define GPIO_B_BASE_ADDR 	( APB_2_BASE_ADDR + 0x0C00U ) 
	#define GPIO_C_BASE_ADDR 	( APB_2_BASE_ADDR + 0x1000U ) 
	#define GPIO_D_BASE_ADDR 	( APB_2_BASE_ADDR + 0x1400U ) 
	#define GPIO_E_BASE_ADDR 	( APB_2_BASE_ADDR + 0x1800U ) 
	#define ADC_1_BASE_ADDR 	( APB_2_BASE_ADDR + 0x2400U ) 
	#define TIM_1_BASE_ADDR 	( APB_2_BASE_ADDR + 0x2C00U ) 
	#define SPI_1_BASE_ADDR 	( APB_2_BASE_ADDR + 0x3000U ) 
	#define USART_1_BASE_ADDR 	( APB_2_BASE_ADDR + 0x3800U ) 
	#define TIM_15_BASE_ADDR 	( APB_2_BASE_ADDR + 0x4000U ) 
	#define TIM_16_BASE_ADDR 	( APB_2_BASE_ADDR + 0x4400U ) 
	#define TIM_17_BASE_ADDR 	( APB_2_BASE_ADDR + 0x4800U ) 

	/*--------------- GPIO REGISTER's STRUCT  ---------------*/
	/*
	 * @see GPIO_RegStruct_t	
	 */			
	typedef struct{
		__vo uint32_t CRL;	
		__vo uint32_t CRH;	
		__vo uint32_t IDR;	
		__vo uint32_t ODR;	
		__vo uint32_t BSR;	
		__vo uint32_t BRR;	
		__vo uint32_t LCKR;	
	}GPIO_RegStruct_t;
	
	/*--------------- GPIO PORTS DEF ---------------*/
	#define GPIO_A 		( (GPIO_RegStruct_t*) GPIO_A_BASE_ADDR )	
	#define GPIO_B 		( (GPIO_RegStruct_t*) GPIO_B_BASE_ADDR )	
	#define GPIO_C 		( (GPIO_RegStruct_t*) GPIO_C_BASE_ADDR )	
	#define GPIO_D 		( (GPIO_RegStruct_t*) GPIO_D_BASE_ADDR )	
	#define GPIO_E 		( (GPIO_RegStruct_t*) GPIO_E_BASE_ADDR )	


	/*--------------- RCC REGISTER's STRUCT  ---------------*/
	/*
	 * @see RCC_RegStruct_t	
	 */			
	typedef struct{
		__vo uint32_t CR;	
		__vo uint32_t CFGR;	
		__vo uint32_t CIR;	
		__vo uint32_t APB2RSTR;	
		__vo uint32_t APB1RSTR;	
		__vo uint32_t AHBENR;	
		__vo uint32_t APB2ENR;	
		__vo uint32_t APB1ENR;	
		__vo uint32_t BDCR;	
		__vo uint32_t CSR;
		__vo uint32_t CFGR2;	
	}RCC_RegStruct_t;
	
	/*--------------- RCC REGISTER's DEF ---------------*/
	#define RCC 		( (RCC_RegStruct_t*) RCC_BASE_ADDR )	


	/*
	 * @see Clock_Enable_Macros	
	 */			
	/*--------------- APB2 CLOCK ENABLE MACROS ---------------*/
	#define AFIO_CLK_ENABLE()	( RCC->APB2ENR |= 1<<0 )
	#define GPIO_A_CLK_ENABLE()	( RCC->APB2ENR |= 1<<2 )
	#define GPIO_B_CLK_ENABLE()	( RCC->APB2ENR |= 1<<3 )
	#define GPIO_C_CLK_ENABLE()	( RCC->APB2ENR |= 1<<4 )
	#define GPIO_D_CLK_ENABLE()	( RCC->APB2ENR |= 1<<5 )
	#define GPIO_E_CLK_ENABLE()	( RCC->APB2ENR |= 1<<6 )
	//#define GPIO_F_CLK_ENABLE()	( RCC->APB2ENR |= 1<<7 )    		PORT F y G?
	//#define GPIO_G_CLK_ENABLE()	( RCC->APB2ENR |= 1<<8 )
	#define ADC_1_CLK_ENABLE()	( RCC->APB2ENR |= 1<<9 )
	#define TIM_1_CLK_ENABLE()	( RCC->APB2ENR |= 1<<11 )
	#define SPI_1_CLK_ENABLE()	( RCC->APB2ENR |= 1<<12 )
	#define USART_1_CLK_ENABLE()	( RCC->APB2ENR |= 1<<14 )
	#define TIM_15_CLK_ENABLE()	( RCC->APB2ENR |= 1<<16 )
	#define TIM_16_CLK_ENABLE()	( RCC->APB2ENR |= 1<<17 )
	#define TIM_17_CLK_ENABLE()	( RCC->APB2ENR |= 1<<18 )
	

	/*--------------- APB1 CLOCK ENABLE MACROS ---------------*/
	#define TIM_2_CLK_ENABLE()	( RCC->APB1ENR |= 1<<0 )
	#define TIM_3_CLK_ENABLE()	( RCC->APB1ENR |= 1<<1 )
	#define TIM_4_CLK_ENABLE()	( RCC->APB1ENR |= 1<<2 )
	#define TIM_5_CLK_ENABLE()	( RCC->APB1ENR |= 1<<3 )
	#define TIM_6_CLK_ENABLE()	( RCC->APB1ENR |= 1<<4 )
	#define TIM_7_CLK_ENABLE()	( RCC->APB1ENR |= 1<<5 )
	#define TIM_12_CLK_ENABLE()	( RCC->APB1ENR |= 1<<6 )
	#define TIM_13_CLK_ENABLE()	( RCC->APB1ENR |= 1<<7 )
	#define TIM_14_CLK_ENABLE()	( RCC->APB1ENR |= 1<<8 )
	#define WWD_CLK_ENABLE()	( RCC->APB1ENR |= 1<<11 )
	#define SPI_2_CLK_ENABLE()	( RCC->APB1ENR |= 1<<14 )
	#define SPI_3_CLK_ENABLE()	( RCC->APB1ENR |= 1<<15 )
	#define USART_2_CLK_ENABLE()	( RCC->APB1ENR |= 1<<17 )
	#define USART_3_CLK_ENABLE()	( RCC->APB1ENR |= 1<<18 )
	#define USART_4_CLK_ENABLE()	( RCC->APB1ENR |= 1<<19 )
	#define USART_5_CLK_ENABLE()	( RCC->APB1ENR |= 1<<20 )
	#define I2C_1_CLK_ENABLE()	( RCC->APB1ENR |= 1<<21 )
	#define I2C_2_CLK_ENABLE()	( RCC->APB1ENR |= 1<<22 )
	#define BKP_CLK_ENABLE()	( RCC->APB1ENR |= 1<<27 )
	#define PWR_CLK_ENABLE()	( RCC->APB1ENR |= 1<<28 )
	#define DAC_CLK_ENABLE()	( RCC->APB1ENR |= 1<<29 )
	#define CEC_CLK_ENABLE()	( RCC->APB1ENR |= 1<<30 )

	/*--------------- AHB CLOCK ENABLE MACROS ---------------*/
	#define DMA_1_CLK_ENABLE()	( RCC->AHBENR |= 1<<0 )
	#define DMA_2_CLK_ENABLE()	( RCC->AHBENR |= 1<<1 )
	#define SRAM_CLK_ENABLE()	( RCC->AHBENR |= 1<<2 )
	#define FLITF_CLK_ENABLE()	( RCC->AHBENR |= 1<<4 )
	#define CRC_CLK_ENABLE()	( RCC->AHBENR |= 1<<6 )
	#define FSMC_CLK_ENABLE()	( RCC->AHBENR |= 1<<8 )


	/*
	 * @see Clock_Disable_Macros	
	 */			
	/*--------------- APB2 CLOCK DISABLE MACROS ---------------*/
	#define AFIO_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<0 ) )
	#define GPIO_A_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<2 ) )
	#define GPIO_B_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<3 ) )
	#define GPIO_C_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<4 ) )
	#define GPIO_D_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<5 ) )
	#define GPIO_E_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<6 ) )
	//#define GPIO_F_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<7 ) )    		PORT F y G?
	//#define GPIO_G_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<8 ) )
	#define ADC_1_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<9 ) )
	#define TIM_1_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<11 ) )
	#define SPI_1_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<12 ) )
	#define USART_1_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<14 ) )
	#define TIM_15_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<16 ) )
	#define TIM_16_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<17 ) )
	#define TIM_17_CLK_DISABLE()	( RCC->APB2ENR &= ~( 1<<18 ) )
	

	/*--------------- APB1 CLOCK DISABLE MACROS ---------------*/
	#define TIM_2_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<0 ) )
	#define TIM_3_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<1 ) )
	#define TIM_4_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<2 ) )
	#define TIM_5_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<3 ) )
	#define TIM_6_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<4 ) )
	#define TIM_7_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<5 ) )
	#define TIM_12_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<6 ) )
	#define TIM_13_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<7 ) )
	#define TIM_14_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<8 ) )
	#define WWD_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<11 ) )
	#define SPI_2_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<14 ) )
	#define SPI_3_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<15 ) )
	#define USART_2_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<17 ) )
	#define USART_3_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<18 ) )
	#define USART_4_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<19 ) )
	#define USART_5_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<20 ) )
	#define I2C_1_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<21 ) )
	#define I2C_2_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<22 ) )
	#define BKP_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<27 ) )
	#define PWR_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<28 ) )
	#define DAC_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<29 ) )
	#define CEC_CLK_DISABLE()	( RCC->APB1ENR &= ~( 1<<30 ) )

	/*--------------- AHB CLOCK DISABLE MACROS ---------------*/
	#define DMA_1_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<0 ) )
	#define DMA_2_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<1 ) )
	#define SRAM_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<2 ) )
	#define FLITF_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<4 ) )
	#define CRC_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<6 ) )
	#define FSMC_CLK_DISABLE()	( RCC->AHBENR &= ~( 1<<8 ) )

	/*--------------- GPIO PORTS RESET MACROS  ---------------*/
	/*
         * @see GPIO_Reg_Reset_Macros	
         */			
	#define GPIO_A_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 2 ); ( RCC-> APB2RSTR &= ~( 1 << 2 )); } while (0)
	#define GPIO_B_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 3 ); ( RCC-> APB2RSTR &= ~( 1 << 3 )); } while (0)
	#define GPIO_C_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 4 ); ( RCC-> APB2RSTR &= ~( 1 << 4 )); } while (0)
	#define GPIO_D_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 5 ); ( RCC-> APB2RSTR &= ~( 1 << 5 )); } while (0)
	#define GPIO_E_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 6 ); ( RCC-> APB2RSTR &= ~( 1 << 6 )); } while (0)
	#define GPIO_F_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 7 ); ( RCC-> APB2RSTR &= ~( 1 << 7 )); } while (0)
	#define GPIO_G_REG_RESET	do{ ( RCC-> APB2RSTR |= 1 << 8 ); ( RCC-> APB2RSTR &= ~( 1 << 8 )); } while (0)



#endif
