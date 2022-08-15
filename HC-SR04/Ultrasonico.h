/* 
 * File:   Ultrasonico.h
 * Author: ToncheLAP
 *
 * Created on August 15, 2022, 11:11 AM
 */

#ifndef ULTRASONICO_H
#define	ULTRASONICO_H

#ifdef	__cplusplus
extern "C" {
#endif

    unsigned int USRead(char trigger, char echo);
    void USBegin(char trigger, char echo);



#ifdef	__cplusplus
}
#endif

#endif	/* ULTRASONICO_H */

