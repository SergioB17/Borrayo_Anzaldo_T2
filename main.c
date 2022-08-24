#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"

#define SIM_5 (*((volatile uint32_t *) 0x40048038))
#define PCR_PTB22 (*((volatile uint32_t *) 0x4004A058))
#define PCR_PTB21 (*((volatile uint32_t *) 0x4004A054))

#define GPIO_B_BASE_ADDR ((volatile uint32_t *) 0x400FF040)

typedef struct
{
	uint32_t PDOR;
	uint32_t PSOR;
	uint32_t PCOR;
	uint32_t PTOR;
	uint32_t PDIR;
	uint32_t PDDR;

} GPIO_t;

#define GPIO_B ((GPIO_t*) GPIO_B_BASE_ADDR)

int main(void) {

	SIM_5 = 0x00000400;
	PCR_PTB22 = 0x00000100;
	PCR_PTB21 = 0x00000100;
	GPIO_B->PDDR = 0x00400000;

    while(1) {

    	GPIO_B->PDOR = 0x00400000;
    	GPIO_B->PDOR = 0x00000000;
    }
    return 0 ;
}
