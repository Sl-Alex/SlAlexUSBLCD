#ifndef ST7565R_H
#define ST7565R_H

    void st7565r_init(uint8_t contrast);
    void st7565r_command(uint8_t c);
    void st7565r_data(uint8_t c);
    void st7565r_set_brightness(uint8_t val);
    void st7565r_clear_display(void);
    void st7565r_clear(void);
    void st7565r_display(void);
    void st7565r_set_raw_data(uint32_t offset, uint8_t *data, uint32_t sz);


#endif // ST7565R_H
