/*===============
	lmcapacho
	2016	
=================*/

#include "procesador.h"

void CPUInit(void)
{
	DDRC = DDRD = DDRE = 0xFF;
	PORTC = PORTE = 0;
	PORTD = (1<<RD)|(1<<WR);
}

void CPUWrite(uint16_t dir, uint8_t data)
{
	DDRA = 0xFF;
	PORTE |= (1<<ALE);
	PORTA = (uint8_t) (dir);
	PORTC = (uint8_t) (dir>>8);
	PORTE &= ~(1<<ALE);

	PORTA = data;
	PORTD &= ~(1<<WR);
	_delay_us(10);
	PORTD |= (1<<WR);
}

uint8_t CPURead(uint16_t dir)
{
	uint8_t data;

	DDRA = 0xFF;
	PORTE |= (1<<ALE);
	PORTA = (uint8_t) (dir);
	PORTC = (uint8_t) (dir>>8);
	PORTE &= ~(1<<ALE);

	DDRA = 0;
	_delay_us(10);
	PORTD &= ~(1<<RD);
	_delay_us(10);
	data = PINA;
	PORTD |= (1<<RD);
	_delay_us(10);

	return data;
}
