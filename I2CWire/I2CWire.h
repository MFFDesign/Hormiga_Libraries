/* 
 * File:   I2CWire.h
 * Author: ToncheLAP
 *
 * Created on April 1, 2022, 2:33 PM
 */

#ifndef I2CWIRE_H
#define	I2CWIRE_H

void I2CStartTransaction(void);
void I2CIDLECheck(void);
char  I2CWriteByte(char databyte);
char I2CReadByte(void);
void I2CRepeatTransaction(void);
void I2CStopTransaction(void);
void I2CBegin(const unsigned long Hertz) ;
void I2CACK(void);
void I2CNACK(void);
char ScanDevices(char *ResultList, char TotalDevices);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* I2CWIRE_H */

