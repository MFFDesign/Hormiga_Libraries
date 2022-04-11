/* 
 * File:   I2CEEPROM.h
 * Author: ToncheLAP
 *
 * Created on April 4, 2022, 2:35 PM
 */

#ifndef I2CEEPROM_H
#define	I2CEEPROM_H

void EEPROMWrite(char MemSlct, unsigned int address, char data);
void EEPROMWritePage(char MemSlct, unsigned int address, char *data, unsigned int lenght );

char EEPROMRead(char MemSlct, unsigned int address);
void EEPROMReadPage(char MemSlct, unsigned int address,  char *data, unsigned int lenght);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* I2CEEPROM_H */

