#include "Hormiga877.h"
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
uint8_t DataPort = 0;
uint8_t DDSRegister[5] = {0,0,0,0,0};
uint8_t Reloj = 0;
uint8_t FrUpdate = 0;
uint8_t DDSPhase = 0;
unsigned int R = 10;

void DDSBegin(uint8_t PORT, uint8_t CLK, uint8_t FUD, uint8_t RST)
{
	DDSRegister[0] = 0x04;
	Reloj = CLK;
	FrUpdate = FUD;
	DataPort = PORT;
	pinMode(RST,OUTPUT);
	pinMode(FUD,OUTPUT);
	pinMode(CLK,OUTPUT);
    pinMode(PORT,0x00);
    digitalWrite(PORT,0x00);
    digitalWrite(RST,HIGH);
    digitalWrite(FUD,LOW);
    delay(R);
    digitalWrite(RST,LOW);
    digitalWrite(FUD,HIGH);
    delay(R);
    digitalWrite(FUD,LOW);
	for(char i=0;i<5;i++)
	{
		digitalWrite(PORT,DDSRegister[i]);
		digitalWrite(CLK,HIGH);
		delay(R);
		digitalWrite(CLK,LOW);
		delay(R);
	}
	digitalWrite(FUD,HIGH);
	delay(R);
	digitalWrite(FUD,LOW);
}

void SetFreq(double Frequency)
{
	uint32_t temp = 0;
	temp = Frequency / TuneRes;
    DDSRegister[0] = 0x00;
	DDSRegister[4] = temp & 0xFF;
	DDSRegister[3] = (temp >> 8);
	DDSRegister[2] = (temp >> 16);
	DDSRegister[1] = (temp >> 24);
    digitalWrite(FrUpdate,HIGH);
	delay(10);
	digitalWrite(FrUpdate,LOW);
	delay(10);
	for(uint8_t i=0;i<5;i++)
	{
		digitalWrite(DataPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(10);
		digitalWrite(Reloj,LOW);
		delay(10);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(10);
	digitalWrite(FrUpdate,LOW);
	delay(10);
}

void SetPhase(double phase) //Degrees
{
	char temp = phase / MinIncrement;
	temp = temp << 3;
	DDSRegister[0] = temp;
    digitalWrite(FrUpdate,HIGH);
	delay(10);
	digitalWrite(FrUpdate,LOW);
	delay(10);
	for(char i=0;i<5;i++)
	{
		digitalWrite(DataPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(10);
		digitalWrite(Reloj,LOW);
		delay(10);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(10);
	digitalWrite(FrUpdate,LOW);
	delay(10);
}

void SetTunningWord(char Frequency[4], char phase)
{
	DDSRegister[0] = phase << 3; //& 0x04;
	DDSRegister[1] = Frequency[0];
	DDSRegister[2] = Frequency[1];
	DDSRegister[3] = Frequency[2];
	DDSRegister[4] = Frequency[3];
    digitalWrite(FrUpdate,HIGH);
	delay(R);
	digitalWrite(FrUpdate,LOW);
	delay(R);
	for(char i=0;i<5;i++)
	{
		digitalWrite(DataPort,DDSRegister[i]);
		digitalWrite(Reloj,HIGH);
		delay(R);
		digitalWrite(Reloj,LOW);
		delay(R);
	}
	digitalWrite(FrUpdate,HIGH);
	delay(R);
	digitalWrite(FrUpdate,LOW);

}
