#include "system.h"
#include "I2CWire.h"

void I2CBegin(char Operation, const unsigned long param)
{
    switch(Operation)
    {
        case MASTER:
            SSPCON = 0b00101000;            //SSP Module as Master
            SSPCON2 = 0;
            SSPADD = (_XTAL_FREQ/(4*param))-1; //Setting Clock Speed
            SSPSTAT = 0;
            TRISC3 = 1;                   //Setting as input as given in datasheet
            TRISC4 = 1;    
            break;
        case SLAVE:
            SSPSTAT = 0x80;    
            SSPADD = param; //Setting address
            SSPCON = 0x36;    //As a slave device
            SSPCON2 = 0x01;
            TRISC3 = 1;       //Setting as input as given in datasheet
            TRISC4 = 1;       //Setting as input as given in datasheet
            GIE = 1;          //Global interrupt enable
            PEIE = 1;         //Peripheral interrupt enable
            SSPIF = 0;        //Clear interrupt flag
            SSPIE = 1;        //Synchronous serial port interrupt enable
            break;
    }
}
void I2CMasterWaiting()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); //Transmit is in progress
}

void I2CMasterStart(void)
{
  I2CMasterWaiting();    
  SEN = 1;             //Initiate start condition
}
void I2CMasterRepeatedStart(void)
{
  I2CMasterWaiting();
  RSEN = 1;           //Initiate repeated start condition
}
void I2CMasterStop(void)
{
  I2CMasterWaiting();
  PEN = 1;           //Initiate stop condition
}
void I2CMasterWrite(unsigned d)
{
  I2CMasterWaiting();
  SSPBUF = d;         //Write data to SSPBUF
}

unsigned short I2CMasterRead(unsigned short a)
{
  unsigned short temp;
  I2CMasterWaiting();
  RCEN = 1;
  I2CMasterWaiting();
  temp = SSPBUF;      //Read data from SSPBUF
  I2CMasterWaiting();
  ACKDT = (a)?0:1;    //Acknowledge bit
  ACKEN = 1;          //Acknowledge sequence
  return temp;
}
