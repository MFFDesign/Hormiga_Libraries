/* 
 * File:   Timers.h
 * Author: ToncheLAP
 *
 * Created on January 4, 2022, 12:24 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#define COUNTERRISE       0xE0
#define COUNTERFALL         0xF0
#define TIMECOUNT   0xD0
#define II                      0x00
#define IV                     0x01
#define VIII                   0x02
#define XVI                   0x03
#define XXXII               0x04
#define LXIV                0x05
#define CXXVII            0x06
#define CCLVI               0x07

void TimerCeroBegin(char mode, char prescaler);
void TimerEveryTenthMS(void);
char TEveryTenthDone(char multiple);
char CountCeroDone(char count);
char  ReadCounterCero(void);
char TimerCeroDone(char offset);

char TimerOneDone(unsigned int offset);
unsigned int ReadTimerOne(void);
char CounterOneDone(unsigned int count);
void TimerOneEnable(char prescale);
void TimerOneShutdown(void);
void TimerOneBegin(char mode, char prescaler);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

