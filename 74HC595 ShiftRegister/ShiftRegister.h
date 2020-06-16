/* 
 * File:   ShiftRegister.h
 * Author: MikyDesktop
 *
 * Created on April 10, 2020, 3:26 AM
 */

#ifndef SHIFTREGISTER_H
#define	SHIFTREGISTER_H
#include <xc.h>
#define ENABLE 0x02
#define DISABLE 0x04
#define FWD 	0x02
#define BWD 	0x01
#define STOP 	0x00
#define M1		0x03
#define M2		0x04
#define M3		0x05
#define M4		0x06
#define MSBF    0x07
#define LSBF    0x08
void MoveMotor(char motor,char Movement);
void StopAllMotor(void);
void ShiftRegisterBegin(char dataInA,char clkA, char latchA, char clrPortA, char OEA);
void WriteRegister(char data,char bits,char byteTransfer);
char RegisterStatus(char status);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SHIFTREGISTER_H */

