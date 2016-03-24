/*===============
	lmcapacho
	2016	
=================*/

#ifndef _PROCESADOR_H_
#define _PROCESADOR_H_

#include <avr/io.h>
#include <util/delay.h>

#define ALE PE1
#define RD  PD7
#define WR  PD6

void CPUInit(void);
void CPUWrite(uint16_t dir, uint8_t data);
uint8_t CPURead(uint16_t dir);

#endif // _PROCESADOR_H_
