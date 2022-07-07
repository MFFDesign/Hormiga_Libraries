/* 
 * File:   MAX6675.h
 * Author: Carlos Tonche
 *
 * Created on June 29, 2022, 11:30 AM
 */

#ifndef MAX6675_H
#define	MAX6675_H

#ifdef	__cplusplus
extern "C" {
#endif

unsigned int ReadTemperature(char Sensor);
void MAX6675Begin(char pin);



#ifdef	__cplusplus
}
#endif

#endif	/* MAX6675_H */

