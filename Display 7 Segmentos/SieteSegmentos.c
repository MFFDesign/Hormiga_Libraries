#include "Hormiga877.h"
#include "SieteSegmentos.h"

uint16_t *ChPointer;
char dataPort;
char SegmentData[14] = {
    //--0-----1--------2-------3------4-------5--------6-------7------8-------9-----a-------b-------d-------h
    0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xFA, 0x3E, 0x9E, 0x6E
};

void DisplayBegin(char port,uint16_t *channels[5])
{
    ChPointer = channels;
    for(char i=0;i!=sizeof(channels);i++)
    {
        pinMode(*(ChPointer +i),OUTPUT);
        digitalWrite(*(ChPointer +i),LOW);
    }
    switch(port)
    {
        case 'b':
            TRISB= 0x00;
            PORTB = 0x00;
            dataPort = 'B';
            break;
        case 'B':
            TRISB = 0x00;
            PORTB = 0x00;
            dataPort = 'B';
            break;
        case 'c':
            TRISC = 0x00;
            PORTC = 0x00;
            dataPort = 'C';
            break;
        case 'C':
            TRISC = 0x00;
            PORTC = 0x00;
            dataPort = 'C';
            break;
        case 'd':
            TRISD = 0x00;
            PORTD = 0x00;
            dataPort = 'D';
            break;
        case 'D':
            TRISD = 0x00;
            PORTD = 0x00;
            dataPort = 'D';
            break;
        default:
            TRISB = 0x00;
            PORTB = 0x00;
            dataPort = 'B';
            break;
    }
}

void DisplayPrint(char code, char disply, char dp,char dt)
{
    char buffer = 0;
    if(code == 0x61) //a
    {
        buffer = SegmentData[10];
    }
    else if(code == 0x62) //b
    {
        buffer = SegmentData[11];
    }
    else if(code == 0x63) //c
    {
        buffer = SegmentData[12];
    }
    else if(code == 0x68) //h
    {
        buffer = SegmentData[13];
    }
    else if((code >= 0) && (code <=  9))
    {
        buffer = SegmentData[code];
    }
    if(dataPort == 'B')
    {
        if(dp == HIGH)
        {
            buffer |= 0x01;
            PORTB = buffer;
            if(dt != AlwaysOn)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
        else
        {
            buffer &= 0xFE;
            PORTB = buffer;
            if(dt != AlwaysOn)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
    }
    else if(dataPort == 'C')
    {
       if(dp == HIGH)
        {
            buffer |= 0x01;
            PORTC = buffer;
            if(dt != AlwaysOn)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
        else
        {
            buffer &= 0xFE;
            PORTC = buffer;
            if(dt != AlwaysOn)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
    }
    else if(dataPort == 'D')
    {
       if(dp == HIGH)
        {
            buffer |= 0x01;
            PORTD = buffer;
            if(dt != 0xFF)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
        else
        {
            buffer &= 0xFE;
            PORTD = buffer;
            if(dt != AlwaysOn)
            {
                digitalWrite(disply,HIGH);
                delay(dt);
                digitalWrite(disply,LOW);
                delay(dt);
            }
            else
            {
                digitalWrite(disply,HIGH);
            }
        }
    }
}
