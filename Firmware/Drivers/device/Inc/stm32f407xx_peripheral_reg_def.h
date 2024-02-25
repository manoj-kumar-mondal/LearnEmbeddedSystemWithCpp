/**
 * @file        stm32f407xx_peripheral_reg_def.h
 * @date        24-02-2024
 * @author      Manoj Mondal
 * @brief       This contains some structural defintions peripheral registers
*/

#ifndef __STM32F407XX_PERIPHERAL_REGISTER_DEF_H__
#define __STM32F407XX_PERIPHERAL_REGISTER_DEF_H__

/****************** Include Files *******************/
/* Library*/
#include <stdint.h>

/****************** Define Macros *******************/
#define __VO                volatile

/************ Constants/Type Definitions ************/

/**
 * Structural defintion for the GPIO register map
*/
typedef struct
{
    __VO uint32_t MODER;     /*!< Mode Register                                          Address Offset: 0X00 */
    __VO uint32_t OTYPER;    /*!< Output Type Register                                   Address Offset: 0X04 */
    __VO uint32_t OSPEEDR;   /*!< Output Speed Register                                  Address Offset: 0X08 */
    __VO uint32_t PUPDR;     /*!< Pull-up Pull-down Register                             Address Offset: 0X0C */
    __VO uint32_t IDR;       /*!< Input Data Register                                    Address Offset: 0X10 */
    __VO uint32_t ODR;       /*!< Output Data Register                                   Address Offset: 0X14 */
    __VO uint32_t BSRR;      /*!< Bit Set/Reset Register                                 Address Offset: 0X18 */
    __VO uint32_t LCKR;      /*!< Configuration Lock Register                            Address Offset: 0X1C */
    __VO uint32_t AFR[2];    /*!< Alternate Function Registers [0]: LOW, [1]: HIGH       Address Offset: AFR[0]: 0X20,  AFR[1]: 0X24*/
}GPIO_RegisterType_t;

/**
 * Structural defintion for the RCC register map
*/
typedef struct
{
    __VO uint32_t CR;               /*!< Control Register                                       Address Offset: 0X00 */
    __VO uint32_t PLLCFGR;          /*!< PLL Configuration Register                             Address Offset: 0X04 */
    __VO uint32_t CFGR;             /*!< Clock Configuration Register                           Address Offset: 0X08 */
    __VO uint32_t CIR;              /*!< Clock Interrupt Register                               Address Offset: 0X0C */
    __VO uint32_t AHB1RSTR;         /*!< AHB1 Peripheral Reset Register                         Address Offset: 0X10 */
    __VO uint32_t AHB2RSTR;         /*!< AHB2 Peripheral Reset Register                         Address Offset: 0X14 */
    __VO uint32_t AHB3RSTR;         /*!< AHB3 Peripheral Reset Register                         Address Offset: 0X18 */
         uint32_t Reserved0;        /*!< Reserved */
    __VO uint32_t APB1RSTR;         /*!< APB1 Peripheral Reset Register                         Address Offset: 0X20 */
    __VO uint32_t APB2RSTR;         /*!< APB2 Peripheral Reset Register                         Address Offset: 0X24 */
         uint32_t Reserved1[2];     /*!< Reserved */
    __VO uint32_t AHB1ENR;          /*!< AHB1 Peripheral Clock Enable Register                  Address Offset: 0X30 */
    __VO uint32_t AHB2ENR;          /*!< AHB2 Peripheral Clock Enable Register                  Address Offset: 0X34 */
    __VO uint32_t AHB3ENR;          /*!< AHB3 Peripheral Clock Enable Register                  Address Offset: 0X38 */
         uint32_t Reserved2;        /*!< Reserved */
    __VO uint32_t APB1ENR;          /*!< APB1 Peripheral Clock Enable Register                  Address Offset: 0X40 */
    __VO uint32_t APB2ENR;          /*!< APB2 Peripheral Clock Enable Register                  Address Offset: 0X44 */
         uint32_t Reserved3[2];     /*!< Reserved */
    __VO uint32_t AHB1LPENR;        /*!< AHB1 Peripheral Clock Enable Register in LP mode       Address Offset: 0X50 */
    __VO uint32_t AHB2LPENR;        /*!< AHB2 Peripheral Clock Enable Register in LP mode       Address Offset: 0X54 */
    __VO uint32_t AHB3LPENR;        /*!< AHB3 Peripheral Clock Enable Register in LP mode       Address Offset: 0X58 */
         uint32_t Reserved6;        /*!< Reserved */
    __VO uint32_t APB1LPENR;        /*!< APB1 Peripheral Clock Enable Register in LP mode       Address Offset: 0X60 */
    __VO uint32_t APB2LPENR;        /*!< APB2 Peripheral Clock Enable Register in LP mode       Address Offset: 0X64 */
         uint32_t Reserved4[2];     /*!< Reserved */
    __VO uint32_t BDCR;             /*!< Backup Domain Control Register                         Address Offset: 0X70 */
    __VO uint32_t CSR;              /*!< Clock Control and Status Register                      Address Offset: 0X74 */
         uint32_t Reserved5[2];     /*!< Reserved */
    __VO uint32_t SSCGR;            /*!< Spread Spectrum Clock Generation Register              Address Offset: 0X80 */
    __VO uint32_t PLLI2SCFGR;       /*!< PLLI2S Configuration Register                          Address Offset: 0X84 */
    __VO uint32_t PLLSAICFGR;       /*!< PLL Configuration Register                             Address Offset: 0X88 */
    __VO uint32_t DCKCFGR;          /*!< Dedicated Clock COnfiguration Register                 Address Offset: 0X8C */
}RCC_RegisterType_t;

#endif //__STM32F407XX_PERIPHERAL_REGISTER_DEF_H__