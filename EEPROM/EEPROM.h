/* 
 * File:   EEPROM.h
 * Author: ToncheLAP
 *
 * Created on February 23, 2022, 2:43 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

void EEPROMSave(char addr, char data);
char  EEPROMRead(char addr);
void SaveData(unsigned int Data, char InitAddress);
unsigned int ReadData(char Address);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

