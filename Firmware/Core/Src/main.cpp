/**
 * @file           : main.cpp
 * @author         : Manoj Mondal
 * @brief          : Main program body
 */

/****************** Include Files *******************/
#include "main.hpp"
#include "stm32f407xx_gpio.hpp"

void SoftwareDelay(void)
{
    for(uint32_t i = 0 ; i < 100000 ; i++);
}

/* Main Function: Program is for blink the four user led on the board in a order */
int main(void)
{
    GPIO Led1(GPIOD);
    GPIO Led2(GPIOD);
    GPIO Led3(GPIOD);
    GPIO Led4(GPIOD);

    Led1.PinConfig.PinNumber = e_GPIOPin12;
    Led1.PinConfig.PinMode = GPIO_MODE_OUT;
    Led1.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Led1.PinConfig.PinOPType = GPIO_OP_TYPE_PP;
    Led1.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Led2.PinConfig.PinNumber = e_GPIOPin13;
    Led2.PinConfig.PinMode = GPIO_MODE_OUT;
    Led2.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Led2.PinConfig.PinOPType = GPIO_OP_TYPE_PP;
    Led2.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Led3.PinConfig.PinNumber = e_GPIOPin14;
    Led3.PinConfig.PinMode = GPIO_MODE_OUT;
    Led3.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Led3.PinConfig.PinOPType = GPIO_OP_TYPE_PP;
    Led3.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Led4.PinConfig.PinNumber = e_GPIOPin15;
    Led4.PinConfig.PinMode = GPIO_MODE_OUT;
    Led4.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Led4.PinConfig.PinOPType = GPIO_OP_TYPE_PP;
    Led4.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Led1.PeripheralClockControl(ENABLE);
    Led2.PeripheralClockControl(ENABLE);
    Led3.PeripheralClockControl(ENABLE);
    Led4.PeripheralClockControl(ENABLE);

    Led1.GPIOInit();
    Led2.GPIOInit();
    Led3.GPIOInit();
    Led4.GPIOInit();

    while(true)
    {
        Led1.ToggleOutputPin();
        SoftwareDelay();
        Led2.ToggleOutputPin();
        SoftwareDelay();
        Led3.ToggleOutputPin();
        SoftwareDelay();
        Led4.ToggleOutputPin();
        SoftwareDelay();
    }
    return 0;
}
