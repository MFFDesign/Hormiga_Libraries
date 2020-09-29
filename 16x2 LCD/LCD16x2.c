#include "Hormiga877.h"
#include "LCD16x2.h"
/*
 * 
 * Library created to operate the LCD with 16 Columns and 2 Rows
 * basen on the HITACHI HD44780.
 * 
 */

uint8_t RSPin = 0;
uint8_t ENPin = 0;
uint8_t RWPin = 0;
uint8_t d4Pin = 0;
uint8_t d5Pin = 0;
uint8_t d6Pin = 0;
uint8_t d7Pin = 0;

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

/*
 * Pendientes de Revisar
 * 
void BlinkCursor(char mode)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,LOW);
	if(mode == ENABLE)
	{
		lcdWriteByte(0x09); //BlinkCursor ON
		delay(5);
	}
	else if(mode == DISABLE)
	{
		lcdWriteByte(0x08); //BlinkCursor OFF
		delay(5);
	}
	
	
}
void ShowCursor(char mode)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,LOW);
	if(mode == ENABLE)
	{
		lcdWriteByte(0x0A); //Cursor ON
		delay(5);
	}
	else if(mode == DISABLE)
	{
		lcdWriteByte(0x08); //Cursor OFF
		delay(5);
	}
}
void Display(char mode)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,LOW);
	if(mode == ENABLE)
	{
		lcdWriteByte(0x0C); //Display ON
		delay(5);
	}
	else if(mode == DISABLE)
	{
		lcdWriteByte(0x08); //Display OFF
		delay(5);
	}
}

void ReturnHome(void)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,HIGH);
	lcdWriteByte(RHome);
	delay(5);
}
 
void ShiftTextLeft(void)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,HIGH);
	lcdWriteByte(0x18); // Recorrer una posicion a la izquierda 0b 0001 1000 = 0x18;
	delay(5);
}
void ShiftTextRight(void)
{
	digitalWrite(RWT,LOW);
	digitalWrite(RST,HIGH);
	lcdWriteByte(0x1F); // Recorrer una posicion a la derecha
	delay(5);
}
void lcdWriteByte(char data) 
{
	char LSNibble = 0x0F & data;
	char MSNibble = data >> 4;   
	char temp = 0x00;
	
	for(char i=0;i<4;i++)
	{
		temp = (MSNibble >> i) & 0x01;
		if(temp)
		{
			digitalWrite(Terminals[i],HIGH);
		}
		else
		{
			digitalWrite(Terminals[i],LOW);
		}
	}
	digitalWrite(ETG,HIGH);
	delay(10);
	digitalWrite(ETG,LOW);
	delay(10);
	for(char i=0;i<4;i++)
	{
		temp = (LSNibble >> i) & 0x01;
		if(temp)
		{
			digitalWrite(Terminals[i],HIGH);
		}
		else
		{
			digitalWrite(Terminals[i],LOW);
		}
	}
	digitalWrite(ETG,HIGH);
	delay(10);
	digitalWrite(ETG,LOW);
	delay(10);
}
void lcdWriteByte(char data)
{
	char temp = 0;
	for(char i=0;i<8;i++)
	{
		temp = (data >> i) & 0x01;
		if(i < 3)
		{
			if(temp)
			{
				digitalWrite(Terminals[i],HIGH);
			}
			else
			{
				digitalWrite(Terminals[i],LOW);
			}
		}
		else if(i == 3)
		{
			if(temp)
			{
				digitalWrite(Terminals[i],HIGH);
			}
			else
			{
				digitalWrite(Terminals[i],LOW);
			}
			delay(10);
			digitalWrite(ET,HIGH);
			delay(10);
			digitalWrite(ET,LOW);
		}
		else
		{
			if(temp)
			{
				digitalWrite(Terminals[i-4],HIGH);
			}
			else
			{
				digitalWrite(Terminals[i-4],LOW);
			}
		}
		
	}
}
 */