#include "Keypad4x4.h"
#include "system.h"

static char characters[4][4] = {
    {'0','0','0','0'},
    {'0','0','0','0'},
    {'0','0','0','0'},
    {'0','0','0','0'}
};

static int RowPins[4];
static int ColPins[4];
int delaying = 100;
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