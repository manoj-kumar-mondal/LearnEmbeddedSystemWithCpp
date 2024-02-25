/**
 * @file        stm32f407xx_gpio.h
 * @date        24-02-2024
 * @author      Manoj Mondal
 * @brief       This contains gpio drivers api.
*/

#ifndef __STM32F407XX_GPIO_HPP__
#define __STM32F407XX_GPIO_HPP__

/****************** Include Files *******************/
#include "stm32f407xx.h"

/****************** Define Macros *******************/
/* GPIO pin possible mode */
#define GPIO_MODE_IN                                0U
#define GPIO_MODE_OUT                               1U
#define GPIO_MODE_ALTFN                             2U
#define GPIO_MODE_ANALOG                            3U
#define GPIO_MODE_IN_FALL_EDGE                      4U
#define GPIO_MODE_IN_RISE_EDGE                      5U
#define GPIO_MODE_IN_BOTH_EDGE                      6U

/* GPIO pin possible output types*/
#define GPIO_OP_TYPE_PP                             0U /*!< Push Pull */
#define GPIO_OP_TYPE_OD                             1U /*!< Open Drain */

/* GPIO pin possible output speeds */
#define GPIO_SPEED_LOW                              0U
#define GPIO_SPEED_MEDIUM                           1U
#define GPIO_SPEED_HIGH                             2U
#define GPIO_SPEED_VERY_HIGH                        3U

/*GPIO pin pullup pulldown configurations */
#define GPIO_NO_PUPD                                0U
#define GPIO_PULLUP                                 1U
#define GPIO_PULLDOWN                               2U

/**************** Type Defintions ******************/
typedef enum
{
    e_GPIOA = 0U,
    e_GPIOB = 1U,
    e_GPIOC = 2U,
    e_GPIOD = 3U,
    e_GPIOE = 4U,
    e_GPIOF = 5U,
    e_GPIOG = 6U,
    e_GPIOH = 7U,
    e_GPIOI = 8U,
    e_GPIONA
} e_GPIOPort_t;

typedef enum
{
    e_GPIOPin0 = 0U,
    e_GPIOPin1 = 1U,
    e_GPIOPin2 = 2U,
    e_GPIOPin3 = 3U,
    e_GPIOPin4 = 4U,
    e_GPIOPin5 = 5U,
    e_GPIOPin6 = 6U,
    e_GPIOPin7 = 7U,
    e_GPIOPin8 = 8U,
    e_GPIOPin9 = 9U,
    e_GPIOPin10 = 10U,
    e_GPIOPin11 = 11U,
    e_GPIOPin12 = 12U,
    e_GPIOPin13 = 13U,
    e_GPIOPin14 = 14U,
    e_GPIOPin15 = 15U,
    e_GPIOPinNA,
} e_GPIOPinNumber_t;

typedef struct
{
    e_GPIOPinNumber_t PinNumber;
    uint8_t PinMode;
    uint8_t PinOPType;
    uint8_t PinSpeed;
    uint8_t PinPuPdControl;
    uint8_t PinAltFunMode;
} GPIO_PinConfig_t;

class GPIO
{
    private:
        /* Data Member */
        GPIO_RegisterType_t *pGPIOx;
        e_GPIOPort_t PortNumber;

        /* Private member function*/
        void DetectGPIOPort();

    public:
        /* Data Member */
        GPIO_PinConfig_t PinConfig;

        /* Constructor*/
        GPIO();
        GPIO(GPIO_RegisterType_t *pGPIOx);
        /* Destructor */
        ~GPIO();

        /* Class Methods */
        void GPIOInit();
        void PeripheralClockControl(uint8_t Mode);
        void WriteToOutputPin(uint8_t Value);
        void WriteToOutputPort(uint16_t Value);
        void ToggleOutputPin();
        uint16_t ReadFromInputPort(void);
        uint8_t ReadFromInputPin();
        //TODO: Handle later
        // void IRQConfig();
        // void IRQHandling();

};
#endif //__STM32F407XX_GPIO_H__