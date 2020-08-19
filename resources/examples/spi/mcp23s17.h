#ifndef MCP23S17_H
#define MCP23S17_H
#include <stdint.h>
// define all register addresses in enum. This will help to easily understand the program.
// We have referred this address from data-sheet of mcp23s17. (Page No 5).
typedef enum {
    IODIRA = 0x00,
    IODIRB = 0x01,
    IPOLA = 0x02,
    IPOLB = 0x03,
    GPINTENA = 0x04,
    GPINTENB = 0x05,
    DEFVALA = 0x06,
    DEFVALB = 0x07,
    INTCONA = 0x08,
    INTCONB = 0x09,
    IOCONA = 0x0A,
    IOCONB = 0x0B,
    GPPUA = 0x0C,
    GPPUB = 0x0D,
    INTFA = 0x0E,
    INTFB = 0x0F,
    INTCAPA = 0x10,
    INTCAPB = 0x11,
    MCPGPIOA = 0x12,
    MCPGPIOB = 0x13,
    OLATA = 0x14,
    OLATB = 0x15
} regName;

typedef enum {PORTA = 0,PORTB = 1} port;

typedef enum {OUTPUT = 0, INPUT = 1, INPUT_PULLUP = 2} mode;

typedef enum{ RISING = 0, FALLING = 1, BOTH = 2} itType;

typedef enum {LOW = 0, HIGH = 1} value;

void begin();
void mcpPinMode(port p, uint8_t bitNum, mode m);
void mcpDigitalWrite(port p, uint8_t bitNum, value val);
void writeReg(regName reg, uint8_t val);
uint8_t readReg(regName reg);
void setBitInReg(regName reg, uint8_t bitNum);
void clearBitInReg(regName reg, uint8_t bitNum);

#endif
