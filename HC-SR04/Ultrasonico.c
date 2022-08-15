#include "Hormiga877.h"
#include "Ultrasonico.h"


void USBegin(char trigger, char echo)
{
    T1CON = 0x30; //Configuration for dt =1.06uS per TMR1 Step
    TMR1H = 0x00;
    TMR1L = 0x00;
    pinMode(trigger, OUTPUT);
    digitalWrite(trigger,LOW);
    pinMode(echo,INPUT);
}

unsigned int USRead(char trigger, char echo) //Returns Lecture in mm
{
    unsigned int buffer = 0;
    TMR1H = 0x00;
    TMR1L = 0x00;
    digitalWrite(trigger,HIGH);
    __delay_us(10);
    digitalWrite(trigger,LOW);
    while(!digitalRead(echo));
    TMR1ON = 1;
    while(digitalRead(echo));
    TMR1ON = 0;
    buffer = (int)(((TMR1H << 8) + TMR1L) / 3.7);
    buffer -= 7; //Calibration Constant
    return  buffer;
}
