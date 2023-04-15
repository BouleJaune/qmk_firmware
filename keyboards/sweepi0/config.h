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
