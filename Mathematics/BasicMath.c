#include "system.h"
#include "BasicMath.h"

unsigned int Suma(unsigned int a, unsigned int b)
{
    unsigned int Resultado = 0;
    Resultado = a + b;
    return Resultado;
}

unsigned int Resta(unsigned int a, unsigned int b)
{
    unsigned int Resultado = 0;
    Resultado = a - b;
    return Resultado;
}

unsigned int Multiplicacion(unsigned int a, unsigned int b)
{
    unsigned int Resultado = 0;
    for(int i=1;i<=b;i++)
    {
        Resultado += a;
    }
    return Resultado;
}

unsigned int Modulo(unsigned int Num, unsigned int Den)
{
    unsigned int Residuo = Num;
    unsigned int Cnt = 0;
    while(Residuo >= Den)
    {
        Residuo = Residuo - Den;
        Cnt++;//1---> 2 ---> 3
    }
    return Cnt; //3
}


unsigned int Residuo(unsigned int Num, unsigned int Den)
{
    unsigned int Residuo = Num;
    while(Residuo >= Den)
    {
        Residuo = Residuo - Den;
    }
    return Residuo;
}

unsigned int Division(unsigned int Num, unsigned int Den, unsigned int Mode)
{
    unsigned int Residuo = Num;
    unsigned int Cnt = 0;
    switch(Mode)
    {
        case RESIDUO:
                while(Residuo >= Den)
                {
                    Residuo = Residuo - Den;
                }
                return Residuo;
            break;
        case MODULO:
                while(Residuo >= Den)
                {
                    Residuo = Residuo - Den;
                    Cnt++;
                }
                return Cnt;
            break;
    }
}

unsigned int RaizCuadrada(unsigned int Base)
{
    
}

double Derivar(double now, double last, double dt) //Predecir el futuro.//Nerrvioso
{
    double derivada = 0;
    derivada = (now - last) / dt;
    return derivada;
}


double Integrar(double now,double dt) 
{
    double Integral = 0;
    Integral = now * dt;
    return Integral;
}


double IntegralTrapezoidal(void)
{
    
}


double IntegralRouth(void)
{
    
}


double IntegralSimpsonUO(void)
{
    
}

double IntegralSimpsonTO(void)
{
    
}

unsigned int Potencia(unsigned int Base, unsigned int Exponente)
{
    unsigned int Resultado = 1;
    for(int i=0;i<Exponente-1;i++)
    {
        Resultado +=  Multiplicacion(Base,Base);
    }
    return Resultado;
}