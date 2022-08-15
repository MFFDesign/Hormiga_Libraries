/* 
 * File:   system.h
 * Author: c4810
 *
 * Created on July 8, 2019, 6:40 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include <xc.h>
#include <stdint.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0
#define _XTAL_FREQ 20000000
#define TMR2PRESCALE 4

// System Configuration
void Initialization(void);
void CCP1Configuration(void);
void PWM2Stop(void);
void PWM1Stop(void);
void CCP2Configuration(void);
char PBRead(char pin);
void pinMode(char pin, char mode);
void digitalWrite(char pin, char value);
char digitalRead(char pin);
unsigned int analogRead(char channel);
uint8_t analogWrite(uint8_t pin, uint16_t value);
void setup(void);
void loop(void);

//SerialModule
char SerialBegin(const long int baudRate);
char TxRegisterFull(void);
char SerialErrors(void);
void SerialWrite(char dataWrite);
char SerialWriteText(char *dataText);
void SerialPrint(char *dataText);
void SerialPrintLn(char *dataText);
char SerialAvailable(void);
char SerialRead(void);
void SerialReadText(char *Output, unsigned int lenght);
//PWM
//Math 
double rescale(double x, double in_min, double in_max, double out_min, double out_max);
char residuo(unsigned int numerator, unsigned int denominator);
char cocienteEntero(unsigned int numerator, unsigned int denominator);

//I2C Module
void I2CMasterStart(void);
void I2CMasterRepeatedStart(void);
void I2CMasterStop(void);
void I2CMasterWrite(unsigned d);
unsigned short I2CMasterRead(unsigned short a);
//time
void delay(const int milis);
void delayMicroseconds(const int us);
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

