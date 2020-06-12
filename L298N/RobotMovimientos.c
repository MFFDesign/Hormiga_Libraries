#include "system.h"
uint8_t in1 = 0;
uint8_t in2 = 0;
uint8_t in3 = 0;
uint8_t in4 = 0;
uint8_t va = 0;
uint8_t vb = 0;

int L298NInit(uint8_t ina,uint8_t inb, uint8_t inc,uint8_t ind, int VelA, int VelB)
{
    pinMode(ina,OUTPUT);
    pinMode(inb,OUTPUT);
    pinMode(inc,OUTPUT);
    pinMode(ind,OUTPUT);
    pinMode(VelA,OUTPUT);
    pinMode(VelB,OUTPUT);
    in1 = ina;
    in2 = inb;
    in3 = inc;
    in4 = ind;
    va = VelA;
    vb = VelB;
    return 0;
}
void Adelante(uint16_t Vel)
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
	analogWrite(va,Vel);
	analogWrite(vb,Vel);
	
}

void Atras(uint16_t Vel)
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
	analogWrite(va,Vel);
	analogWrite(vb,Vel);
}

void Izquierda(uint16_t Vel)
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
	analogWrite(va,Vel);
	analogWrite(vb,Vel);	
}

void Derecha(uint16_t Vel)
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);  
	analogWrite(va,Vel);
	analogWrite(vb,Vel);
}

void Detener(void)
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW); 
	analogWrite(va,0);
	analogWrite(vb,0);
}
