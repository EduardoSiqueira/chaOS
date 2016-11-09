
#ifndef _REGISTERS_H
#define _REGISTERS_H

#include <stdint.h>

uint16_t get_cs_content(void);

uint16_t get_ds_content(void);

uint16_t get_ss_content(void);

void print_registers(void);

#endif
