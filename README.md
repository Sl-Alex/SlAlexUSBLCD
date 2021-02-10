# SlAlexUSBLCD

This is a simple USB LCD, based on STM32F103C8T6 "Blue Pill" board and a cheap graphic LCD. ST7565R-based LCDs are supported. GMG12864-06D LCD was tested, for the rest some adjustments might be necessary.

Here is the wiring diagram:

![wiring][wiring]

| STM32 pin | LCD Module pin |
|-----------|----------------|
| A2        | RST (RSE)      |
| A3        | RS             |
| A4        | CS             |
| A5        | SCL            |
| A7        | SI             |

The only thing you should care about is the backlight current. There should be a current limiting resistor on the back side of LCD module, please check if it's really there and is not zero-Ohm.

The communication protocol is very simple. SW just sends a raw display content to USB BULK device endpoint 0x01 and then confirms that transmission is done by sending an empty package to the same endpoint.

## Build

Clone the repository with submodules and build everything

```console
git clone --recurse-submodules https://github.com/Sl-Alex/SlAlexUSBLCD.git
./make_all.sh
```

The result would be two `*.bin` files, the one with `*_BL.bin` is for [DFU bootloader][bootloader], another one can be flashed directly.

[wiring]: images/wiring.png
[bootloader]: https://github.com/Sl-Alex/STM32F103-bootloader