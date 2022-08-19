/*
#include "system.h"
#include "RobotAM.h"
//Motor Izquierdo
uint8_t TerminalAMotorA = 3;//Naranja
uint8_t TerminalBMotorA = 2;//Amarillo
//Motor Derecho
uint8_t TerminalAMotorB = 4;//Rojo
uint8_t TerminalBMotorB = 5;//Cafe
//Terminales de velocidad
uint8_t TerminalVelocidadA = 22; //Izquiedro
uint8_t TerminalVelocidadB = 23; //Derecho


char Data = '0';

void setup()
{
    SerialBegin(9600);
    pinMode(TerminalAMotorA,OUTPUT);
    pinMode(TerminalBMotorA,OUTPUT);
    pinMode(TerminalAMotorB,OUTPUT);
    pinMode(TerminalBMotorB,OUTPUT);
    pinMode(TerminalVelocidadA,OUTPUT);
    pinMode(TerminalVelocidadB,OUTPUT);
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);
}

void loop()
{
    if(SerialAvailable() >= 0)
    {
       digitalWrite(13,LOW);
       Data = SerialRead();
       switch(Data)
       {
           case 'w':
               Adelante(1000);
               delay(100);
               break;
           case 's':
               Atras(1000);
               delay(100);
               break;
           case 'a':
               Izquierda(1000);
               delay(100);
               break;
           case 'd':
               Derecha(1000);
               delay(100);
               break;
           case 'q':
               Detener();
               break;
       }
    }
}


void AdelanteMotorIzquierdo(void)
{
    digitalWrite(TerminalAMotorA,HIGH);
    digitalWrite(TerminalBMotorA,LOW);
}

void AtrasMotorIzquierdo(void)
{
    digitalWrite(TerminalAMotorA,LOW);
    digitalWrite(TerminalBMotorA,HIGH);
}

void AdelanteMotorDerecho(void)
{
    digitalWrite(TerminalAMotorB,HIGH);
    digitalWrite(TerminalBMotorB,LOW);
}

void AtrasMotorDerecho(void)
{
    digitalWrite(TerminalAMotorB,LOW);
    digitalWrite(TerminalBMotorB,HIGH);
}

void Adelante(uint16_t Velocidad)
{
    AdelanteMotorIzquierdo();
    AdelanteMotorDerecho();
    analogWrite(TerminalVelocidadA,Velocidad);
    analogWrite(TerminalVelocidadB,Velocidad);
}

void Atras(uint16_t Velocidad)
{
    AtrasMotorIzquierdo();
    AtrasMotorDerecho();
    analogWrite(TerminalVelocidadA,Velocidad);
    analogWrite(TerminalVelocidadB,Velocidad);
}

void Izquierda(uint16_t Velocidad)
{
    AtrasMotorIzquierdo();
    AdelanteMotorDerecho();
    analogWrite(TerminalVelocidadA,Velocidad);
    analogWrite(TerminalVelocidadB,Velocidad);
}

void Derecha(uint16_t Velocidad)
{
    AdelanteMotorIzquierdo();
    AtrasMotorDerecho();
    analogWrite(TerminalVelocidadA,Velocidad);
    analogWrite(TerminalVelocidadB,Velocidad);
}

void Detener(void)
{
    digitalWrite(TerminalAMotorB,LOW);
    digitalWrite(TerminalBMotorB,LOW);
    digitalWrite(TerminalAMotorA,LOW);
    digitalWrite(TerminalBMotorA,LOW);
}
 * 
 * */