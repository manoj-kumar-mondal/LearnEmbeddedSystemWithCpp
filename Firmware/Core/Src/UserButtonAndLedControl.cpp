/**
 * @file           : UserButtonAndLedControl.cpp
 * @author         : Manoj Mondal
 * @brief          : Program is to update the led state when user button is pressed.
 */

/****************** Include Files *******************/
#include "stm32f407xx_gpio.hpp"
#include "Utils.hpp"

/************** Function Definitions ****************/
void ButtonWithLed(void)
{
    /* User Button is connected to GPIOA */
    GPIO Button(GPIOA);
    GPIO Led(GPIOD);

    Button.PinConfig.PinNumber = e_GPIOPin0;
    Button.PinConfig.PinMode = GPIO_MODE_IN;
    Button.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Button.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Led.PinConfig.PinNumber = e_GPIOPin12;
    Led.PinConfig.PinMode = GPIO_MODE_OUT;
    Led.PinConfig.PinSpeed = GPIO_SPEED_HIGH;
    Led.PinConfig.PinOPType = GPIO_OP_TYPE_PP;
    Led.PinConfig.PinPuPdControl = GPIO_NO_PUPD;

    Button.PeripheralClockControl(ENABLE);
    Led.PeripheralClockControl(ENABLE);

    Button.GPIOInit();
    Led.GPIOInit();

    while(true)
    {
        if(HIGH == Button.ReadFromInputPin())
        {
            SoftwareDelay(); // handle the button debouncing
            Led.ToggleOutputPin();
        }
    }
}
