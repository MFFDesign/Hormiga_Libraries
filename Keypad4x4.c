#include "Keypad4x4.h"
#include "system.h"

static char characters[4][4] = {
    {'0','0','0','0'},
    {'0','0','0','0'},
    {'0','0','0','0'},
    {'0','0','0','0'}
};

static unsigned int MaxAndMinValues[16][2] = {
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

static int Vmax = 0;
static int Vmin = 0;
static int RowPins[4];
static int ColPins[4];
int delaying = 100;
unsigned int ADeCeChannel = 0;
void KeypadBegin(const int rows[4], const int cols[4], char data[4][4])
{
    for(int i=0;i<4;i++)
    {
        RowPins[i] = rows[i];
        ColPins[i] = cols[i];
        pinMode(RowPins[i],INPUT);
        pinMode(ColPins[i],OUTPUT);
    }
    
    for(int j=0;j<4;j++)
    {
        for(int k=0;k<4;k++)
        {
            characters[j][k] = data[j][k];
        }
    }
}

void analogKeypadBegin(unsigned int channel,unsigned int KayValues[4][4], char data[4][4])
{
	unsigned int VoltageKeys[16];
	unsigned int offset = 0;
	for(int a=0;a<4;a++)
	{
		offset = a*4;
		VoltageKeys[0+offset] = KayValues[a][0];
		VoltageKeys[1+offset] = KayValues[a][1];
		VoltageKeys[2+offset] = KayValues[a][2];
		VoltageKeys[3+offset] = KayValues[a][3];
	}
    ADeCeChannel = channel;
    for(int j=0;j<4;j++)
    {
        for(int k=0;k<4;k++)
        {
            characters[j][k] = data[j][k];
        }
    }
    for(int i=0;i<16;i++)
    {
        if(VoltageKeys[i] < 12)
        {
            MaxAndMinValues[i][1] = VoltageKeys[i] + 12;
            MaxAndMinValues[i][0] = 0;
        }
        else if(VoltageKeys[i] > 1011)
        {
            MaxAndMinValues[i][1] = 1011;
            MaxAndMinValues[i][0] = VoltageKeys[i] - 12;
        }
        else
        {
            MaxAndMinValues[i][1] = VoltageKeys[i] + 12;
            MaxAndMinValues[i][0] = VoltageKeys[i] - 12;
        }
        if(Vmax < MaxAndMinValues[i][1])
        {
            Vmax = MaxAndMinValues[i][1];
        }
    }
}

void analogKeypadCalibration(unsigned int channel)
{
    
}
char analogKeypadRead(void)
{
    unsigned int data = 0;
    data  = analogRead(ADeCeChannel);
    if((data <= MaxAndMinValues[0][1]) && (data >= MaxAndMinValues[0][0]))
    {
        return characters[0][0];
    }
    else if((data <= MaxAndMinValues[1][1]) && (data >= MaxAndMinValues[1][0]))
    {
        return characters[0][1];
    }
    else if((data <= MaxAndMinValues[2][1]) && (data >= MaxAndMinValues[2][0]))
    {
        return characters[0][2];
    }
    else if((data <= MaxAndMinValues[3][1]) && (data >= MaxAndMinValues[3][0]))
    {
        return characters[0][3];
    }
    else if((data <= MaxAndMinValues[4][1]) && (data >= MaxAndMinValues[4][0]))
    {
        return characters[1][0];
    }
    else if((data <= MaxAndMinValues[5][1]) && (data >= MaxAndMinValues[5][0]))
    {
        return characters[1][1];
    }
    else if((data <= MaxAndMinValues[6][1]) && (data >= MaxAndMinValues[6][0]))
    {
        return characters[1][2];
    }
    else if((data <= MaxAndMinValues[7][1]) && (data >= MaxAndMinValues[7][0]))
    {
        return characters[1][3];
    }
    else if((data <= MaxAndMinValues[8][1]) && (data >= MaxAndMinValues[8][0]))
    {
        return characters[2][0];
    }
    else if((data <= MaxAndMinValues[9][1]) && (data >= MaxAndMinValues[9][0]))
    {
        return characters[2][1];
    }
    else if((data <= MaxAndMinValues[10][1]) && (data >= MaxAndMinValues[10][0]))
    {
        return characters[2][2];
    }
    else if((data <= MaxAndMinValues[11][1]) && (data >= MaxAndMinValues[11][0]))
    {
        return characters[2][3];
    }
    else if((data <= MaxAndMinValues[12][1]) && (data >= MaxAndMinValues[12][0]))
    {
        return characters[3][0];
    }
    else if((data <= MaxAndMinValues[13][1]) && (data >= MaxAndMinValues[13][0]))
    {
        return characters[3][1];
    }
    else if((data <= MaxAndMinValues[14][1]) && (data >= MaxAndMinValues[14][0]))
    {
        return characters[3][2];
    }
    else if((data <= MaxAndMinValues[15][1]) && (data >= MaxAndMinValues[15][0]))
    {
        return characters[3][3];
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
char KeypadRead(void)
{
    digitalWrite(ColPins[0],HIGH);
    digitalWrite(ColPins[1],LOW);
    digitalWrite(ColPins[2],LOW);
    digitalWrite(ColPins[3],LOW);
    if(digitalRead(RowPins[0]))
    {
        delay(delaying);
        if(digitalRead(RowPins[0]))
        {
            return characters[0][0];
        }
    }
    else if(digitalRead(RowPins[1]))
    {
        delay(delaying);
        if(digitalRead(RowPins[1]))
        {
            return characters[1][0];
        }
    }
    else if(digitalRead(RowPins[2]))
    {
        delay(delaying);
        if(digitalRead(RowPins[2]))
        {
            return characters[2][0];
        }
    }
    else if(digitalRead(RowPins[3]))
    {
        delay(delaying);
        if(digitalRead(RowPins[3]))
        {
            return characters[3][0];
        }
    }
    else
    {
        digitalWrite(ColPins[0],LOW);
        digitalWrite(ColPins[1],HIGH);
        digitalWrite(ColPins[2],LOW);
        digitalWrite(ColPins[3],LOW);
        if(digitalRead(RowPins[0]))
        {
            delay(delaying);
            if(digitalRead(RowPins[0]))
            {
                return characters[0][1];
            }
        }
        else if(digitalRead(RowPins[1]))
        {
            delay(delaying);
            if(digitalRead(RowPins[1]))
            {
                return characters[1][1];
            }
        }
        else if(digitalRead(RowPins[2]))
        {
            delay(delaying);
            if(digitalRead(RowPins[2]))
            {
                return characters[2][1];
            }
        }
        else if(digitalRead(RowPins[3]))
        {
            delay(delaying);
            if(digitalRead(RowPins[3]))
            {
                return characters[3][1];
            }
        }
        else
        {
            digitalWrite(ColPins[0],LOW);
            digitalWrite(ColPins[1],LOW);
            digitalWrite(ColPins[2],HIGH);
            digitalWrite(ColPins[3],LOW);
            if(digitalRead(RowPins[0]))
            {
                delay(delaying);
                if(digitalRead(RowPins[0]))
                {
                    return characters[0][2];
                }
            }
            else if(digitalRead(RowPins[1]))
            {
                delay(delaying);
                if(digitalRead(RowPins[1]))
                {
                    return characters[1][2];
                }
            }
            else if(digitalRead(RowPins[2]))
            {
                delay(delaying);
                if(digitalRead(RowPins[2]))
                {
                    return characters[2][2];
                }
            }
            else if(digitalRead(RowPins[3]))
            {
                delay(delaying);
                if(digitalRead(RowPins[3]))
                {
                    return characters[3][2];
                }
            }
            else
            {
                digitalWrite(ColPins[0],LOW);
                digitalWrite(ColPins[1],LOW);
                digitalWrite(ColPins[2],LOW);
                digitalWrite(ColPins[3],HIGH);
                if(digitalRead(RowPins[0]))
                {
                    delay(delaying);
                    if(digitalRead(RowPins[0]))
                    {
                        return characters[0][3];
                    }
                }
                else if(digitalRead(RowPins[1]))
                {
                    delay(delaying);
                    if(digitalRead(RowPins[1]))
                    {
                        return characters[1][3];
                    }
                }
                else if(digitalRead(RowPins[2]))
                {
                    delay(delaying);
                    if(digitalRead(RowPins[2]))
                    {
                        return characters[2][3];
                    }
                }
                else if(digitalRead(RowPins[3]))
                {
                    delay(delaying);
                    if(digitalRead(RowPins[3]))
                    {
                        return characters[3][3];
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

//void KeyPadSetupTest(void)
//{
//    for(int i=0;i<4;i++)
//    {
//        pinMode(ROWS[i],INPUT);
//        pinMode(COLS[i],OUTPUT);
//    }
//}
//void KeypadLoopTest(void)
//{
//    delay(100);
//    digitalWrite(COLS[0],HIGH);
//    digitalWrite(COLS[1],LOW);
//    digitalWrite(COLS[2],LOW);
//    digitalWrite(COLS[3],LOW);
//    if(digitalRead(ROWS[0]))
//    {
//        data = keys[0][0];
//    }
//    else if(digitalRead(ROWS[1]))
//    {
//        data = keys[1][0];
//    }
//    else if(digitalRead(ROWS[2]))
//    {
//        data = keys[2][0];
//    }
//    else if(digitalRead(ROWS[3]))
//    {
//        data = keys[3][0];
//    }
//    else
//    {
//        delay(100);
//        digitalWrite(COLS[0],LOW);
//        digitalWrite(COLS[1],HIGH);
//        digitalWrite(COLS[2],LOW);
//        digitalWrite(COLS[3],LOW);
//        if(digitalRead(ROWS[0]))
//        {
//            data = keys[0][1];
//        }
//        else if(digitalRead(ROWS[1]))
//        {
//            data = keys[1][1];
//        }
//        else if(digitalRead(ROWS[2]))
//        {
//            data = keys[2][1];
//        }
//        else if(digitalRead(ROWS[3]))
//        {
//            data = keys[3][1];
//        }
//        else
//        {
//            delay(100);
//            digitalWrite(COLS[0],LOW);
//            digitalWrite(COLS[1],LOW);
//            digitalWrite(COLS[2],HIGH);
//            digitalWrite(COLS[3],LOW);
//            if(digitalRead(ROWS[0]))
//            {
//                data = keys[0][2];
//            }
//            else if(digitalRead(ROWS[1]))
//            {
//                data = keys[1][2];
//            }
//            else if(digitalRead(ROWS[2]))
//            {
//                data = keys[2][2];
//            }
//            else if(digitalRead(ROWS[3]))
//            {
//                data = keys[3][2];
//            }
//            else
//            {
//                delay(100);
//                digitalWrite(COLS[0],LOW);
//                digitalWrite(COLS[1],LOW);
//                digitalWrite(COLS[2],LOW);
//                digitalWrite(COLS[3],HIGH);
//                if(digitalRead(ROWS[0]))
//                {
//                    data = keys[0][3];
//                }
//                else if(digitalRead(ROWS[1]))
//                {
//                    data = keys[1][3];
//                }
//                else if(digitalRead(ROWS[2]))
//                {
//                    data = keys[2][3];
//                }
//                else if(digitalRead(ROWS[3]))
//                {
//                    data = keys[3][3];
//                }
//                else
//                {
//                    data = 'n';
//                }
//            }
//        }
//    }
//}