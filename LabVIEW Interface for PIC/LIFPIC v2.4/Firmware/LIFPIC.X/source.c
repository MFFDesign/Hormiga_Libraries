#include "system.h"

#define MASTER 0x01
#define SLAVE 0x02


int main(void)
{
    Initialization();
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}

void Initialization(void)
{
            //ADCCOnfiguration
    ADCON0 = 0x81; //FOSC/8 Channel 0, ADC ON
    ADCON1 = 0xC2; //RA3,RA2,RA1,RA0 Analogic || Vref+ = VDD, -Vref = Vss
    //PORT A Configuration
    asm("CLRF PORTA"); //All Terminal as Inputs. only RA4 as digital Inpuy
    asm("MOVLW 0x3F");
    asm("MOVWF TRISA");
    //TRISB = 0xFF; //all pins as Ouptus by default and low State
    asm("CLRF PORTB");
    asm("MOVLW 0x00");
    asm("MOVWF TRISB");
    //PORTC Configuration
    asm("CLRF PORTC");
    asm("MOVLW 0x00");
    asm("MOVWF TRISC");
    CCP1Configuration();
    CCP2Configuration();
    //PORTD Configuration
    asm("CLRF PORTD");
    asm("MOVLW 0x00");
    asm("MOVF TRISD");
    PORTE = 0x00;
    TRISE = 0x07;
}
void CCP1Configuration(void)
{
    PR2 = 0xFF;
    T2CON = 0x05; //Tmier 2 prescaler equals 
    CCP1CON = 0x4F;
}

void PWM2Stop(void)
{
    CCP2CON = 0x00;
}
void CCP2Configuration(void)
{
    CCP2CON = 0x4F;
}
void PWM1Stop(void)
{
    CCP1CON = 0x00;
}
void pinMode(char pin, char mode)
{
    switch(pin)
    {
        case 0:
            TRISCbits.TRISC7 = mode;
            break;
        case 1:
            TRISCbits.TRISC6 = mode;
            break;
        case 2:
            TRISDbits.TRISD2 = mode;
            break;
        case 3:
            TRISDbits.TRISD3 = mode;
            break;
        case 4:
            TRISCbits.TRISC4 = mode;
            break;
        case 5:
            TRISCbits.TRISC5 = mode;
            break;
        case 6:
            TRISDbits.TRISD4 = mode;
            break;
        case 7:
            TRISDbits.TRISD5 = mode;
            break;
        case 8:
            TRISDbits.TRISD6 = mode;
            break;
        case 9:
            TRISDbits.TRISD7 = mode;
            break;
        case 10:
            TRISBbits.TRISB0 = mode;
            break;
        case 11:
            TRISBbits.TRISB1 = mode;
            break;
        case 12:
            TRISBbits.TRISB2 = mode;
            break;
        case 13:
            TRISBbits.TRISB4 = mode;
            break;
        case 14:
            TRISBbits.TRISB3 = mode;
            break;
        case 15:
            TRISBbits.TRISB5 = mode;
            break;
        case 16:
            TRISBbits.TRISB6 = mode;
            break;
        case 17:
            TRISCbits.TRISC3 = mode;
            break;
        case 18:
            TRISBbits.TRISB7 = mode;
            break;
        case 19:
            TRISAbits.TRISA4 = mode;
            break;
        case 20:
            ADCON1bits.PCFG3 = 0;
            ADCON1bits.PCFG2 = 1;
            ADCON1bits.PCFG1 = 0;
            ADCON1bits.PCFG0 = 0;
            TRISAbits.TRISA5 = mode;
            //Analog pin Too Vref+ = VDD Vref- = Vss
            //with this configuration AN2 becomes digitalpin.
            break;
        case 21:
            TRISCbits.TRISC0 = mode;
            break;
        case 22:
            TRISCbits.TRISC1 = mode;
            break;
        case 23:
            TRISCbits.TRISC2 = mode;
            break;      
        case 24:
            TRISDbits.TRISD1 = mode;
            break;
        case 25:
            TRISDbits.TRISD0 = mode;
            break;
        case 26:
            ADCON1bits.PCFG3 = 0;
            ADCON1bits.PCFG2 = 1;
            ADCON1bits.PCFG1 = 0;
            ADCON1bits.PCFG0 = 0;
            TRISAbits.TRISA2 = mode;
            //Analog pin Too Vref+ = VDD Vref- = Vss
            //with this configuration AN2 becomes digitalpin.
            break;
    }
}
void digitalWrite(char pin, char value)
{
    switch(pin)
    {
        case 0:
            PORTCbits.RC7 = value;
            break;
        case 1:
            PORTCbits.RC6 = value;
            break;
        case 2:
            PORTDbits.RD2 = value;
            break;
        case 3:
            PORTDbits.RD3 = value;
            break;
        case 4:
            PORTCbits.RC4 = value;
            break;
        case 5:
            PORTCbits.RC5 = value;
            break;
        case 6:
            PORTDbits.RD4 = value;
            break;
        case 7:
            PORTDbits.RD5 = value;
            break;
        case 8:
            PORTDbits.RD6 = value;
            break;
        case 9:
            PORTDbits.RD7 = value;
            break;
        case 10:
            PORTBbits.RB0 = value;
            break;
        case 11:
            PORTBbits.RB1 = value;
            break;
        case 12:
            PORTBbits.RB2 = value;
            break;
        case 13:
            PORTBbits.RB4 = value;
            break;
        case 14:
            PORTBbits.RB3 = value;
            break;
        case 15:
            PORTBbits.RB5 = value;
            break;
        case 16:
            PORTBbits.RB6 = value;
            break;
        case 17:
            PORTCbits.RC3 = value;
            break;
        case 18:
            PORTBbits.RB7 = value;
            break;
        case 19:
            PORTAbits.RA4 = value;
            break;
        case 20:
            PORTAbits.RA5 = value;
            break;
        case 21:
            PORTCbits.RC0 = value;
            break;
        case 22:
            PORTCbits.RC1 = value;
            break;
        case 23:
            PORTCbits.RC2 = value;
            break;
        case 24:
            PORTDbits.RD1 = value;
            break;
        case 25:
            PORTDbits.RD0 = value;
            break;
        case 26:
            PORTAbits.RA2 = value;
            break;
    }
}
char digitalRead(char pin)
{
    switch(pin)
    {
        case 0:
             return PORTCbits.RC7;
            break;
        case 1:
            return PORTCbits.RC6;
            break;
        case 2:
            return PORTDbits.RD2;
            break;
        case 3:
            return PORTDbits.RD3;
            break;
        case 4:
            return PORTCbits.RC4;
            break;
        case 5:
            return PORTCbits.RC5;
            break;
        case 6:
            return PORTDbits.RD4;
            break;
        case 7:
            return PORTDbits.RD5;
            break;
        case 8:
            return PORTDbits.RD6;
            break;
        case 9:
            return PORTDbits.RD7;
            break;
        case 10:
            return PORTBbits.RB0;
            break;
        case 11:
            return PORTBbits.RB1;
            break;
        case 12:
            return PORTBbits.RB2;
            break;
        case 13:
            return PORTBbits.RB4;
            break;
        case 14:
            return PORTBbits.RB3;
            break;
        case 15:
            return PORTBbits.RB5;
            break;
        case 16:
            return PORTBbits.RB6;
            break;
        case 17:
            return PORTCbits.RC3;
            break;
        case 18:
            return PORTBbits.RB7;
            break;
        case 19:
            return PORTAbits.RA4;
            break;
        case 20:
            return PORTAbits.RA5;
            break;
        case 21:
            return PORTCbits.RC0;
            break;
        case 22:
            return PORTCbits.RC1;
            break;
        case 23:
            return PORTCbits.RC2;
            break;
        case 24:
            return PORTDbits.RD1;
            break;
        case 25:
            return PORTDbits.RD0;
            break;
        case 26:
            return PORTAbits.RA2;
            break;
    }
}
unsigned int analogRead(char channel)
{
    switch(channel)
    {
        case 0:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 1:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 1;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 2:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 3:
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS0 = 1;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
        case 4:
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS0 = 0;
            ADCON0bits.GO_DONE = 1;
            while(ADCON0bits.GO_DONE != 0)
            {
                
            }
            return (ADRESH << 8)+ ADRESL;
            break;
    }
}
uint8_t analogWrite(uint8_t pin, uint16_t value)
{
    switch(pin)
    {
        case 0x16://CCP2   Terminal 22
            //TRISCbits.TRISC1 = 0;
            CCPR2L = value >> 2;
            CCP2X = value & 2;
            CCP2Y = value & 1;  
            break;
        case 0x17://CCP1  Terminal 23
            //TRISCbits.TRISC2 = 0;
            CCPR1L = value >> 2;
            CCP1X = value & 2;
            CCP1Y = value & 1;
            break;
    }
    return pin;
}
char PBRead(char pin)
{
    switch(pin)
    {
        case 0:
            return PORTEbits.RE0;
            break;
        case 1:
            return PORTEbits.RE1;
            break;
        case 2:
            return PORTEbits.RE2;
            break;
    }
}
double rescale(double x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

char SerialBegin(const long int BaudRate)
{
	/*
		BaudRate = _XTAL_FREQ / (64 * (SPBRG + 1))
	*/
	unsigned  int x;
	BRGH = 0;
	x = (_XTAL_FREQ / (64 * BaudRate)) - 1;
	if(x > 255)
	{
		BRGH = 1;
		x = (_XTAL_FREQ / (16 * BaudRate)) - 1;
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 0;
	}
	else
	{
		SPBRG = x;
		SYNC = 0;
		SPEN = 1;                                     //Enables Serial Port
		TRISC7 = 1;                                   //As Prescribed in Datasheet
		TRISC6 = 1;                                   //As Prescribed in Datasheet
		CREN = 1;                                     //Enables Continuous Reception
		TXEN = 1;
        TXREG = 0x00;
        RCREG = 0x00;
		return 1;
	}
}

char TxRegisterFull(void)
{
    return TRMT;
}
char SerialErrors(void)
{
    if((FERR == 1) && (FERR || OERR)) //Framing Error
    {
        return 1;
    }
    else if((OERR == 1) && (FERR || OERR)) //OverRun Error
    {
        return 2;
    }
    else if(OERR && FERR) 
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void SerialWrite(char dataWrite)
{
    while(!TXIF);
    TXREG = dataWrite;
}

char SerialWriteText(char *dataText)
{
    unsigned int i;
    for(i=0;dataText[i]!='\0';i++)
    {
       SerialWrite(dataText[i]); 
    }
}
void SerialPrint(char *dataText)
{
    for(unsigned int i=0;dataText[i]!='\0';i++)
    {
        SerialWrite(dataText[i]);
    }
}
void SerialPrintLn(char *dataText)
{
    unsigned int i;
        for(i=0;dataText[i]!='\0';i++)
        {
            SerialWrite(dataText[i]);
        }
        SerialWrite(0x0A);
}
char SerialAvailable(void)
{
    return RCIF || (TXIF && TRMT);
}

char SerialRead(void)
{
    while(!RCIF);
    return RCREG;
}

void SerialReadText(char *Output, unsigned int lenght)
{
    unsigned int i;
    for(i=0;i<lenght;i++)
    {
        Output[i] = SerialRead();
    }
}

void I2CBegin(char Operation, const unsigned long param)
{
    switch(Operation)
    {
        case MASTER:
            SSPCON = 0b00101000;            //SSP Module as Master
            SSPCON2 = 0;
            SSPADD = (_XTAL_FREQ/(4*param))-1; //Setting Clock Speed
            SSPSTAT = 0;
            TRISC3 = 1;                   //Setting as input as given in datasheet
            TRISC4 = 1;    
            break;
        case SLAVE:
            SSPSTAT = 0x80;    
            SSPADD = param; //Setting address
            SSPCON = 0x36;    //As a slave device
            SSPCON2 = 0x01;
            TRISC3 = 1;       //Setting as input as given in datasheet
            TRISC4 = 1;       //Setting as input as given in datasheet
            GIE = 1;          //Global interrupt enable
            PEIE = 1;         //Peripheral interrupt enable
            SSPIF = 0;        //Clear interrupt flag
            SSPIE = 1;        //Synchronous serial port interrupt enable
            break;
    }
}
void I2CMasterWaiting()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F)); //Transmit is in progress
}

void I2CMasterStart()
{
  I2CMasterWaiting();    
  SEN = 1;             //Initiate start condition
}
void I2CMasterRepeatedStart()
{
  I2CMasterWaiting();
  RSEN = 1;           //Initiate repeated start condition
}
void I2CMasterStop()
{
  I2CMasterWaiting();
  PEN = 1;           //Initiate stop condition
}
void I2CMasterWrite(unsigned d)
{
  I2CMasterWaiting();
  SSPBUF = d;         //Write data to SSPBUF
}

unsigned short I2CMasterRead(unsigned short a)
{
  unsigned short temp;
  I2CMasterWaiting();
  RCEN = 1;
  I2CMasterWaiting();
  temp = SSPBUF;      //Read data from SSPBUF
  I2CMasterWaiting();
  ACKDT = (a)?0:1;    //Acknowledge bit
  ACKEN = 1;          //Acknowledge sequence
  return temp;
}

void delay(const int milis)
{
    for(int j=0;j<milis;j++)
    {
        //Retardo de 1ms
        for(int i=0;i<400;i++)
        {
            asm("NOP");
        }
    }
}

void delayMicroseconds(const int us)
{
    for(char i=0;i<us;i++)
    {
        asm("NOP");
    }
}