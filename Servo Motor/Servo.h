/* 
 * File:   Servo.h
 * Author: c4810
 *
 * Created on November 25, 2019, 11:49 AM
 */

#ifndef SERVO_H
#define	SERVO_H
void ServoAttach(uint8_t PinValue);
void ServoWrite(unsigned int DegreesValue);
void ServoWriteCero(uint16_t deegres);
void ServoWriteNoventa(uint16_t deegres);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

