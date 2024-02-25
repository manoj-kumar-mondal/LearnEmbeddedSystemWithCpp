/**
 * @file        stm32f407xx_memory_map.h
 * @date        24-02-2024
 * @author      Manoj Mondal
 * @brief       This contains the memory map of board STM32F407VG Discovery Kit.
*/

#ifndef __STM32F407XX_MEMORY_MAP_H__
#define __STM32F407XX_MEMORY_MAP_H__

/****************** Define Macros *******************/
/**
 * Base Addresses of Flash and SRAM memories
*/
#define FLASH_BASE_ADDR                 0X08000000UL
#define SRAM1_BASE_ADDR                 0X20000000UL /*!< Size of Main-SRAM(SRAM1) = 112KB */
#define SRAM2_BASE_ADDR                 (SRAM1_BASE_ADDR + (112UL * 1024UL)) /*!< SRAM2 base address = (SRAM1 + 112KB) */
#define SRAM                            SRAM1_BASE_ADDR
#define ROM                             0X1FFF0000UL /*!< System Memory */

/**
 * Base Addresses of Peripherals (AHBs & APBs)
*/
#define PERIPH_BASE_ADDR                0X40000000UL
#define PERIPH_APB1_BASE_ADDR           PERIPH_BASE_ADDR
#define PERIPH_APB2_BASE_ADDR           0X40010000UL
#define PERIPH_AHB1_BASE_ADDR           0X40020000UL
#define PERIPH_AHB2_BASE_ADDR           0X50000000UL

/**
 * Base Addresses of Peripherals hanging on AHB1 bus.
*/
#define GPIOA_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X0000UL)
#define GPIOB_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X0400UL)
#define GPIOC_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X0800UL)
#define GPIOD_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X0C00UL)
#define GPIOE_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X1000UL)
#define GPIOF_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X1400UL)
#define GPIOG_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X1800UL)
#define GPIOH_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X1C00UL)
#define GPIOI_BASE_ADDR                 (PERIPH_AHB1_BASE_ADDR + 0X2000UL) /*!< This mcu supports upto GPIOI only */
#define RCC_BASE_ADDR                   (PERIPH_AHB1_BASE_ADDR + 0X3800UL)

/**
 * Base Addresses of Peripherals hanging on APB1 bus.
*/
#define SPI2_BASE_ADDR                  (PERIPH_APB1_BASE_ADDR + 0X3800UL)
#define SPI3_BASE_ADDR                  (PERIPH_APB1_BASE_ADDR + 0X3C00UL)
#define USART2_BASE_ADDR                (PERIPH_APB1_BASE_ADDR + 0X4400UL)
#define USART3_BASE_ADDR                (PERIPH_APB1_BASE_ADDR + 0X4800UL)
#define UART4_BASE_ADDR                 (PERIPH_APB1_BASE_ADDR + 0X4C00UL)
#define UART5_BASE_ADDR                 (PERIPH_APB1_BASE_ADDR + 0X5000UL)
#define I2C1_BASE_ADDR                  (PERIPH_APB1_BASE_ADDR + 0X5400UL)
#define I2C2_BASE_ADDR                  (PERIPH_APB1_BASE_ADDR + 0X5800UL)
#define I2C3_BASE_ADDR                  (PERIPH_APB1_BASE_ADDR + 0X5C00UL)

/**
 * Base Addresses of Peripherals hanging on APB2 bus.
*/
#define USART1_BASE_ADDR                (PERIPH_APB2_BASE_ADDR + 0X1000UL)
#define USART6_BASE_ADDR                (PERIPH_APB2_BASE_ADDR + 0X1400UL)
#define SPI1_BASE_ADDR                  (PERIPH_APB2_BASE_ADDR + 0X3000UL)
#define SPI4_BASE_ADDR                  (PERIPH_APB2_BASE_ADDR + 0X3400UL)
#define SYSCFG_BASE_ADDR                (PERIPH_APB2_BASE_ADDR + 0X3800UL)
#define EXTI_BASE_ADDR                  (PERIPH_APB2_BASE_ADDR + 0X3C00UL)

#endif //__STM32F407XX_MEMORY_MAP_H__
