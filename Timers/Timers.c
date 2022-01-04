#include "Hormiga877.h"
#include "Timers.h"


void TimerCeroBegin(char mode, char prescaler)
{
    switch(mode)
    {
        case COUNTERRISE:
            TMR0 = 0;
            OPTION_REG &= COUNTERRISE;
            OPTION_REG |= prescaler;
            break;
        case COUNTERFALL:
            TMR0 = 0;
            OPTION_REG &= COUNTERFALL;
            OPTION_REG |= prescaler;
            break;
        case TIMECOUNT:
            TMR0 = 0;
            OPTION_REG  &= TIMECOUNT;
            OPTION_REG |= prescaler;
            break;
    }
}

char CountCeroDone(char count)
{
    if(TMR0IF)
    {
        TMR0IF = 0;
        TMR0 = 255 - count;
        return 1;
    }
    else
    {
        return 0;
    }
    
}

char ReadCounterCero(void)
{
    return TMR0;
}


char TimerCeroDone(char offset)
{
    if(TMR0IF)
    {
        TMR0IF = 0;
        TMR0 = offset;
        return 1;
    }
    else
    {
        return 0;
    }
}

void TimerOneBegin(char mode, char prescaler)
{
    switch(mode)
    {
        case COUNTERRISE:
            T1CON &= 0x02;
            prescaler = prescaler << 4;
            T1CON |= prescaler;
            T1CON |= 0x01;
            break;
        case TIMECOUNT:
            T1CON &= 0x00;
            prescaler = prescaler << 4;
            T1CON |= prescaler;
            T1CON |= 0x01;
            break;
    }
}

void TimerOneShutdown(void)
{
    T1CON &= 0xFE;
}

void TimerOneEnable(char prescale)
{
    prescale = prescale << 4;
    T1CON |= prescale;
    T1CON |= 0x01;
}

char CounterOneDone(unsigned int count)
{
    if(TMR1IF)
    {
        TMR1IF = 0;
        TMR1 = 65535 - count;
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned int ReadTimerOne(void)
{
    return (TMR1H << 8) + TMR1L;
}


char TimerOneDone(unsigned int offset)
{
    if(TMR1IF)
    {
        TMR1IF = 0;
        TMR1 = 65535 - offset;
        return 1;
    }
    else
    {
        return 0;
    }
}
