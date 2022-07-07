/* 
 * File:   PASControl_RevA.h
 * Author: Carlos Tonche
 *
 * Created on June 28, 2022, 3:22 PM
 */

#ifndef PASCONTROL_REVA_H
#define	PASCONTROL_REVA_H

#ifdef	__cplusplus
extern "C" {
#endif

    void ChangeToSSR(void);
void ChangeToPAS(void);
void PASControlBegin(char digTerminal);
char SetPhase(char Phase);



#ifdef	__cplusplus
}
#endif

#endif	/* PASCONTROL_REVA_H */

