#include "procesador.h"
#include "ports.h"

void secuencias(uint8_t sel);

int main(){

    uint8_t sel;

    CPUInit();

    CPUWrite(0x100, 0x01);
    CPUWrite(0x201, 0x80);

    CPUWrite(DDR_A, 0);
    CPUWrite(DDR_B, 0xFF);

    while(1){
        sel = CPURead(PIN_A);
        secuencias(sel);
        _delay_ms(500);
    }
}

void secuencias(uint8_t sel)
{
    uint8_t value;

    switch(sel)
    {
        case 1:
            value = CPURead(0x100);
            if(value == 0)
                value = 1;

            CPUWrite(PORT_B, value);
            value <<= 1;
            CPUWrite(0x100,value);
            break;

        case 2:
            value = CPURead(0x201);
            if(value == 0)
                value = 0x80;

            CPUWrite(PORT_B, value);
            value >>= 1;
            CPUWrite(0x201,value);
            break;

        case 4:
            value = CPURead(PORT_B);
            value++;
            CPUWrite(PORT_B, value);
            break;

        case 8:
            value = CPURead(PORT_B);
            value--;
            CPUWrite(PORT_B, value);
            break;

        default:
            value = CPURead(PORT_B);
            value ^= 0xFF;
            CPUWrite(PORT_B, value);
            break;
    }
}
