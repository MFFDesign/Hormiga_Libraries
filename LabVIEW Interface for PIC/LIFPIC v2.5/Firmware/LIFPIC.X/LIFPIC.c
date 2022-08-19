/*
 * LabVIEW Interface for PIC  6/Nov/2019
 * Designed By : Carlos Eduardo Tonche Vazquez.
 * 
*/
#include "Hormiga877.h"
#include "LIFPIC.h"
#include "Ultrasonico.h"

#define PINMODE 		0x05
#define DIGITALWRITE	0x06
#define DIGTALREAD		0x07
#define ANALOGREAD		0x08
#define ANALOGWRITE		0x09
#define PBREAD          0x0A
#define READPORT 0x0B
#define WRITEPORT 0x0C
#define READUS 0x0D
#define TRISPORT 0x15
enum MaquinaEstados{Enviar,Recibir,Decode};
enum MaquinaEstados Estado;

uint8_t BufferLenght = 4;
char Informacion[4];
char DataEnviar[2];
uint8_t LED = 14;
uint8_t Val = 0;
uint16_t Dato = 0;
unsigned int buffer  = 0;

unsigned char Trigger = 2;
unsigned char Echo = 3;

uint8_t Valor = 0;
char dada = 0;
void setup(void)
{
	SerialBegin(9600);
    pinMode(LED,OUTPUT);
    USBegin(Trigger,Echo);
	while(Valor != 1)
	{
        digitalWrite(LED,HIGH);
        dada = SerialRead();
        SerialWrite('k');
        if(dada == 'k')
        {
            Valor = 1;
        }
        else
        {
            Valor = 0;
        }
	}
    Valor = 0;
    dada = 0;
    digitalWrite(LED,LOW);
	Estado = Recibir;
}

void loop(void)
{
	if(SerialAvailable() >= 0)
	{
		switch(Estado)
		{
			case Decode:
				
				Dato = ProcessCommand(Informacion[0],Informacion[1],Informacion[2],Informacion[3]);
				//DataEnviar[0] = Dato & 0xFF00;
				DataEnviar[0] = (Dato >> 8);
				DataEnviar[1] = Dato & 0xFF;
				Estado = Enviar;
			break;
			case Recibir:
				while(Valor != 1)
				{
					for(int i=0;i<BufferLenght;i++)
					{
						Informacion[i] = SerialRead();
					}
                    dada = SerialRead();
                    if(dada == 'k')
                    {
                        Valor = 1;
                    }
                    else
                    {
                        Valor = 0;
                    }
				}
                dada = 0;
                Valor = 0;
                Estado = Decode;
			break;
			case Enviar:
                while(Valor != 1)
                {
                    for(int j=0;j<2;j++)
                    {
                        SerialWrite(DataEnviar[j]);
                        
                    }
                    SerialWrite(';');
                    dada = SerialRead();
                    if(dada == 'k')
                    {
                        Valor = 1;
                    }
                    else
                    {
                        Valor = 0;
                    }
                }
                Valor = 0;
                dada = 0;
				Estado = Recibir;
			break;
		}
	}
}

uint16_t ProcessCommand(uint8_t instruction, uint8_t port, uint8_t MSBData, uint8_t LSBData)
{
    uint16_t data = 0;
		switch(instruction)
		{
			case PINMODE:
				if(port > 24)
				{
					port = 24;
				}
				pinMode(port,LSBData);
				return 1;
			break;
			case DIGITALWRITE:
				if(port > 24)
				{
					port = 24;
				}
				digitalWrite(port,LSBData);
				return LSBData;
			break;
			case DIGTALREAD:
				if(port > 24)
				{
					port = 24;
				}
				return digitalRead(port);
			break;
			case ANALOGREAD:
				return analogRead(port);
			break;
			case ANALOGWRITE:
//                Limites Agregados varian segund la placa Hormiga que se use
//				if(port > 6)
//				{
//					port = 6;
//				}
//				else if(port < 5)
//				{
//					port = 5;
//				}
                data = (MSBData << 8) + LSBData;
				analogWrite(port,data);
				return port;
			break;
            case PBREAD:
                return PBRead(port);
            break;
            case READPORT:
                if(port == 0x0B)
                {
                    return PORTB;
                }
                else if(port == 0x0D)
                {
                    return PORTD;
                }
                break;
            case WRITEPORT:
                if(port == 0x0B)
                {
                    PORTB = LSBData;
                }
                else if(port == 0x0D)
                {
                    PORTD = LSBData;
                }
                break;
            case READUS:
                data = USRead(Trigger,Echo);
                return data;
                break;
            case TRISPORT:
                if(port == 0x0B)
                {
                    TRISB = LSBData;
                }
                else if(port == 0x0D)
                {
                    TRISD = LSBData;
                }
                return TRISPORT;
                break;
		}
}