/**
 * @file    NVIC_prog.c
 * @author  Mohamed Moaaz
 * @brief   NVIC program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/NVIC_interface.h"
#include "MCAL/NVIC_register.h"
#include "MCAL/NVIC_private.h"
#include "MCAL/NVIC_config.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

E_Status NVIC_xEnableInterrupt(uint8_t copy_u8IntNumber)
{
    E_Status Local_ErrorState = E_OK;
    if (copy_u8IntNumber <= 31)
    {
        NVIC_ISER0 = (1 << copy_u8IntNumber);
    }
    else if (copy_u8IntNumber <= 59)
    {
        copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1 << copy_u8IntNumber);
    }
    else
    {
        Local_ErrorState = E_NOK;
    }
    return Local_ErrorState;
}

E_Status NVIC_xDisableInterrupt(uint8_t copy_u8IntNumber)
{
    E_Status Local_ErrorState = E_OK;
    if (copy_u8IntNumber <= 31)
    {
        NVIC_ICER0 = (1 << copy_u8IntNumber);
    }
    else if (copy_u8IntNumber <= 59)
    {
        copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1 << copy_u8IntNumber);
    }
    else
    {
        Local_ErrorState = E_NOK;
    }
    return Local_ErrorState;
}

E_Status NVIC_xSetPendingFlag(uint8_t copy_u8IntNumber)
{
    E_Status Local_ErrorState = E_OK;
    if (copy_u8IntNumber <= 31)
    {
        NVIC_ISPR0 = (1 << copy_u8IntNumber);
    }
    else if (copy_u8IntNumber <= 59)
    {
        copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1 << copy_u8IntNumber);
    }
    else
    {
        Local_ErrorState = E_NOK;
    }
    return Local_ErrorState;
}

E_Status NVIC_xClearPendingFlag(uint8_t copy_u8IntNumber)
{
    E_Status Local_ErrorState = E_OK;
    if (copy_u8IntNumber <= 31)
    {
        NVIC_ICPR0 = (1 << copy_u8IntNumber);
    }
    else if (copy_u8IntNumber <= 59)
    {
        copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1 << copy_u8IntNumber);
    }
    else
    {
        Local_ErrorState = E_NOK;
    }
    return Local_ErrorState;
}

E_Status NVIC_xGetActiveFlag(uint8_t copy_u8IntNumber, uint8_t *copy_u8FlagState)
{
    E_Status Local_ErrorState = E_OK;
    if (copy_u8IntNumber <= 31)
    {
        *copy_u8FlagState = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
    }
    else if (copy_u8IntNumber <= 59)
    {
        copy_u8IntNumber -= 32;
        *copy_u8FlagState = GET_BIT(NVIC_IABR1, copy_u8IntNumber);
    }
    else
    {
        Local_ErrorState = E_NOK;
    }
    return Local_ErrorState;
}

E_Status NVIC_xSetPriority(uint8_t copy_u8InterruptID, uint8_t copy_u8GroupPriority, uint8_t copy_u8SubGroupPriority)
{
    E_Status Local_ErrorStatus = E_OK;
    /*check if incorrect data is entered*/
    if (copy_u8InterruptID > MAX_INTERRUPTS_SOURCES || copy_u8GroupPriority > 16 || copy_u8SubGroupPriority > 16)
    {
        Local_ErrorStatus = E_NOK;
    }
    else
    {
        /*calculate the priority bits*/
        uint8_t Local_priority = 0;
        Local_priority = copy_u8SubGroupPriority | ((copy_u8GroupPriority) << ((GROUPS_PRIORITY - 0x05FA0300) / 256));

        /*set the priority bits in their corresponding cell*/
        NVIC_IPR[copy_u8InterruptID] = (Local_priority << 4);

        /*set the priority and subpriority groups*/
        SCB_AIRCR = GROUPS_PRIORITY;
    }
}