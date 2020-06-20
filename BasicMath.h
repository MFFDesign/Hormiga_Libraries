/* 
 * File:   BasicMath.h
 * Author: Mr. Carlos Tonche
 *
 * Created on June 17, 2020, 9:08 PM
 */

#ifndef BASICMATH_H
#define	BASICMATH_H

#define RESIDUO 0x01
#define MODULO  0x02
unsigned int Suma(unsigned int a, unsigned int b);
unsigned int Resta(unsigned int a, unsigned int b);
unsigned int Multiplicacion(unsigned int a, unsigned int b);
unsigned int Modulo(unsigned int Num, unsigned int Den);
double Derivar(double now, double last, double dt);
unsigned int Residuo(unsigned int Num, unsigned int Den);
unsigned int Division(unsigned int Num, unsigned int Den, unsigned int Mode);
unsigned int Potencia(unsigned int Base, unsigned int Exponente);
double Integrar(double now,double dt);
double IntegralTrapezoidal(void);
double IntegralRouth(void);
double IntegralSimpsonUO(void);
double IntegralSimpsonTO(void);
unsigned int RaizCuadrada(unsigned int Base);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* BASICMATH_H */

