# CH32V003 Peripheral Drivers

Bare-metal peripheral drivers for the **CH32V003** (RISC-V) microcontroller, written in C at register level.

## Current peripheral support

| Peripheral | Status | Details |
|------------|--------|---------|
| **RCC** | Supported | Clock enable for GPIOA, GPIOC, GPIOD and USART1 |
| **GPIO** | Supported | Init, set, reset and toggle. Modes: analog input, floating input, pull-up / pull-down input, push-pull and open-drain output, alternate function. Speeds: 2, 10 and 30 MHz |
| **USART** | Supported | Init, send byte, receive byte and flag check (polling). 8 or 9 data bits, even / odd / no parity, 0.5 / 1 / 1.5 / 2 stop bits. Baud rate: 9600 (`BD9600`) |
| **ADC** | Supported | Init and single conversion read (polling) on PA2. Configurable sample time (3 to 241 cycles) |
| TIM | Not yet | |
| I2C | Not yet | |
| SPI | Not yet | |
| Interrupts | Not yet | |

## Layout

```
Inc/   Headers (register definitions in ch32v003.h, one header per driver)
Src/   Driver sources: gpio.c, rcc.c, usart.c, adc.c
```

## Example

```c
#include "gpio.h"
#include "rcc.h"

int main(void)
{
    GPIO_Config led;

    GPIOxClockControl(GPIOD);

    led.Pin   = GPIO_PIN_4;
    led.Mode  = OUTPUT_PUSH_PULL;
    led.Speed = GPIO_SPEED_2MHZ;
    GPIOInit(GPIOD, &led);

    while (1)
    {
        GPIOToggle(GPIOD, GPIO_PIN_4);
        for (volatile uint32_t i = 0; i < 100000; i++);
    }
}
```

## Build

Toolchain: `riscv-none-elf-gcc` with `-march=rv32ec -mabi=ilp32e -nostdlib`.
Add `Inc/` to the include path and compile the files in `Src/` together with your own `main.c`, startup code and linker script.

## Used in

- [VoltageSystem-Firmware](https://github.com/AlexBh1304/VoltageSystem-Firmware): voltage acquisition sent over UART in a checksum-protected frame
