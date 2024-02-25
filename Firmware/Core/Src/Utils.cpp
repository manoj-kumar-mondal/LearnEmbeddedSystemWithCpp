/**
 * @file        Utils.cpp
 * @date        25-02-2024
 * @author      Manoj Mondal
 * @brief       This file contains some utility functions.
*/

/****************** Include Files *******************/
#include "Utils.hpp"
#include "stdint.h"

/************** Function Definitions ****************/
/**
 * @brief   Function is for give some delay to the program.
 * @param   none
 * @retval  none
*/
void SoftwareDelay(void)
{
    for(uint32_t i = 0 ; i < 100000 ; i++);
}