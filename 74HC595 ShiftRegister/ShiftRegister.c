#include "system.h"
#include "ShiftRegister.h"


char M1FWD = 0x04; //Out 1 and Out 2
char M1BWD = 0x08; //Out 1 and Out 2

char M2FWD = 0x02; //Out 3 and Out 4
char M2BWD = 0x01; //Out 3 and Out 4

char M3FWD = 0x40; //Out 5 and 6
char M3BWD = 0x80; //Out 5 and 6

char M4FWD = 0x10; //Out 7 and Out 8
char M4BWD = 0x20; //Out 7 and Out 8

char dataInB = 0;
char clkB = 0;
char latchB = 0;
char clrPortB = 0;
char OEB = 0;

void ShiftRegisterBegin(char dataInA,char clkA, char latchA, char clrPortA, char OEA)
{
    dataInB = dataInA;
	clkB = clkA;
	latchB = latchA;
	clrPortB = clrPortA;
	OEB = OEA;
	pinMode(OEB,OUTPUT);
	pinMode(clrPortB,OUTPUT);
	pinMode(latchB,OUTPUT);
	pinMode(clkB,OUTPUT);
	pinMode(dataInB,OUTPUT);
	digitalWrite(dataInB,LOW);
	digitalWrite(latchB,LOW);
	digitalWrite(clkB,LOW);
	digitalWrite(clrPortB,HIGH);
	digitalWrite(OEB,LOW);
}

void WriteRegister(char data,char bits,char byteTransfer)
{
	char buffer = 0;
    switch(byteTransfer)
    {
        case MSBF:
            for(int i=0;i<bits;i++)
            {
                buffer = data << i;
                buffer &= 0x80;
                if(buffer)
                {
                    digitalWrite(dataInB,HIGH);
                }
                else
                {
                    digitalWrite(dataInB,LOW);
                }
                digitalWrite(clkB,HIGH);
                delay(5);
                digitalWrite(clkB,LOW);
                delay(5);
            }
            break;
        case LSBF:
            for(int i=0;i<bits;i++)
            {
                buffer = data >> i;
                buffer &= 0x01;
                if(buffer)
                {
                    digitalWrite(dataInB,HIGH);
                }
                else
                {
                    digitalWrite(dataInB,LOW);
                }
                digitalWrite(clkB,HIGH);
                delay(5);
                digitalWrite(clkB,LOW);
                delay(5);
            }
            break;
    }
	digitalWrite(latchB,HIGH);
	delay(5);
	digitalWrite(latchB,LOW);
}

char RegisterStatus(char status)
{
	switch(status)
	{
		case DISABLE:
			digitalWrite(OEB,HIGH);
			return 0;
		break;
		case ENABLE:
			digitalWrite(OEB,LOW);
			return 1;
		break;
	}
}


void MoveMotor(char motor,char Movement)
{
	static char Register = 0;
    char buffer = 0;

	switch(motor)
	{
		case M1:
            switch(Movement)
            {
                case FWD:
                    buffer = 0x04;
                    Register &= 0xF3;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case BWD:
                    buffer = 0x08;
                    Register &= 0xF3;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case STOP:
                    Register &= 0xF3;
                    WriteRegister(Register,8,LSBF);
                    break;
            }
            
            
		break;
		case M2:
            switch(Movement)
            {
                case FWD:
                    buffer = 0x02;
                    Register &= 0xFC;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case BWD:
                    buffer = 0x01;
                    Register &= 0xFC;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case STOP:
                    Register &= 0xFC;
                    WriteRegister(Register,8,LSBF);
                    break;
            }
		break;
		case M3:
            switch(Movement)
            {
                case FWD:
                    buffer = 0x40;
                    Register &= 0x3F;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case BWD:
                    buffer = 0x80;
                    Register &= 0x3F;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case STOP:
                    Register &= 0x3F;
                    WriteRegister(Register,8,LSBF);
                    break;
            }
		break;
		case M4:
            switch(Movement)
            {
                case FWD:
                    buffer = 0x10;
                    Register &= 0xCF;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case BWD:
                    buffer = 0x20;
                    Register &= 0xCF;
                    Register |= buffer;
                    WriteRegister(Register,8,LSBF);
                    break;
                case STOP:
                    Register &= 0xCF;
                    WriteRegister(Register,8,LSBF);;
                    break;
            }
		break;
	}
}

void StopAllMotor(void)
{
	digitalWrite(clrPortB,LOW);
	delay(10);
	digitalWrite(clrPortB,HIGH);
    delay(10);
    digitalWrite(clrPortB,LOW);
}
