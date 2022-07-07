/* 
 * File:   SPI.h
 * Author: Carlos Tonche
 *
 * Created on June 28, 2022, 3:31 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

char spiRead(void);
void spiMasterbegin(void);
char spiDataAvailable(void);
void spiWrite(char byte);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

