#include "Hormiga877.h"
#include "PASControl_RevA.h"
#include "ShiftRegister.h"

//Phase Angle Shot Control Varible Declaration
char sSrT = 0;
char PASControlBuffer = 0;

void ChangeToSSR(void)
{
    PASControlBuffer = 0x80;
    WriteRegister(PASControlBuffer,8,LSBF);
}

void ChangeToPAS(void)
{
    PASControlBuffer = 0x00;
    WriteRegister(PASControlBuffer,8,LSBF);
}

void PASControlBegin(char digTerminal)
{
    PASControlBuffer = 0x00;
    digTerminal = sSrT;
    pinMode(sSrT,OUTPUT);
    digitalWrite(sSrT,LOW);
    WriteRegister(PASControlBuffer,8,LSBF);
}

char SetPhase(char Phase)
{
    char buff = Phase;
    buff = Phase & 0x7F;
    buff = 128 - buff;
    WriteRegister(buff,8,LSBF);
    return buff;
}
