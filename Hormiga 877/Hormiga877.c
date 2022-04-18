#include "Hormiga877.h"

int main(void)
{
    Initialization();
    setup();
    for(;;)
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
    PORTB = 0x00;
    TRISB &= 0x00;
    PORTB = 0x00;
    //PORTC Configuration
    PORTC = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;
//    asm("CLRF PORTC");
//    asm("MOVLW 0x00");
//    asm("MOVWF TRISC");
//    asm("CLRF PORTC");
    PWMConfiguration();
    //PORTD Configuration
    asm("CLRF PORTD");
    asm("MOVLW 0x00");
    asm("MOVF TRISD");
    asm("CLRF PORTD");
    PORTE = 0x00;
    TRISE = 0x07;
}

void PWMConfiguration(void)
{
    PR2 = 0xFF;
    T2CON = 0x05; //Tmier 2 prescaler equals 
    CCPR2L = 0x00;
    CCPR1L = 0x00;
    CCP1CON = 0x0C;//0x4F; //0100 1111 //New Value 0000 1100
    CCP2CON = 0x0C;//0x4F;
}

void PWMStop(void)
{
    CCP2CON = 0x00;
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
            TRISCbits.TRISC5 = mode;
            break;
        case 3:
            TRISCbits.TRISC4 = mode;
            break;
        case 4:
            TRISCbits.TRISC3 = mode;
            break;
        case 5:
            TRISCbits.TRISC2 = mode;
            //CCP1CON = 0x00;      
            break;
        case 6:
            TRISCbits.TRISC1 = mode;
            //CCP2CON = 0x00;
            break;
        case 7:
            TRISCbits.TRISC0 = mode;
            break;
        case 8:
            TRISBbits.TRISB0 = mode;
            break;
        case 9:
            TRISBbits.TRISB1 = mode;
            break;
        case 10:
            TRISBbits.TRISB2 = mode;
            break;
        case 11:
            TRISBbits.TRISB3 = mode;
            break;
        case 12:
            TRISBbits.TRISB4 = mode;
            break;
        case 13:
            TRISBbits.TRISB5 = mode;
            break;
        case 14:
            TRISBbits.TRISB6 = mode;
            break;
        case 15:
            TRISBbits.TRISB7 = mode;
            break;
        case 16:
            TRISDbits.TRISD0 = mode;
            break;
        case 17:
            TRISDbits.TRISD1 = mode;
            break;
        case 18:
            TRISDbits.TRISD2 = mode;
            break;
        case 19:
            TRISDbits.TRISD3 = mode;
            break;
        case 20:
			TRISDbits.TRISD4 = mode;
			/*
            ADCON1bits.PCFG3 = 0;
            ADCON1bits.PCFG2 = 1;
            ADCON1bits.PCFG1 = 0;
            ADCON1bits.PCFG0 = 0;
            TRISAbits.TRISA5 = mode;
            //Analog pin Too Vref+ = VDD Vref- = Vss
            //with this configuration AN2 becomes digitalpin.
            */
			break;
        case 21:
            TRISDbits.TRISD5 = mode;
            break;
        case 22:
            TRISDbits.TRISD6 = mode;
            break;
        case 23:
            TRISDbits.TRISD7 = mode;
            break;      
        case 24:
            TRISAbits.TRISA4 = mode;
            break;
			/*
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
			*/
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
            PORTCbits.RC5 = value;
            break;
        case 3:
            PORTCbits.RC4 = value;
            break;
        case 4:
            PORTCbits.RC3 = value;
            break;
        case 5:
            CCP1CON = 0x00; 
            PORTCbits.RC2 = value;
            break;
        case 6:
            CCP2CON = 0x00;
            PORTCbits.RC1 = value;
            break;
        case 7:
            PORTCbits.RC0 = value;
            break;
        case 8:
            PORTBbits.RB0 = value;
            break;
        case 9:
            PORTBbits.RB1 = value;
            break;
        case 10:
            PORTBbits.RB2 = value;
            break;
        case 11:
            PORTBbits.RB3 = value;
            break;
        case 12:
            PORTBbits.RB4 = value;
            break;
        case 13:
            PORTBbits.RB5 = value;
            break;
        case 14:
            PORTBbits.RB6 = value;
            break;
        case 15:
            PORTBbits.RB7 = value;
            break;
        case 16:
            PORTDbits.RD0 = value;
            break;
        case 17:
            PORTDbits.RD1 = value;
            break;
        case 18:
            PORTDbits.RD2 = value;
            break;
        case 19:
            PORTDbits.RD3 = value;
            break;
        case 20:
            PORTDbits.RD4 = value;
            break;
        case 21:
            PORTDbits.RD5 = value;
            break;
        case 22:
            PORTDbits.RD6 = value;
            break;
        case 23:
            PORTDbits.RD7 = value;
            break;
        case 24:
            PORTAbits.RA4 = value;
            break;
			/*
        case 25:
            PORTDbits.RD0 = value;
            break;
        case 26:
            PORTAbits.RA2 = value;
            break;
			*/
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
            return PORTCbits.RC5;
            break;
        case 3:
            return PORTCbits.RC4;
            break;
        case 4:
            return PORTCbits.RC3;
            break;
        case 5:
            return PORTCbits.RC2;
            break;
        case 6:
            return PORTCbits.RC1;
            break;
        case 7:
            return PORTCbits.RC0;
            break;
        case 8:
            return PORTBbits.RB0;
            break;
        case 9:
            return PORTBbits.RB1;
            break;
        case 10:
            return PORTBbits.RB2;
            break;
        case 11:
            return PORTBbits.RB3;
            break;
        case 12:
            return PORTBbits.RB4;
            break;
        case 13:
            return PORTBbits.RB5;
            break;
        case 14:
            return PORTBbits.RB6;
            break;
        case 15:
            return PORTBbits.RB7;
            break;
        case 16:
            return PORTDbits.RD0;
            break;
        case 17:
            return PORTDbits.RD1;
            break;
        case 18:
            return PORTDbits.RD2;
            break;
        case 19:
            return PORTDbits.RD3;
            break;
        case 20:
            return PORTDbits.RD4;
            break;
        case 21:
            return PORTDbits.RD5;
            break;
        case 22:
            return PORTDbits.RD6;
            break;
        case 23:
            return PORTDbits.RD7;
            break;
        case 24:
            return PORTAbits.RA4;
            break;
			/*
        case 25:
            return PORTDbits.RD0;
            break;
        case 26:
            return PORTAbits.RA2;
            break;
			*/
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
uint8_t analogWrite(char pin, unsigned int value)
{
    switch(pin)
    {
        case 6://CCP2
            CCPR2L = value >> 2;
            CCP2X = value & 2;
            CCP2Y = value & 1;  
            break;
        case 5://CCP1
            CCPR1L = value >> 2;
            CCP1X = value & 2;
            CCP1Y = value & 1;
            break;
    }
    return 0;
}

char PBRead(char pin)
{
    switch(pin)
    {
        case 0:
            if(PORTEbits.RE0)
            {
                delay(100);
                return (PORTEbits.RE0) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
        case 1:
            if(PORTEbits.RE1) 
            {
                delay(100);
                return (PORTEbits.RE1) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
        case 2:
            if(PORTEbits.RE2) 
            {
                delay(120);
                return (PORTEbits.RE2) ? 1 : 0;
            }
            else
            {
                return 0;
            }
            break;
    }
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

void delay(const int milis)
{
    for(int j=0;j<milis;j++)
    {
        //Retardo de 1ms
        for(int i=0;i<235;i++)
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