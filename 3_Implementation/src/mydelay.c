#include "mydelay.h"

void delay(int seconds)
{
    int microseconds= 1000000 * seconds;
    clock_t start_time = clock();
    while(clock()< start_time+ microseconds);
}
