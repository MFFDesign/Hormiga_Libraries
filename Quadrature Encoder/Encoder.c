#include "Encoder.h"
#include "system.h"

#define ENC_ERROR 0
static unsigned int pinA, pinB;
signed char EncoderMatrix[4][4] = {
    { 0, 1, -1, ENC_ERROR },
    { -1, 0, ENC_ERROR, 1 },
    { 1, ENC_ERROR, 0, -1 },
    { ENC_ERROR, -1, 1, 0 }
};
void EncoderBegin(unsigned int A, unsigned int B)
{
    pinA = A;
    pinB = B;
    pinMode(B,INPUT);
    pinMode(A,INPUT);
}

signed char EncoderRead(void)
{
    static signed char previo,actual,incremento;
    actual = ((digitalRead(pinA) & 0x01) << 1) & (digitalRead(pinB) & 0x02);
    incremento = EncoderMatrix[previo][actual];
    previo = actual;
    return incremento;
}
