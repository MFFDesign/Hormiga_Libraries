#include "EEPROM.h"
#include "Hormiga877.h"

void EEPROMSave(char addr, char data)
{
    while(EECON1bits.WR);
    EEADR = addr;
    EEDATA = data;
    EECON1bits.EEPGD = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    EECON1bits.WREN = 0;
}

char  EEPROMRead(char addr)
{
    while(EECON1bits.RD || EECON1bits.WR);
    EEADR = addr;
    EECON1bits.EEPGD = 0;
    EECON1bits.RD = 1;
    return EEDATA;
}

void SaveData(unsigned int Data, char InitAddress)
{
    char buffer = (Data >> 8) & 0xFF;
    EEPROMSave(buffer,InitAddress);
    buffer = Data & 0xFF;
    EEPROMSave(buffer, InitAddress + 1);
}

unsigned int  ReadData(char Address)
{
    char buffer = 0;
    char bufferB = 0;
    buffer = EEPROMRead(Address);
    bufferB = EEPROMRead(Address + 1);
    return (buffer << 8) + bufferB;
}