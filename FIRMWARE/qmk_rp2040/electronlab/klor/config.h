/*
Copyright 2024 ElectronLab

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// ┌─────────────────────────────────────────────────┐
// │ p i n   c o n f i g                             │
// └─────────────────────────────────────────────────┘ 

#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2

// ┌─────────────────────────────────────────────────┐
// │ k e y   m a t r i x                             │
// └─────────────────────────────────────────────────┘ 

//#define MATRIX_ROW_PINS { GP5, GP6, GP7, GP8 }
//#define MATRIX_COL_PINS { GP27, GP26, GP22, GP20, GP23, GP21 }
//#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define DEBOUNCE 5


// ┌─────────────────────────────────────────────────┐
// │ s p l i t   c o m m u n i c a t i o n           │
// └─────────────────────────────────────────────────┘ 

#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_USB_DETECT

//Half Duplex communication
#define SERIAL_USART_TX_PIN GP1     // USART TX pin

//Full Duplex communication
//#define SERIAL_USART_TX_PIN GP4     // USART TX pin
//#define SERIAL_USART_RX_PIN GP1     // USART RX pin
//#define SERIAL_USART_FULL_DUPLEX
//#define SERIAL_USART_PIN_SWAP

// ┌─────────────────────────────────────────────────┐
// │ e n c o d e r s                                 │
// └─────────────────────────────────────────────────┘ 

//#define ENCODERS_PAD_A       { GP28 }
//#define ENCODERS_PAD_B       { GP29 }
//#define ENCODERS_PAD_A_RIGHT { GP29 }
//#define ENCODERS_PAD_B_RIGHT { GP28 }
#define ENCODER_RESOLUTION { 2 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }


// ┌─────────────────────────────────────────────────┐
// │ o l e d s                                       │
// └─────────────────────────────────────────────────┘

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define SPLIT_OLED_ENABLE
#    define OLED_FONT_H  "./lib/glcdfont.c"
#endif



// ┌─────────────────────────────────────────────────┐
// │ t r a c k b a l l                               │
// └─────────────────────────────────────────────────┘ 

#ifdef POINTING_DEVICE_ENABLE
#    define PAW3204_SCLK_PIN GP3
#    define PAW3204_SDIO_PIN GP2
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define AUTO_MOUSE_DELAY 300
#endif
