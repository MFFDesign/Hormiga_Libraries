/* 
 * File:   Keypad4x4.h
 * Author: c4810
 *
 * Created on May 27, 2019, 8:59 AM
 */

#ifndef KEYPAD4X4_H
#define	KEYPAD4X4_H

#include <xc.h>
#include <stdint.h>
#define NO_KEY 'n'
void KeypadBegin(const int rows[4], const int cols[4], char data[4][4]);
char KeypadRead(void);
char analogKeypadRead(void);
void analogKeypadBegin(unsigned int channel,unsigned int KayValues[4][4], char data[4][4]);
void analogKeypadCalibration(unsigned int channel);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD4X4_H */

