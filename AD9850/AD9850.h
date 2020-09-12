/* 
 * File:   AD9850.h
 * Author: MikyDesktop
 *
 * Created on July 30, 2020, 5:53 PM
 */

#ifndef AD9850_H
#define	AD9850_H

void DDSBegin(uint8_t PORT, uint8_t CLK, uint8_t FUD, uint8_t RST);
void SetFreq(double Frequency);
void SetPhase(double phase); //Degrees
void SetTunningWord(char Frequency[4], char phase);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* AD9850_H */

