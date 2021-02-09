#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#include <delay.h>

void delay_setup(void)
{
    /* set up a microsecond free running timer for ... things... */
    rcc_periph_clock_enable(RCC_TIM4);
    /* microsecond counter */
    timer_set_prescaler(TIM4, (rcc_apb1_frequency / 1000000) - 1);
    timer_set_period(TIM4, 0xffff);
    timer_one_shot_mode(TIM4);
}

void delay_us(uint16_t us)
{
    TIM_ARR(TIM4) = us;
    TIM_EGR(TIM4) = TIM_EGR_UG;
    TIM_CR1(TIM4) |= TIM_CR1_CEN;
    while (TIM_CR1(TIM4) & TIM_CR1_CEN);
}

void delay_ms(uint32_t nTime)
{
    for (uint32_t i = 0; i < nTime; i++)
        delay_us(1000);
    /* Very dirty hack, don't use it */
    // for (uint32_t i = 0; i < 0x800*5*nTime; i++)
    //     __asm("NOP");
}
