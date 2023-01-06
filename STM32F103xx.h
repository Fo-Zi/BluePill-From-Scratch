#ifndef STM32F103XX_H
#define STM32F103XX_H
	
	/*--------------- MEMORY AND BUSES BASE ADDRESSES  ---------------*/
	#define FLASH_BASE_ADDR 	0x08000000UL
	#define SRAM_BASE_ADDR		0x20000000UL
	#define ROM_BASE_ADDR		0x1FFFF000UL

	#define AHB_BASE_ADDR		0x40020000UL
	#define APB_1_BASE_ADDR		0x40000000UL
	#define APB_2_BASE_ADDR		0x40010000UL
	
	/*--------------- AHB PERIPHERALS BASE ADDRESSES  ---------------*/
	#define DMA_1_BASE_ADDR		AHB_BASE_ADDR 
	#define RCC_BASE_ADDR		( AHB_BASE_ADDR + 0x1000U ) 
	#define FLASH_INTERF_BASE_ADDR	( AHB_BASE_ADDR + 0x2000U ) 
	#define CRC_BASE_ADDR		( AHB_BASE_ADDR + 0x3000U ) 

	
	/*--------------- APB1 PERIPHERALS BASE ADDRESSES  ---------------*/
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
	
#endif
