/* 
 * File:   Encoder.h
 * Author: c4810
 *
 * Created on May 31, 2019, 5:29 PM
 */

#ifndef ENCODER_H
#define	ENCODER_H
#include <xc.h>
#include <stdint.h>

signed char EncoderRead(void);
void EncoderBegin(unsigned int A, unsigned int B);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ENCODER_H */

