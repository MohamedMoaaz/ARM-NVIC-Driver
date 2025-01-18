/**
 * @file    NVIC_interface.h
 * @author  Mohamed Moaaz
 * @brief   NVIC interface file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__

//==============================================================================
// Includes
//==============================================================================


//==============================================================================
// Macros & Defines
//==============================================================================


//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

E_Status NVIC_u8EnableInterrupt(uint8_t copy_u8IntNumber);

E_Status NVIC_u8DisableInterrupt(uint8_t copy_u8IntNumber);

E_Status NVIC_u8SetPendingFlag(uint8_t copy_u8IntNumber);

E_Status NVIC_u8ClearPendingFlag(uint8_t copy_u8IntNumber);

E_Status NVIC_u8GetActiveFlag(uint8_t copy_u8IntNumber, uint8_t *copy_u8FlagState);

#endif /* __NVIC_INTERFACE_H__ */