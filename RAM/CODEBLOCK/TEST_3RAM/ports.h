#ifndef _PORTS_H_
#define _PORTS_H_

#define DIRBASE_A   0x2000
#define DIRBASE_B   0x4000

#define DDR_A           DIRBASE_A + 0
#define PORT_A          DIRBASE_A + 1
#define PIN_A           DIRBASE_A + 2

#define DDR_B           DIRBASE_B + 0
#define PORT_B          DIRBASE_B + 1
#define PIN_B           DIRBASE_B + 2

#endif // _PORTS_H_
