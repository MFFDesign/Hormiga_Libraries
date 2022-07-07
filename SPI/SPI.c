#include "Hormiga877.h"

char spiRead(void)
{
    while(!SSPSTATbits.BF); //check if buffer is full
    return SSPBUF;
}
void spiMasterbegin(void)
{
    // SDI is handled automatically by MSSP Module
    TRISC5 = 0; //SDO signal for SPI
    TRISC3 = 0; //CLK signal for SPI
    SSPSTAT = 0x00;
    SSPCON = 0x20; 
    /*
     * Configuration for :
     * SPI Mode, clock = SCK pin,!SS pin control disabled; can be used as IO
     * Idle state for clock is  a low level
     * enables serial port
     */

}
void spiWrite(char byte)
{
    SSPBUF = byte;
}

char spiDataAvailable(void)
{
    return (SSPSTAT & 0x01)? 1:0;
}