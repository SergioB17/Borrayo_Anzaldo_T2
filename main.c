#include <stdio.h>
#include "MK64F12.h"

#define SIM_5 (*((volatile uint32_t *) 0x40048038))
#define PCR_PTB22 (*((volatile uint32_t *) 0x4004A058))
#define GPIO_B_PDOR (*((volatile uint32_t *) 0x400FF040))
#define GPIO_B_PDDR (*((volatile uint32_t *) 0x400FF054))

int main(void) {


    while(1) {

    }
    return 0 ;
}
