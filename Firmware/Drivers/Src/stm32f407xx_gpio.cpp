/**
 * @file        stm32f407xx_gpio.c
 * @date        24-02-2024
 * @author      Manoj Mondal
 * @brief       This contains all the gpio driver api's defintions.
*/

/****************** Include Files *******************/
#include "stm32f407xx_gpio.hpp"

/***************** class Methods ********************/

/**
 * @brief   Default constructor
 * @param   none
 * @retval  none
*/
GPIO::GPIO()
{
    this->pGPIOx = nullptr;
    this->PortNumber = e_GPIONA;
}

/**
 * @brief   Parametrized constructor.
 * @param   GPIOX - GPIO Port.
 * @retval  none
*/
GPIO::GPIO(GPIO_RegisterType_t *pGPIOx)
{
    this->pGPIOx = pGPIOx;
    this->DetectGPIOPort();
}

/**
 * @brief   Destructor
 * @param   none
 * @retval  none
*/
GPIO::~GPIO()
{
    this->pGPIOx = nullptr;
}

/**
 * @brief   Methods is to read data from input pin.
 * @param   PinNumber
 * @retval  none
*/
uint8_t GPIO::ReadFromInputPin()
{
    uint8_t Value = 0;
    if(e_GPIOPinNA != this->PinConfig.PinNumber)
    {
        Value = (uint8_t)((this->pGPIOx->IDR >> this->PinConfig.PinNumber) & 0X01);
    }
    return Value;
}

/**
 * @brief   Method is to read the whole GPIO port input register.
 * @param   none
 * @retval  none
*/
uint16_t GPIO::ReadFromInputPort(void)
{
    uint16_t Value;
    Value = (uint16_t)(this->pGPIOx->IDR);
    return Value;
}

/**
 * @brief   Method is to write a value to a pin number.
 * @param   PinNumber
 * @param   Value - to be write
 * @retval  none
*/
void GPIO::WriteToOutputPin(uint8_t Value)
{
    if(e_GPIOPinNA != this->PinConfig.PinNumber)
    {
        if(SET == Value)
        {
            (this->pGPIOx->ODR |= (1 << this->PinConfig.PinNumber));
        }
        else if(RESET == Value)
        {
            (this->pGPIOx->ODR &= ~(1 << this->PinConfig.PinNumber));
        }
        else
        {
            //Do nothing
        }
    }
}

/**
 * @brief   Method for write a value into the GPIO port.
 * @param   Value
 * @retval  none
*/
void GPIO::WriteToOutputPort(uint16_t Value)
{
    this->pGPIOx->ODR = Value;
}

/**
 * @brief   Method is to toggle the pin.
 * @param   PinNumber
 * @retval  none
*/
void GPIO::ToggleOutputPin()
{
    this->pGPIOx->ODR ^= (1 << this->PinConfig.PinNumber);
}

/**
 * @brief   Method is to control the peripheral clock.
 * @param   Mode
 * @retval  none
*/
void GPIO::PeripheralClockControl(uint8_t Mode)
{
    if((ENABLE == Mode) && (e_GPIONA != this->PortNumber))
    {
        (RCC->AHB1ENR |= (1 << this->PortNumber));
    }
    else if((DISABLE == Mode) && (e_GPIONA != this->PortNumber))
    {
        (RCC->AHB1ENR &= ~(1 << this->PortNumber));
    }
}

/**
 * @brief   Init Method
 * @param   none
 * @retval  none
*/
void GPIO::GPIOInit()
{   
    /* Configure Mode */
    if(GPIO_MODE_ANALOG >= this->PinConfig.PinMode)
    {
        this->pGPIOx->MODER |= (this->PinConfig.PinMode << (2 * this->PinConfig.PinNumber));
    }
    else
    {
        //Handle Interrupt mode later
    }

    /* Configure Speed */
    this->pGPIOx->OSPEEDR |= (this->PinConfig.PinSpeed << (2 * this->PinConfig.PinNumber));

    /* Configure PUPD Control */
    this->pGPIOx->PUPDR |= (this->PinConfig.PinPuPdControl << (2 * this->PinConfig.PinNumber));

    /* Configure OP Type */
    this->pGPIOx->OTYPER |= (this->PinConfig.PinOPType << this->PinConfig.PinNumber);

    /* Configure Alternate functional register */
    if(GPIO_MODE_ALTFN == this->PinConfig.PinMode)
    {
        // Handle Later
    }
}

/**
 * @brief   Method is to detect GPIO port.
 * @param   none
 * @retval  none
*/
void GPIO::DetectGPIOPort()
{
    if(GPIOA == this->pGPIOx)
    {
        this->PortNumber = e_GPIOA;
    }
    else if(GPIOB == this->pGPIOx)
    {
        this->PortNumber = e_GPIOB;
    }
    else if(GPIOC == this->pGPIOx)
    {
        this->PortNumber = e_GPIOC;
    }
    else if(GPIOD == this->pGPIOx)
    {
        this->PortNumber = e_GPIOD;
    }
    else if(GPIOE == this->pGPIOx)
    {
        this->PortNumber = e_GPIOE;
    }
    else if(GPIOF == this->pGPIOx)
    {
        this->PortNumber = e_GPIOF;
    }
    else if(GPIOG == this->pGPIOx)
    {
        this->PortNumber = e_GPIOG;
    }
    else if(GPIOH == this->pGPIOx)
    {
        this->PortNumber = e_GPIOH;
    }
    else if(GPIOI == this->pGPIOx)
    {
        this->PortNumber = e_GPIOI;
    }
    else
    {
        this->PortNumber = e_GPIONA;
    }
}