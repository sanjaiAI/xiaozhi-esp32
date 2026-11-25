# sanjai-breadboard

Custom XiaoZhi board for Sanjai's breadboard build — AYWHP ESP32-S3-DevKitC,
WROOM-1-N16R8. Based on `bread-compact-wifi-lcd`, with pins changed to match
the as-built wiring in `~/workspace/esp32-s3-day1/wiring.md`. It is a new
board, not an edit of a stock board, so OTA will not replace it with stock
firmware.

## Wiring

| Part | Pins |
|---|---|
| INMP441 mic | SCK 5, WS 6, SD 7, VDD 3V3, GND rail, L/R to GND |
| MAX98357A amp + 4 ohm / 3 W speaker | DIN 18, BCLK 16, LRC 17, VIN 3V3, GND rail |
| 1.8" ST7735 TFT 128x160 | SCK 11, MOSI 10, CS 13, DC 14, RST 4, VCC 3V3, LED/BL 3V3 |
| Push button | GPIO 21 -> GND (tap = talk / interrupt) |
| LED | GPIO 15 -> 220 ohm -> LED -> GND (also the MCP lamp) |
| On-board | BOOT GPIO 0 (tap = talk, at boot = Wi-Fi config), RGB LED GPIO 48 |

## Build

```sh
python3 scripts/build.py sanjai-breadboard --language en-US
# produces build/merged-binary.bin ; add --zip for releases/v*_sanjai-breadboard.zip
```

Flash with `idf.py -p <port> flash` / `esptool.py write_flash -z 0x0 merged-binary.bin`,
or the web flasher. First boot speaks a 6-digit code — enter it at xiaozhi.me.
