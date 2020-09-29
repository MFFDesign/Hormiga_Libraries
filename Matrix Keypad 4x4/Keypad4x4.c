#include "Keypad4x4.h"
#include "Hormiga877.h"


unsigned char *KeypadAddress = 0;
unsigned int *TeclasVolValues = 0;
uint8_t RenROWS = 0;
uint8_t COLumns = 0;

unsigned int MaxAndMinValues[16][2] = {
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0}
};
unsigned int Vmax = 0;
uint8_t *RowPins;
uint8_t *ColPins;
uint8_t delaying = 20;
uint8_t ADeCeChannel = 0;


/*
 * Functions "KeypadBegin8TO15()" and Keypad8TO15Read() Works with portB/
 */
uint8_t KeypadBegin8TO15(const uint8_t ROWSNibble, const uint8_t COLSNibble, unsigned char *Keyclas)
{
    if((ROWSNibble == NIBBLE8TO11) || (ROWSNibble == NIBBLE12TO15))
    {
        if((COLSNibble == NIBBLE8TO11) || (COLSNibble == NIBBLE12TO15))
        {
            nRBPU = 0;
            RenROWS = ROWSNibble;
            COLumns = COLSNibble;
            pinMode(ROWSNibble,0x0F);
            pinMode(COLSNibble,0x00);
            KeypadAddress = Keyclas;
            digitalWrite(COLSNibble,0x0F);
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 2;
    }
    
}

char Keypad8TO15Read(void)
{
    digitalWrite(COLumns,0x0E);
    if(digitalRead(RenROWS) == 0x0E)
    {
        return *KeypadAddress;
    }
    else if(digitalRead(RenROWS) == 0x0D)
    {
        return *(KeypadAddress + 1);
    }
    else if(digitalRead(RenROWS) == 0x0B)
    {
        return *(KeypadAddress + 2);
    }
    else if(digitalRead(RenROWS) == 0x07)
    {
        return *(KeypadAddress + 3);
    }
    else
    {
        digitalWrite(COLumns,0x0D);
        if(digitalRead(RenROWS) == 0x0E)
        {
            return *(KeypadAddress + 4);
        }
        else if(digitalRead(RenROWS) == 0x0D)
        {
            return *(KeypadAddress + 5);
        }
        else if(digitalRead(RenROWS) == 0x0B)
        {
            return *(KeypadAddress + 6);
        }
        else if(digitalRead(RenROWS) == 0x07)
        {
            return *(KeypadAddress + 7);
        }
        else
        {
            digitalWrite(COLumns,0x0B);
            if(digitalRead(RenROWS) == 0x0E)
            {
                return *(KeypadAddress + 8);
            }
            else if(digitalRead(RenROWS) == 0x0D)
            {
                return *(KeypadAddress + 9);
            }
            else if(digitalRead(RenROWS) == 0x0B)
            {
                return *(KeypadAddress + 10);
            }
            else if(digitalRead(RenROWS) == 0x07)
            {
                return *(KeypadAddress + 11);
            }
            else
            {
                digitalWrite(COLumns,0x07);
                if(digitalRead(RenROWS) == 0x0E)
                {
                    return *(KeypadAddress + 12);
                }
                else if(digitalRead(RenROWS) == 0x0D)
                {
                    return *(KeypadAddress + 13);
                }
                else if(digitalRead(RenROWS) == 0x0B)
                {
                    return *(KeypadAddress + 14);
                }
                else if(digitalRead(RenROWS) == 0x07)
                {
                    return *(KeypadAddress + 15);
                }
                else
                {
                    return NO_KEY;
                }
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////

//Pendiente de Verificar (Antes trabajaba, se Modifico y ni se probo)
void analogKeypadBegin(uint8_t channel,unsigned int *KayValues, unsigned char *data)
{
    TeclasVolValues = KayValues; //Get direction for Central Voltage values for Analog Keypad.
	unsigned int offset = 0;
    unsigned int Tol = 10;
    ADeCeChannel = channel;
    KeypadAddress = data;
    for(int i=0;i<16;i++)
    {
        if(*(TeclasVolValues + i) < Tol)
        {
            MaxAndMinValues[i][0] = *(TeclasVolValues + i) + Tol;
            MaxAndMinValues[i][1] = 0;
        }
        else if(*(TeclasVolValues + i) > 1013)
        {
            MaxAndMinValues[i][0] = 1013;
            MaxAndMinValues[i][1] = *(TeclasVolValues + i) - Tol;
        }
        else
        {
            MaxAndMinValues[i][0] = *(TeclasVolValues + i) + Tol;
            MaxAndMinValues[i][1] = *(TeclasVolValues + i) - Tol;
        }
        if(MaxAndMinValues[i][0] > Vmax)
        {
            Vmax = MaxAndMinValues[i][0];
        }
    }
}

//Pendiente de Verificar (Antes trabajaba, se Modifico y ni se probo)
char analogKeypadRead(void)
{
    unsigned int data = 0;
    for(char i=0;i<5;i++)
    {
        data += analogRead(ADeCeChannel);
        delay(10);
    }
    data /= 5;
    if((data <= MaxAndMinValues[0][1]) && (data >= MaxAndMinValues[0][0]))
    {
        return *(KeypadAddress);
    }
    else if((data <= MaxAndMinValues[1][1]) && (data >= MaxAndMinValues[1][0]))
    {
        return *(KeypadAddress + 1);
    }
    else if((data <= MaxAndMinValues[2][1]) && (data >= MaxAndMinValues[2][0]))
    {
        return *(KeypadAddress + 2);
    }
    else if((data <= MaxAndMinValues[3][1]) && (data >= MaxAndMinValues[3][0]))
    {
        return *(KeypadAddress + 3);
    }
    else if((data <= MaxAndMinValues[4][1]) && (data >= MaxAndMinValues[4][0]))
    {
        return *(KeypadAddress + 4);
    }
    else if((data <= MaxAndMinValues[5][1]) && (data >= MaxAndMinValues[5][0]))
    {
        return *(KeypadAddress + 5);
    }
    else if((data <= MaxAndMinValues[6][1]) && (data >= MaxAndMinValues[6][0]))
    {
        return *(KeypadAddress + 6);
    }
    else if((data <= MaxAndMinValues[7][1]) && (data >= MaxAndMinValues[7][0]))
    {
        return *(KeypadAddress + 7);
    }
    else if((data <= MaxAndMinValues[8][1]) && (data >= MaxAndMinValues[8][0]))
    {
        return *(KeypadAddress + 8);
    }
    else if((data <= MaxAndMinValues[9][1]) && (data >= MaxAndMinValues[9][0]))
    {
        return *(KeypadAddress + 9);
    }
    else if((data <= MaxAndMinValues[10][1]) && (data >= MaxAndMinValues[10][0]))
    {
        return *(KeypadAddress + 10);
    }
    else if((data <= MaxAndMinValues[11][1]) && (data >= MaxAndMinValues[11][0]))
    {
        return *(KeypadAddress + 11);
    }
    else if((data <= MaxAndMinValues[12][1]) && (data >= MaxAndMinValues[12][0]))
    {
        return *(KeypadAddress + 12);
    }
    else if((data <= MaxAndMinValues[13][1]) && (data >= MaxAndMinValues[13][0]))
    {
        return *(KeypadAddress + 13);
    }
    else if((data <= MaxAndMinValues[14][1]) && (data >= MaxAndMinValues[14][0]))
    {
        return *(KeypadAddress + 14);
    }
    else if((data <= MaxAndMinValues[15][1]) && (data >= MaxAndMinValues[15][0]))
    {
        return *(KeypadAddress + 15);
    }
    else if(data > Vmax)
    {
        return NO_KEY;
    }
	else
	{
		return NO_KEY;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//Pendiende de probar
void KeypadBegin(unsigned char *rows, unsigned char *cols, unsigned char *data)
{
    RowPins = rows;
    ColPins = cols;
    KeypadAddress = data;
    for(int i=0;i<4;i++)
    {
        pinMode(*(RowPins + i),INPUT);
        pinMode(*(ColPins + i),OUTPUT);
    }
}

//Pendiente de Probar
char KeypadRead(void)
{
    digitalWrite(*(ColPins),HIGH);
    digitalWrite(*(ColPins + 1),LOW);
    digitalWrite(*(ColPins + 2),LOW);
    digitalWrite(*(ColPins + 3),LOW);
    if(digitalRead(*(RowPins)))
    {
        delay(delaying);
        if(digitalRead(*(RowPins)))
        {
            return *(KeypadAddress);
        }
    }
    else if(digitalRead(*(RowPins + 1)))
    {
        delay(delaying);
        if(digitalRead(*(RowPins + 1)))
        {
            return  *(KeypadAddress + 1);
        }
    }
    else if(digitalRead(*(RowPins + 2)))
    {
        delay(delaying);
        if(digitalRead(*(RowPins + 2)))
        {
            return *(KeypadAddress + 2);
        }
    }
    else if(digitalRead(*(RowPins + 3)))
    {
        delay(delaying);
        if(digitalRead(*(RowPins + 3)))
        {
            return *(KeypadAddress + 3);
        }
    }
    else
    {
        digitalWrite(*(ColPins),LOW);
        digitalWrite(*(ColPins + 1),HIGH);
        digitalWrite(*(ColPins + 2),LOW);
        digitalWrite(*(ColPins + 3),LOW);
        if(digitalRead(*(RowPins)))
        {
            delay(delaying);
            if(digitalRead(*(RowPins)))
            {
                return *(KeypadAddress + 4);
            }
        }
        else if(digitalRead(*(RowPins + 1)))
        {
            delay(delaying);
            if(digitalRead(*(RowPins + 1)))
            {
                return *(KeypadAddress + 5);
            }
        }
        else if(digitalRead(*(RowPins + 2)))
        {
            delay(delaying);
            if(digitalRead(*(RowPins + 2)))
            {
                return *(KeypadAddress + 6);
            }
        }
        else if(digitalRead(*(RowPins + 3)))
        {
            delay(delaying);
            if(digitalRead(*(RowPins + 3)))
            {
                return *(KeypadAddress + 7);
            }
        }
        else
        {
            digitalWrite(*(ColPins),LOW);
            digitalWrite(*(ColPins + 1),LOW);
            digitalWrite(*(ColPins + 2),HIGH);
            digitalWrite(*(ColPins + 3),LOW);
            if(digitalRead(*(RowPins)))
            {
                delay(delaying);
                if(digitalRead(*(RowPins)))
                {
                    return *(KeypadAddress + 8);
                }
            }
            else if(digitalRead(*(RowPins + 1)))
            {
                delay(delaying);
                if(digitalRead(*(RowPins + 1)))
                {
                    return *(KeypadAddress + 9);
                }
            }
            else if(digitalRead(*(RowPins + 2)))
            {
                delay(delaying);
                if(digitalRead(*(RowPins + 2)))
                {
                    return *(KeypadAddress + 10);
                }
            }
            else if(digitalRead(*(RowPins + 3)))
            {
                delay(delaying);
                if(digitalRead(*(RowPins + 3)))
                {
                    return *(KeypadAddress + 11);
                }
            }
            else
            {
                digitalWrite(*(ColPins),LOW);
                digitalWrite(*(ColPins + 1),LOW);
                digitalWrite(*(ColPins + 2),LOW);
                digitalWrite(*(ColPins + 3),HIGH);
                if(digitalRead(*(RowPins)))
                {
                    delay(delaying);
                    if(digitalRead(*(RowPins)))
                    {
                        return *(KeypadAddress + 12);
                    }
                }
                else if(digitalRead(*(RowPins + 1)))
                {
                    delay(delaying);
                    if(digitalRead(*(RowPins + 1)))
                    {
                        return *(KeypadAddress + 13);
                    }
                }
                else if(digitalRead(*(RowPins + 2)))
                {
                    delay(delaying);
                    if(digitalRead(*(RowPins + 2)))
                    {
                        return *(KeypadAddress + 14);
                    }
                }
                else if(digitalRead(*(RowPins + 3)))
                {
                    delay(delaying);
                    if(digitalRead(*(RowPins + 3)))
                    {
                        return *(KeypadAddress + 15);
                    }
                }
                else
                {
                    return NO_KEY;
                }
            }
        }
    }
}
