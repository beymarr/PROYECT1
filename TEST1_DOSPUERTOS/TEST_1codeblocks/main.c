#include "procesador.h"

int main(){

    uint8_t value;

    CPUInit();

    CPUWrite(0x2000, 0x00);
    CPUWrite(0x4000, 0xFF);

    while(1){
        value = CPURead(0x2002);
        CPUWrite(0x4001, value);
        _delay_ms(10);
    }
}
