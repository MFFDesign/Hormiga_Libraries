/* 
 * File:   LCDI2C.h
 * Author: ToncheLAP
 *
 * Created on April 1, 2022, 2:24 PM
 */

#ifndef LCDI2C_H
#define	LCDI2C_H

#define BLON 0x08
#define BLOFF 0xF7
#define Enable_H 0x04
#define Enable_L 0xFB
#define Instruction 0xFE
#define Data 0x01

//Display Control
#define DisplayON   0x0C
#define DisplayOFF 0x0B
#define BlinkON 0x09
#define BlinkOFF    0x0E
#define CursorON    0x0A
#define CursorOFF   0x0D

//Display Control Functions
void Blinking(char mode);
void Cursor(char mode);
void Display(char mode);
void SendData(char databyte);
void LCDInit(char addrs);
void SendInstruction(char instruction);
void LCDClear(void);       
void LCDSetCursor(char row, char column);
void LCDWrite(char data);
void LCDPrint(char *string);
void Backlight(char mode);
        
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCDI2C_H */

