/* 
 * File:   NumberTreatment.h
 * Author: ToncheLAP
 *
 * Created on February 26, 2022, 6:50 PM
 */

#ifndef NUMBERTREATMENT_H
#define	NUMBERTREATMENT_H

void PrintToFile(float number, char *DataVector, char PteInt,char PteFrac);
void ShowNumber(float number, float resolution, char *DataVector);
void PrintNumber(float number, char *DataVector);
unsigned int ParteFraccional(float number, float resolution);
unsigned int ParteEntera(float number );
unsigned int MakeIntegerNumber(char row, char col);
double MakeDoubleNumber(char row, char col);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NUMBERTREATMENT_H */

