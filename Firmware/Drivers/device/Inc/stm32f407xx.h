/**
 * @file        stm32f407xx.h
 * @date        24-02-2024
 * @author      Manoj Mondal
 * @brief       This header files contain some generic macros and defintions.
*/

#ifndef __STM32F407XX_H__
#define __STM32F407XX_H__
/****************** Include Files *******************/
#include "stm32f407xx_memory_map.h"
#include "stm32f407xx_peripheral_reg_def.h"

/****************** Define Macros *******************/

/**
 * GPIO Ports Defintions (Peripheral base addresses type-casted to GPIO_RegisterType_t structure)
*/
#define GPIOA                           ((GPIO_RegisterType_t*)GPIOA_BASE_ADDR)
#define GPIOB                           ((GPIO_RegisterType_t*)GPIOB_BASE_ADDR)
#define GPIOC                           ((GPIO_RegisterType_t*)GPIOC_BASE_ADDR)
#define GPIOD                           ((GPIO_RegisterType_t*)GPIOD_BASE_ADDR)
#define GPIOE                           ((GPIO_RegisterType_t*)GPIOE_BASE_ADDR)
#define GPIOF                           ((GPIO_RegisterType_t*)GPIOF_BASE_ADDR)
#define GPIOG                           ((GPIO_RegisterType_t*)GPIOG_BASE_ADDR)
#define GPIOH                           ((GPIO_RegisterType_t*)GPIOH_BASE_ADDR)
#define GPIOI                           ((GPIO_RegisterType_t*)GPIOI_BASE_ADDR)

/**
 * RCC register
*/
#define RCC                             ((RCC_RegisterType_t*)RCC_BASE_ADDR)

/**
 * Clock Enabling and Disable Macro
*/
/* Enable GPIO Clock */
#define GPIOA_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()                 (RCC->AHB1ENR |= (1 << 8))

/* Disable GPIO Clock */
#define GPIOA_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()                 (RCC->AHB1ENR &= ~(1 << 8))

/**
 * Some Generic MACROS and typedef Enums.
*/
#define HIGH                            1U
#define LOW                             0U
#define ENABLE                          1U
#define DISABLE                         0U
#define SET                             1U
#define RESET                           0U

#endif //__STM32F407XX_H__
