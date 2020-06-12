#include "system.h"
#include "LCD16x2.h"
/*
 * 
 * Library created to operate the LCD with 16 Columns and 2 Rows
 * basen on the HITACHI HD44780.
 * 
 */

int RSPin = 0;
int ENPin = 0;
int RWPin = 0;
int d4Pin = 0;
int d5Pin = 0;
int d6Pin = 0;
int d7Pin = 0;

void lcdBegin(char RS, char EN, char R_W, char d4, char d5, char d6,char d7)
{
    RSPin = RS;
    ENPin = EN;
    RWPin = R_W;
    d4Pin = d4;
    d5Pin = d5;
    d6Pin = d6;
    d7Pin = d7;
    pinMode(RS,OUTPUT);
    pinMode(EN,OUTPUT);
    pinMode(R_W,OUTPUT);
    pinMode(d4,OUTPUT);
    pinMode(d5,OUTPUT);
    pinMode(d6,OUTPUT);
    pinMode(d7,OUTPUT);
    delay(15);
    WriteInstruction(0x02);
    WriteInstruction(0x28);
    WriteInstruction(0x01);
    WriteInstruction(0x0C);
    WriteInstruction(0x06);
}
void lcdClear(void)
{
    WriteInstruction(0x01);
}
void lcdSetCursor(char row, char column)
{
    char location = 0;
    if(row == 1)
    {
        location = (0x80) + (column - 1);
        WriteInstruction(location);
    }
    else if(row == 2)
    {
        location = 0xC0  + (column - 1);
        WriteInstruction(location);
    }
    else
    {
        return;
    }
}
void lcdWrite(char data)
{
    delay(8);
    WriteData(data);
}
void lcdPrint(char *string)
{
    for(int i=0;string[i] != '\0';i++)
    {
        lcdWrite(string[i]);
    }
}


void lcdShiftRight(void)
{
    lcdCommand(0x01,INSTRUCTION);
    lcdCommand(0x0C,INSTRUCTION);
}
void lcdShiftLeft(void)
{
    lcdCommand(0x01,INSTRUCTION);
    lcdCommand(0x08,INSTRUCTION);
}
void lcdWritePort(char data)
{
    if(data & 0x01)
    {
        digitalWrite(d4Pin,HIGH);
    }
    else
    {
        digitalWrite(d4Pin,LOW);
    }
    if(data & 0x02)
    {
        digitalWrite(d5Pin,HIGH);
    }
    else
    {
        digitalWrite(d5Pin,LOW);
    }
    if(data & 0x04)
    {
        digitalWrite(d6Pin, HIGH);
    }
    else
    {
        digitalWrite(d6Pin,LOW);
    }
    if(data & 0x08)
    {
        digitalWrite(d7Pin,HIGH);
    }
    else
    {
        digitalWrite(d7Pin,LOW);
    }
    
}

void WriteInstruction(char instruction)
{
    char MSNibble = 0;
    char LSNibble = 0;
    MSNibble = instruction & 0xF0;
    MSNibble = (MSNibble >> 4);
    LSNibble = instruction & 0x0F;
    ByteByNibble(MSNibble);
    digitalWrite(RSPin,LOW);
    digitalWrite(RWPin,LOW);
    digitalWrite(ENPin,HIGH);
    delay(5);
//    asm("NOP");
    digitalWrite(ENPin,LOW);
    delay(5);
    ByteByNibble(LSNibble);
    digitalWrite(ENPin,HIGH);
    delay(5);
//    asm("NOP");
    digitalWrite(ENPin,LOW);
    delay(3);
}

void WriteData(char data)
{
    char MSNibble = 0;
    char LSNibble = 0;
    MSNibble = data & 0xF0;
    MSNibble = (MSNibble >> 4);
    LSNibble = data & 0x0F;
    ByteByNibble(MSNibble);
    digitalWrite(RSPin,HIGH);
    digitalWrite(RWPin,LOW);
    digitalWrite(ENPin,HIGH);
    delay(5);
//    asm("NOP");
    digitalWrite(ENPin,LOW);
    delay(5);
    ByteByNibble(LSNibble);
    digitalWrite(ENPin,HIGH);
    delay(5);
//    asm("NOP");
    digitalWrite(ENPin,LOW);
    delay(3);
}

void ByteByNibble(char NibbleValue)
{
    switch(NibbleValue)
    {
        case 0x00:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x01:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x02:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x03:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x04:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x05:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x06:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x07:
            digitalWrite(d7Pin,LOW);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x08:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x09:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x0A:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x0B:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,LOW);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x0C:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x0D:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,LOW);
            digitalWrite(d4Pin,HIGH);
            break;
        case 0x0E:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,LOW);
            break;
        case 0x0F:
            digitalWrite(d7Pin,HIGH);
            digitalWrite(d6Pin,HIGH);
            digitalWrite(d5Pin,HIGH);
            digitalWrite(d4Pin,HIGH);
            break; 
    }
}