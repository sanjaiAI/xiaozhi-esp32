#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// Sanjai breadboard — AYWHP ESP32-S3-DevKitC, WROOM-1-N16R8 (16 MB flash, 8 MB PSRAM)
// Wiring as-built, ~/workspace/esp32-s3-day1/wiring.md (2026-11-17/18).
// Do NOT copy stock bread-compact-wifi pins: they clash with this wiring
// (mic WS/SD, amp DIN/BCLK/LRC and TFT RST all differ).

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Simplex I2S: I2S0 = mic, I2S1 = amp (same split as bread-compact-wifi)
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

// INMP441 mic: SCK 5, WS 6, SD 7 (L/R to GND = left channel)
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_6
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_7
// MAX98357A amp: DIN 18, BCLK 16, LRC 17
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_18
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_16
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_17

#else

#define AUDIO_I2S_GPIO_WS GPIO_NUM_6
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_7
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_18

#endif

#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
// Push button on the breadboard, GPIO 21 -> GND (internal pull-up)
#define CHAT_BUTTON_GPIO        GPIO_NUM_21
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC

// 1.8" ST7735 TFT (SPI), as wired: SCK 11, MOSI 10, CS 13, DC 14, RST 4.
// LED/BL is tied to the 3.3 V rail, so there is no backlight GPIO.
#define DISPLAY_BACKLIGHT_PIN GPIO_NUM_NC
#define DISPLAY_MOSI_PIN      GPIO_NUM_10
#define DISPLAY_CLK_PIN       GPIO_NUM_11
#define DISPLAY_DC_PIN        GPIO_NUM_14
#define DISPLAY_RST_PIN       GPIO_NUM_4
#define DISPLAY_CS_PIN        GPIO_NUM_13

// ST7735 128x160 — same panel block as bread-compact-wifi-lcd uses.
// Note: this panel showed pink-as-purple in MicroPython with MADCTL 0xC8;
// if colours look swapped on hardware, flip DISPLAY_RGB_ORDER to BGR.
#ifdef CONFIG_LCD_ST7735_128X160
#define LCD_TYPE_ST7789_SERIAL
#define DISPLAY_WIDTH   128
#define DISPLAY_HEIGHT  160
#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true
#define DISPLAY_SWAP_XY false
#define DISPLAY_INVERT_COLOR    false
#define DISPLAY_RGB_ORDER  LCD_RGB_ELEMENT_ORDER_RGB
#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE 0
#endif

// MCP lamp test drives the breadboard LED: GPIO 15 -> 220 ohm -> LED -> GND.
// (Stock LAMP_GPIO 18 would drive the amp DIN pin — never use it here.)
#define LAMP_GPIO GPIO_NUM_15

#endif // _BOARD_CONFIG_H_
