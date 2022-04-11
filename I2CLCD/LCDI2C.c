#include "Hormiga877.h"
#include "I2CWire.h"
#include "LCDI2C.h"

char DisplayControl = 0xFF;
char BacklightState = BLON;
char LCDDirection = 0;
char MSNibble = 0;
char LSNibble = 0;


void Blinking(char mode)
{
     if(mode == BlinkON)
    {
        DisplayControl |= BlinkON;
    }
    else if(mode == BlinkOFF)
    {
        DisplayControl &= BlinkOFF;
    }
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ; //I2C Begin
    SEN = 1;                                                        //I2CBegin
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LCDDirection;
    MSNibble = DisplayControl & 0xF0;
    MSNibble |= BacklightState;
    MSNibble &= Instruction;
    MSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    MSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    LSNibble = DisplayControl << 4;
    LSNibble |=BacklightState;
    LSNibble &= Instruction;
    LSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
    LSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
}

void Cursor(char mode)
{
     if(mode == CursorON)
    {
        DisplayControl &= CursorOFF;
        DisplayControl |= CursorON;
    }
    else if(mode == CursorOFF)
    {
        DisplayControl &= CursorOFF;
    }
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ; //I2C Begin
    SEN = 1;                                                        //I2CBegin
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LCDDirection;
    MSNibble = DisplayControl & 0xF0;
    MSNibble |= BacklightState;
    MSNibble &= Instruction;
    MSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    MSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    LSNibble = DisplayControl << 4;
    LSNibble |=BacklightState;
    LSNibble &= Instruction;
    LSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
    LSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
}

void Display(char mode)
{
    if(mode == DisplayON)
    {
        DisplayControl |= DisplayON;
    }
    else if(mode == DisplayOFF)
    {
        DisplayControl &= DisplayOFF;
    }
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ; //I2C Begin
    SEN = 1;                                                        //I2CBegin
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LCDDirection;
    MSNibble = DisplayControl & 0xF0;
    MSNibble |= BacklightState;
    MSNibble &= Instruction;
    MSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    MSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = MSNibble;
    LSNibble = DisplayControl << 4;
    LSNibble |=BacklightState;
    LSNibble &= Instruction;
    LSNibble |= Enable_H;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
    LSNibble &= Enable_L;
    while((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)) ;
    SSPBUF = LSNibble;
}

void LCDInit(char addrs)
{
        delay(15);
        char StringInit[5] = {0x02, 0x28,0x01, 0x0C, 0x06}; 
        LCDDirection = addrs;
        LCDDirection = LCDDirection << 1;
        LCDDirection &= 0xFE; //clear the 8th bit of byte to I2C Write Mode
        I2CStartTransaction();
        while(I2CWriteByte(LCDDirection))
        {
            I2CRepeatTransaction();
        }
        for(char i=0;i<5;i++)
        {
            MSNibble = StringInit[i] & 0xF0;
            MSNibble |= BacklightState;
            MSNibble &= Instruction;
            MSNibble |= Enable_H;
            I2CWriteByte(MSNibble);
            MSNibble &= Enable_L;
            I2CWriteByte(MSNibble);
            LSNibble = StringInit[i] << 4;
            LSNibble |=BacklightState;
            LSNibble &= Instruction;
            LSNibble |= Enable_H;
            I2CWriteByte(LSNibble);
            LSNibble &= Enable_L;
            I2CWriteByte(LSNibble);
            delay(5);
        }
        I2CStopTransaction();
}

void Backlight(char mode)
{
    BacklightState = mode;
}


void SendInstruction(char instr)
{
    I2CStartTransaction();
    while(I2CWriteByte(LCDDirection))
    {
        I2CRepeatTransaction();
    }
    MSNibble = instr & 0xF0;
    MSNibble |= BacklightState;
    MSNibble &= Instruction;
    MSNibble |= Enable_H;
    I2CWriteByte(MSNibble);
    MSNibble &= Enable_L;
     I2CWriteByte(MSNibble);
    LSNibble = instr << 4;
    LSNibble |=BacklightState;
    LSNibble &= Instruction;
    LSNibble |= Enable_H;
     I2CWriteByte(LSNibble);
    LSNibble &= Enable_L;
     I2CWriteByte(LSNibble);
     I2CStopTransaction();
}
    
void SendData(char databyte)
{
    I2CStartTransaction();                                               //I2CBegin
    while(I2CWriteByte(LCDDirection))
    {
        I2CRepeatTransaction();
    }
    MSNibble = databyte & 0xF0;
    MSNibble |= BacklightState;
    MSNibble |= Data;
    MSNibble |= Enable_H;
    I2CWriteByte(MSNibble);
    MSNibble &= Enable_L;
    I2CWriteByte(MSNibble);
    LSNibble = databyte << 4;
    LSNibble |=BacklightState;
    LSNibble |= Data;
    LSNibble |= Enable_H;
    I2CWriteByte(LSNibble);
    LSNibble &= Enable_L;
    I2CWriteByte(LSNibble);
    I2CStopTransaction();
}

void LCDClear(void)
{
    LCDSetCursor(1,1);
    LCDPrint("                ");
    LCDSetCursor(2,1);
    LCDPrint("                ");
    LCDSetCursor(1,1);
}
        
void LCDSetCursor(char row, char column)
{
    char location = 0;
    if(row == 1)
    {
        location = (0x80) + (column - 1);
        SendInstruction(location);
    }
    else if(row == 2)
    {
        location = 0xC0  + (column);// - 1);
        SendInstruction(location);
    }
}

void LCDWrite(char data)
{
    delay(4);
    SendData(data);
}

void LCDPrint(char *string)
{
    I2CStartTransaction();
    while(I2CWriteByte(LCDDirection))
    {
        I2CRepeatTransaction();
    }
    for(int i=0;string[i] != '\0';i++)
    {
        MSNibble = string[i] & 0xF0;
        MSNibble |= BacklightState;
        MSNibble |= Data;
        MSNibble |= Enable_H;
        I2CWriteByte(MSNibble);
        MSNibble &= Enable_L;
        I2CWriteByte(MSNibble);
        LSNibble = string[i] << 4;
        LSNibble |=BacklightState;
        LSNibble |= Data;
        LSNibble |= Enable_H;
        I2CWriteByte(LSNibble);
        LSNibble &= Enable_L;
        I2CWriteByte(LSNibble);
    }
    I2CStopTransaction();
}