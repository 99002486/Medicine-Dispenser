#ifndef __PERIPHERALINITIALIZER_H_
#define __PERIPHERALINITIALIZER_H_

#include <stdio.h>
/**
Struct- Consists file pointers pointing to each GPIO file
**/
typedef struct peripherals
{
    FILE* pir;
    FILE* rled;
    FILE* gled;
    FILE* motorout1;
    FILE* motorout2;
} peripherals_t;

peripherals_t peripheralsinit(void);

int peripheral_setout(FILE* peripheral_ddr);

int peripheral_setin(FILE* peripheral_ddr);

int peripheralddrinit(void);

#endif 
