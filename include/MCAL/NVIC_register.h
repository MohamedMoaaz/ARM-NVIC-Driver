/**
 * @file    NVIC_register.h
 * @author  Mohamed Moaaz
 * @brief   NVIC register file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __NVIC_REGISTER_H__
#define __NVIC_REGISTER_H__

//==============================================================================
// Macros & Defines
//==============================================================================

#define NVIC_BASE   0xE000E100
#define NVIC_ISER0  REG(NVIC_BASE + 0x000)
#define NVIC_ISER1  REG(NVIC_BASE + 0x004)
#define NVIC_ICER0  REG(NVIC_BASE + 0x080)
#define NVIC_ICER1  REG(NVIC_BASE + 0x084)
#define NVIC_ISPR0  REG(NVIC_BASE + 0x100)
#define NVIC_ISPR1  REG(NVIC_BASE + 0x104)
#define NVIC_ICPR0  REG(NVIC_BASE + 0x180)
#define NVIC_ICPR1  REG(NVIC_BASE + 0x184)
#define NVIC_IABR0  REG(NVIC_BASE + 0x200)
#define NVIC_IABR1  REG(NVIC_BASE + 0x204)
#define NVIC_IPR    ((volatile uint8_t*)0xE000E400)

#define SCB_AIRCR   REG(0xE000ED00 + 0x0C)

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __NVIC_REGISTER_H__ */