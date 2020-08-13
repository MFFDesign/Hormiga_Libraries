#include "system.h"
#include "AD9850.h"
//AD9850

#define RefCLK 			125000000
#define TuneRes 		0.0291
#define MaxFreq			62500000
#define MaxFreqChange	23000000
#define MinIncrement	11.25
#define FreqConstant	34.3597 //bits / Hz

/*
	AD9850 Control Bytes
	The frequency tuning, control, and phase modulation words
	are loaded into the AD9850 via parallel byte or serial loading
	format. The parallel load format consist on five interative
	loads of  8-bit control word (byte).
	
	First byte - Controls phase modulation, power-down enable, and loading format.
	Second byte - Fiveth byte  -  32 bit tunning word.
	
	Fout = ( Tw * RefCLK ) / 2^32
	
	Fout = Frequency output signal in MHz
	Tw 	 = Tuning Word (32 bit)
	RefCLK = Reference clock frequency in MHz
	
	Fout * 34.35 = Tw
	
	(Fout << 5) + 2 = Tw
	
*/

char dataFreqPort[8] = {0,0,0,0,0,0,0,0};
char DDSRegister[5] = {0,0,0,0,0};
char Reloj = 0;
char FrUpdate = 0;
char DDSPhase = 0;

void DDSBegin(char PORT[8], char CLK, char FUD, char RST)
{
	DDSRegister[0] = 0x04;
	Reloj = CLK;
	FrUpdate = FUD;
	pinMode(RST,OUTPUT);
	pinMode(FUD,OUTPUT);
	pinMode(CLK,OUTPUT);
	digitalWrite(RST,HIGH);
	digitalWrite(FUD,LOW);
	digitalWrite(CLK,LOW);
	digitalWrite(RST,LOW);
	for(char i=0;i<8;i++)
	{
		pinMode(PORT[i],OUTPUT);
		dataFreqPort[i] = PORT[i];
		digitalWrite(PORT[i],LOW);
	}
	for(char i=0;i<5;i++)
	{
		WritePort(dataFreqPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(50);
		digitalWrite(Reloj,LOW);
		delay(50);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(50);
	digitalWrite(FrUpdate,LOW);
	delay(50);
}

void SetFreq(double Frequency)
{
	uint32_t temp = 0;
	temp = Frequency / TuneRes;
	DDSRegister[1] = temp & 0xFF;
	DDSRegister[2] = (temp >> 8) & 0xFF;
	DDSRegister[3] = (temp >> 16) & 0xFF;
	DDSRegister[4] = (temp >> 24) & 0xFF;
	for(char i=0;i<5;i++)
	{
		WritePort(dataFreqPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(50);
		digitalWrite(Reloj,LOW);
		delay(50);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(50);
	digitalWrite(FrUpdate,LOW);
	delay(50);
}
char SetFrequency(unsigned long Freq) //Hertz
{
	unsigned long temp = 0;
	temp = (Freq << 5) + 2;
	/*
		DDSRegister[4] = temp & 0x0F;
		DDSRegister[3] = (temp >> 8) & 0xFF;
		DDSRegister[2] = (temp >> 16) & 0F0F;
		DDSRegister[1] = (temp >> 24) & 0xFF;
	*/
	for(char i=0;i<4;i++)
	{
		DDSRegister[4-i] = (temp >> i*8) & 0xFF;
	}
	for(char i=0;i<5;i++)
	{
		WritePort(dataFreqPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(50);
		digitalWrite(Reloj,LOW);
		delay(50);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(50);
	digitalWrite(FrUpdate,LOW);
	delay(50);
}

void SetPhase(unsigned int phase) //Degrees
{
	char temp = phase / MinIncrement;
	temp = (temp << 3) & 0x0C;
	DDSRegister[0] = temp;
	for(char i=0;i<5;i++)
	{
		WritePort(dataFreqPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(50);
		digitalWrite(Reloj,LOW);
		delay(50);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(50);
	digitalWrite(FrUpdate,LOW);
	delay(50);
}

void WritePort(char PORT[8],char data)
{
	char temp = 0;
	for(int i=0;i<8;i++)
	{
		temp = (data >> i) & 0x01;
		if(temp == 1)
		{
			digitalWrite(PORT[i],HIGH);
		}
		else
		{
			digitalWrite(PORT[i],LOW);
		}
	}
}

void SetTunningWord(char Frequency[4], char phase)
{
	char temp[5] = {0,0,0,0,0};
	temp[0] = (phase << 3) & 0x0C;
	temp[1] = Frequency[3];
	temp[2] = Frequency[2];
	temp[3] = Frequency[1];
	temp[4] = Frequency[0];
	for(char i=0;i<5;i++)
	{
		WritePort(dataFreqPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(50);
		digitalWrite(Reloj,LOW);
		delay(50);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(50);
	digitalWrite(FrUpdate,LOW);
	delay(50);
}