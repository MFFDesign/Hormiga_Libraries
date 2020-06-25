/* 
 * File:   Matematica.h
 * Author: user
 *
 * Created on June 25, 2020, 12:35 PM
 */

#ifndef MATEMATICA_H
#define	MATEMATICA_H
unsigned int Suma(unsigned int a, unsigned int b);
unsigned int Resta(unsigned int a, unsigned int b);
unsigned int Multiplicacion(unsigned int a, unsigned int b);
unsigned int Modulo(unsigned int Num, unsigned int Den);
unsigned int Residuo(unsigned int Num, unsigned int Den);
unsigned int RaizCuadrada(unsigned int numero);
double derivar(double now, double dt);
double Integrar(double now,double dt) ;
double IntegralTrapezoidal(double now, double dt);
double IntegralSimpson(double now, double dt);
unsigned int Potencia(unsigned int Base, unsigned int Exponente);
double map(double data, double X2, double X1, double Y2, double Y1);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MATEMATICA_H */

