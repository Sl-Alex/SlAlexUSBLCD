#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>

void delay_setup(void);
void delay_us(uint16_t us);
void delay_ms(uint32_t nTime);

#endif // DELAY_H