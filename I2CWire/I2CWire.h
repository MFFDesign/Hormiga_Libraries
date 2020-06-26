/* 
 * File:   I2CWire.h
 * Author: user
 *
 * Created on June 26, 2020, 4:45 PM
 */

#ifndef I2CWIRE_H
#define	I2CWIRE_H

#define SLAVE 0x00
#define MASTER 0x01

void I2CBegin(char Operation, const unsigned long param);
void I2CMasterWaiting(void);
void I2CMasterStart(void);
void I2CMasterRepeatedStart(void);
void I2CMasterStop(void);
void I2CMasterWrite(unsigned d);
unsigned short I2CMasterRead(unsigned short a);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* I2CWIRE_H */

