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

//////////using PORTB
uint8_t KeypadBegin8TO15(const uint8_t ROWSNibble, const uint8_t COLSNibble, unsigned char *Keyclas);
char Keypad8TO15Read(void);

///// Mixed GPIO (Digital Generalization))
void KeypadBegin(unsigned char *rows, unsigned char *cols, unsigned char *data);
char KeypadRead(void);

///// analog signal Method
char analogKeypadRead(void);
void analogKeypadBegin(uint8_t channel,unsigned int *KayValues, unsigned char *data);
void analogKeypadCalibration(unsigned int channel);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD4X4_H */

