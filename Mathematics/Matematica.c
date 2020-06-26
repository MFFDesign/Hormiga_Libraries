#include "system.h"
#include "Matematica.h"

unsigned int Suma(unsigned int a, unsigned int b)
{
    return a + b;
}

unsigned int Resta(unsigned int a, unsigned int b)
{
    return a - b;
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
        Cnt++;
    }
    return Cnt;
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
unsigned int RaizCuadrada(unsigned int numero)
{
    unsigned int residuo = 0;
    unsigned int cont = 0;
    for(int i=0;i<=numero;i++)
    {
        residuo = i * i;
        
        if(residuo > numero)
        {
            cont = i - 1;
            break;
        }
        else if(residuo = numero)
        {
            cont = i;
            break;
        }
    }
    return cont;
}

double derivar(double now, double dt)
{
    static double Last = 0;
    double derivada = 0;
    derivada = (now - Last)/dt;
    Last = now;
    return derivada;
}


double Integrar(double now,double dt) 
{
    static double Integral = 0;
    if(dt == -1)
    {
        Integral = 0;
        return 0;
    }
    else
    {
        Integral += now * dt;
    }
    return Integral;
}

double IntegralTrapezoidal(double now, double dt)
{
    static double Integral = 0;
    static double last = 0;
    if(dt == -1)
    {
        Integral = 0;
        now = 0;
        last = 0;
        return 0;
    }
    else
    {
        Integral += (dt * (now + last)) / 2;
        last = now;
        return Integral;
    }
}

double IntegralSimpson(double now, double dt)
{
    static double last[2] = {0,0};
    static double Integral = 0;
    if(dt == -1)
    {
        Integral = 0;
        last[0] = 0;
        last[1] = 0;
        return 0;
    }
    else
    {
        Integral += (dt * (now + (4 * last[0]) + last[1])) / 3;
        last[1] = last[0];
        last[0] = now;
        return Integral;
    }
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

double map(double data, double X2, double X1, double Y2, double Y1)
{
    double m = (Y2 - Y1) / (X2 - X1);
    return (m * data) - (m * X1) + Y1;
}

