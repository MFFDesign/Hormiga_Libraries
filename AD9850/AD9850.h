/* 
 * File:   AD9850.h
 * Author: MikyDesktop
 *
 * Created on July 30, 2020, 5:53 PM
 */

#ifndef AD9850_H
#define	AD9850_H

void DDSBegin(char PORT[8], char CLK, char FUD, char RST);
char SetFrequency(unsigned long Freq);
void SetPhase(unsigned int phase);
void WritePort(char PORT[8],char data);
void SetTunningWord(char Frequency[4], char phase);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* AD9850_H */

