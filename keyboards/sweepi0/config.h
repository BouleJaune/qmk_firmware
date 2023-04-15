// Copyright 2023 Amettler Thierry (@BouleJaune)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define EE_HANDS
// #define MASTER_LEFT

#define SERIAL_PIO_USE_PIO1
// #define SERIAL_USART_TX_PIN GP14 //uncomment for left and comment for right
// #define SERIAL_USART_TX_PIN GP9 //uncomment for right and comment for left


#if defined(EE_HANDS)
#    if defined(INIT_EE_HANDS_LEFT)
#        define SERIAL_USART_TX_PIN GP14
#    elif defined(INIT_EE_HANDS_RIGHT)
#        define SERIAL_USART_TX_PIN GP9
#    else
#        error EE_HANDS without left/right config
#    endif
#endif


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
