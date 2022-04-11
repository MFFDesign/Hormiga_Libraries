/* 
 * File:   NumberIO.h
 * Author: ToncheLAP
 *
 * Created on April 6, 2022, 2:13 PM
 */

#ifndef NUMBERIO_H
#define	NUMBERIO_H

void PrintNumber(float number, char *DataVector);
void ShowNumber(float number, float resolution, char *DataVector);
unsigned int ParteEntera(float number );
double MakeDoubleNumber(char row, char col);
unsigned int MakeIntegerNumber(char row, char col);
char MakeByteNumber(char row, char col);
char CaseSelector(char *Vector, char SizeValues, char row, char col);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NUMBERIO_H */

