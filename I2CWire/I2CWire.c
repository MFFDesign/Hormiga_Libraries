#include "Hormiga877.h"
#include "I2CWire.h"

void I2CBegin(const unsigned long Hertz) //Set to 100KHz
{
    TRISC3 = 1; //Set  Input SCL
    TRISC4 = 1; //Set as Input SDA
    SSPCON = 0x28; //I2C Master Mode, clock  = Fosc / 4 * (SSPADD + 1))
    SSPCON2 = 0x00;
    SSPADD =(_XTAL_FREQ/(4*Hertz)) - 1;;// 0x2F; //100KHz;//(_XTAL_FREQ / (4 * VTrans)) - 1;  // (4 * 100 * VTransfer) SCL FRequency needs to be Check
    SSPSTAT = 0x00; // It holds aditional configurations asSMP and CKD, Needs to be checked
    __delay_us(75); //Trigger to OSCX
}

void I2CStartTransaction(void)
{
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SEN = 1;
}

void I2CIDLECheck(void)
{
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
}
char  I2CWriteByte(char databyte)
{
    I2CIDLECheck();
    SSPBUF = databyte;
    while(!SSPIF); // check if transaction is done
    SSPIF = 0;
    return ACKSTAT;
}

void I2CRepeatTransaction(void)
{
    I2CIDLECheck();
    RSEN = 1;
}

void I2CStopTransaction(void)
{
    I2CIDLECheck();
    PEN = 1;
}

char I2CReadByte(void)
{
    I2CIDLECheck();
    RCEN = 1; //Enable Recive Mode I2C
    while(!SSPIF); //Waits until the trasaction is done
    SSPIF = 0; // clear Flag
    I2CIDLECheck();
    return SSPBUF;
}


void I2CACK(void)
{
    ACKDT = 0;
    I2CIDLECheck();
    ACKEN = 1; //Send ACK
}

void I2CNACK(void)
{
    ACKDT = 1;
    I2CIDLECheck();
    ACKEN = 1; //Send NACK
}

char ScanDevices(char *ResultList, char TotalDevices)
{
    char buffer = 0;
    char counter = 0;
    for(char address = 0; address < 127;address++)
    {
        if(counter < TotalDevices)
        {
            I2CStartTransaction();
            if(!I2CWriteByte(address << 1))
            {
                buffer = address & 0xF0;
                buffer = buffer << 1;
                buffer |= (address & 0x0F);
                buffer = buffer >> 1;
                ResultList[counter] = buffer;
                counter++;
            }
        }
        I2CStopTransaction();
    }
    return counter;
}