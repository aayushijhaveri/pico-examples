/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#ifdef PICO_DEFAULT_LED_PIN
#define LED_PIN PICO_DEFAULT_LED_PIN
#endif

//set pins
const int rs = 0;
const int rw = 1;
const int d7 = 2;
const int d6 = 3;
const int d5 = 4;
const int d4 = 5;
const int d3 = 6;
const int d2 = 7;
const int d1 = 8;
const int d0 = 9;

void wait(){
  sleep_ms(100);  
}

int main() {
    stdio_init_all();
    printf("Hello, 7segment - press button to count down!\n");

    //initilaise pins 
    gpio_init(rs);
    gpio_init(rw);
    gpio_init(d7);
    gpio_init(d6);
    gpio_init(d5);
    gpio_init(d4);
    gpio_init(d3);
    gpio_init(d2);
    gpio_init(d1);
    gpio_init(d0);

    //set direction of data flow
    gpio_set_dir(rs, GPIO_OUT);
    gpio_set_dir(rw, GPIO_OUT);
    gpio_set_dir(d7, GPIO_OUT);
    gpio_set_dir(d6, GPIO_OUT);
    gpio_set_dir(d5, GPIO_OUT);
    gpio_set_dir(d4, GPIO_OUT);
    gpio_set_dir(d3, GPIO_OUT);
    gpio_set_dir(d2, GPIO_OUT);
    gpio_set_dir(d1, GPIO_OUT);
    gpio_set_dir(d0, GPIO_OUT);

    hd44780_init();
}

void write_byte_8bit(uint8_t message, bool rs_val){

    gpio_put(d0, (message & 0x01) == 0x01);
    gpio_put(d1, (message & 0x02) == 0x02);
    gpio_put(d2, (message & 0x04) == 0x04);
    gpio_put(d3, (message & 0x08) == 0x08);
    gpio_put(d4, (message & 0x10) == 0x10);
    gpio_put(d5, (message & 0x20) == 0x20);
    gpio_put(d6, (message & 0x40) == 0x40);
    gpio_put(d7, (message & 0x80) == 0x80);

    wait();

}

void hd44780_init(){
    write_byte_8bit(0x30, false);
    write_byte_8bit(0x30, false);
    write_byte_8bit(0x30, false);
    write_byte_8bit(0x08, false);
    write_byte_8bit(0x01, false);
    write_byte_8bit(0x07, false);

    //display message
    
    write_byte_8bit(0x48, true);
    write_byte_8bit(0x45, true);
    write_byte_8bit(0x4C, true);
    write_byte_8bit(0x4C, true);
    write_byte_8bit(0x4F, true);

}

void reset(){
    
}

