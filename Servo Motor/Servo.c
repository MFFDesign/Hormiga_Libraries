#include "system.h"

uint8_t ServoValue = 0;

void ServoAttach(uint8_t PinValue)
{
    ServoValue = PinValue;
    pinMode(PinValue,OUTPUT);
}

void ServoWrite(unsigned int DegreesValue)
{
    //800uS = 175 Min Time On
    //2200us = 475 Max Time On
    //20ms = 4350 points
    //DegreesValue most be between 0 - 300
    unsigned int i,timeOn,timeOff;
    timeOn = DegreesValue + 175;
    timeOff = 4350 - timeOn;
    for(i=0;i<10;i++)
    {
        digitalWrite(ServoValue,HIGH);
        for(uint16_t j=0;j<timeOn;j++)
        {
            __delay_us(1);
        }
        digitalWrite(ServoValue,LOW);
        for(uint16_t k=0;k<timeOff;k++)
        {
            __delay_us(1);
        }
    }
}

void ServoWriteCero(uint16_t deegres)
{
    unsigned int i;
    for(i=0;i<5;i++)
    {
        digitalWrite(ServoValue,HIGH);
        delayMicroseconds(800);
        digitalWrite(ServoValue,LOW);
        delayMicroseconds(19200);
    }
}
void ServoWriteNoventa(uint16_t deegres)
{
    unsigned int i;
    for(i=0;i<50;i++)
    {
        digitalWrite(ServoValue,HIGH);
        delayMicroseconds(1500);
        digitalWrite(ServoValue,LOW);
        delayMicroseconds(18500);
    }
}
