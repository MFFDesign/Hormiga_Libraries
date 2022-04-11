#include "Hormiga877.h"
#include "I2CWire.h"

char bufferMemory = 0;

void EEPROMWrite(char MemSlct, unsigned int address, char data)
{
    I2CStartTransaction();
    //1. Escribes la direccion de la EEPROM a 
    //a Donde vas a escribir y esperas el ACK
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory &= 0xFE; //Address to Write Mode
    while(I2CWriteByte(bufferMemory))
    {
        I2CRepeatTransaction();
    }
    bufferMemory = address >> 8;
    I2CWriteByte(bufferMemory);
    bufferMemory &= 0xFF;
    I2CWriteByte(bufferMemory);
    I2CWriteByte(data);
    I2CStopTransaction();
}

void EEPROMWritePage(char MemSlct, unsigned int address, char *data, unsigned int lenght )
{
    I2CStartTransaction();
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory &= 0xFE; //Addres to Write Mode
    while(I2CWriteByte(bufferMemory))
    {
        I2CRepeatTransaction();
    }
    bufferMemory = address >> 8;
    I2CWriteByte(bufferMemory);
    bufferMemory &= 0xFF;
    I2CWriteByte(bufferMemory);
    for(unsigned int i=0;i<lenght;i++)
    {
        I2CWriteByte(data[i]);
    }
    I2CStopTransaction();
}

char EEPROMRead(char MemSlct, unsigned int address)
{
    char data;
    I2CStartTransaction();
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory &= 0xFE; //Addres to Write Mode
    while(I2CWriteByte(bufferMemory))
    {
        I2CRepeatTransaction();
    }
    bufferMemory = address >> 8;
    I2CWriteByte(bufferMemory);
    bufferMemory &= 0xFF;
    I2CWriteByte(bufferMemory);
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory |= 0x01; //Addres to Read Mode
    I2CRepeatTransaction();
    I2CWriteByte(bufferMemory);
    data = I2CReadByte();
    I2CNACK();
    I2CStopTransaction();
    return data;
    
}

void EEPROMReadPage(char MemSlct, unsigned int address, char *data, unsigned int lenght)
{
    I2CStartTransaction();
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory &= 0xFE; //Addres to Write Mode
    while(I2CWriteByte(bufferMemory))
    {
        I2CRepeatTransaction();
    }
    bufferMemory = address >> 8;
    I2CWriteByte(bufferMemory);
    bufferMemory &= 0xFF;
    I2CWriteByte(bufferMemory);
    I2CRepeatTransaction();
    bufferMemory = MemSlct;
    bufferMemory = bufferMemory << 1;
    bufferMemory |= 0x01; //Addres to Read Mode
    I2CWriteByte(bufferMemory);
    for(unsigned int i=0;i<lenght;i++)
    {
        data[i] = I2CReadByte();
        I2CACK();
    }
    I2CStopTransaction();
}