#ifndef __PERIPHERALINITIALIZER_H_
#define __PERIPHERALINITIALIZER_H_

#include <stdio.h>

typedef struct peripherals
{
    FILE* pir;
    FILE* out;
    FILE* SPI;
    FILE* motor;
} peripherals_t;

int peripheralsinit(void);

int peripheral_setout(FILE* peripheral_ddr);

int peripheral_setin(FILE* peripheral_ddr);

#endif 