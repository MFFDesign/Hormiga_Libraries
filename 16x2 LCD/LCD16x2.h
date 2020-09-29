/* 
 * File:   LCD16x2.h
 * Author: c4810
 *
 * Created on July 19, 2019, 10:54 AM
 */

#ifndef LCD16X2_H
#define	LCD16X2_H

    #include <xc.h>
    #include <stdint.h>
    // LCD Commands:
#define ENABLE 0x01
#define DISABLE 0x00
    /*
     * lcdClear() :  is used to clear de display.
     */
    void lcdClear(void);
    /*
     * lcdSetCursor(int row, int column): is used
     * to set the row and column of the cursor on the LCD
     * screen. by using this function we can change the position
     * of the character or string displayed.
     */
    void lcdSetCursor(char row, char column);
    /*
     * lcdWrite(char data) :  to writa a character on the current position.
     */
    void lcdWrite(char data);
    void lcdPrint(char *string);
    void lcdWritePort(char a);
    void lcdCommand(char data, char mode);
    void lcdBegin(char RS, char EN, char R_W, char d4, char d5, char d6,char d7);
    void LcdWriteNibble(char data , char mode);
    void ByteByNibble(char NibbleValue);
    void WriteData(char data);
    void WriteInstruction(char instruction);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD16X2_H */

