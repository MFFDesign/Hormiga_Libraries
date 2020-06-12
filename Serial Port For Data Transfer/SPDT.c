/*
 *	Serial Port for Data transfer (SPDT) v0.1
 *	Terminal Requiered : Clock, Data.
 *	Designed By : Carlos Eduardo Tonche Vazquez.
*/
#include "system.h"
#include "SPDT.h"


uint8_t Information = 0;
uint8_t Clocking = 0;


uint8_t SPDTBegin(uint8_t Data, uint8_t Clock)
{
	Information = Data;
	Clocking = Clock;
	pinMode(Information,OUTPUT);
	pinMode(Clocking,OUTPUT);
	digitalWrite(Information,LOW);
	digitalWrite(Clocking,LOW);
	return 0;
}


uint8_t SPDTWrite(uint8_t Data)
{
	for(uint8_t i=0;i<8;i++)
	{
		delay(20);
		digitalWrite(Clocking,HIGH);
		if(Data && (0x01 << i))
		{
			digitalWrite(Information,HIGH);
		}
		else
		{
			digitalWrite(Information,LOW);
		}
		digitalWrite(Clocking,LOW);
	}
}
