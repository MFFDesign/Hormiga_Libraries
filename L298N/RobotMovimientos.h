/* 
 * File:   RobotMovimientos.h
 * Author: c4810
 *
 * Created on November 15, 2019, 1:56 PM
 */

#ifndef ROBOTMOVIMIENTOS_H
#define	ROBOTMOVIMIENTOS_H
void Adelante(uint16_t Vel);
void Atras(uint16_t Vel);
void Izquierda(uint16_t Vel);
void Derecha(uint16_t Vel);
void Detener(void);
int L298NInit(uint8_t ina,uint8_t inb, uint8_t inc,uint8_t ind, int VelA, int VelB);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ROBOTMOVIMIENTOS_H */

