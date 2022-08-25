/*Sergio Eduardo Borrayo Anzaldo
  Tarea 2 - Sistemas Embebidos*/
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"

#define SIM_5 (*((volatile uint32_t *) 0x40048038))
#define PCR_PTB22 (*((volatile uint32_t *) 0x4004A058))
#define PCR_PTB21 (*((volatile uint32_t *) 0x4004A054))
#define PCR_PTE26 (*((volatile uint32_t *) 0x4004D068))

#define GPIO_B_BASE_ADDR ((volatile uint32_t *) 0x400FF040u)
#define GPIO_E_BASE_ADDR ((volatile uint32_t *) 0x400FF100u)

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
#define GPIO_E ((GPIO_t*) GPIO_E_BASE_ADDR)

int main(void) {

	SIM_5 = 0x00002400; /*Activamos el clock*/

	PCR_PTB22 = 0x00000100; /* Modo GPIO para los 3 puertos */
	PCR_PTB21 = 0x00000100;
	PCR_PTE26 = 0x00000100;


    while(1) {

    	GPIO_B->PDDR = 0x00400000; /*Prende LED rojo*/

    	GPIO_B->PDDR = 0x00200000; /*Prende LED azul*/
    	GPIO_B->PDDR = 0x00000000; /*Apaga puerto B */

    	GPIO_E->PDDR = 0x04000000; /*Prende LED verde*/

    	GPIO_B->PDDR = 0x00600000; /*Prende LED blanco*/
    	GPIO_E->PDDR = 0x00000000; /*Apaga LED verde*/
    	GPIO_B->PDDR = 0x00000000; /*Apaga LEDs rojo y azul*/
    }
    return 0 ;
}
