#include "Hormiga877.h"
#include "SPI.h"

void MAX6675Begin(char pin)
{
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
}

unsigned int ReadTemperature(char Sensor)
{
    char MSBTempe = 0;
    char LSBTempe = 0;
    digitalWrite(Sensor,LOW);
    spiWrite(0xAA);
    if(spiDataAvailable())
    {
        MSBTempe = spiRead();
    }
    spiWrite(0xAA);
    if(spiDataAvailable())
    {
        LSBTempe = spiRead();
    }
    digitalWrite(Sensor,HIGH);
    return (MSBTempe << 5) + (LSBTempe >> 3);
}
