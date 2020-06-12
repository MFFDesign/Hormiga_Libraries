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
#define DATA            0x01
#define INSTRUCTION     0x00
#define FUNCTION_SET    0x28  // 4 bit interface, 2 lines, 5x8 font 
#define DISPLAY_SETUP   0x0C                         // display on, cursor off, blink offd
#define ENTRY_MODE      0x06                         // increment mode
#define CLEAR_DISPLAY   0x01
#define GOTOHOME        0x02
#define MOVECURSORRIGHT 0x05 //Do shift Display
#define CURSORRIGHT     0x06 //DOnt Shif Display (Most Common)
#define STEADYCURSOR    0x0E //Display ON cursor ON
#define BLINKCURSOR     0x0F
#define SHIFTLEFT       0x10 //Shift Cursor Left
#define SHIFTRIGHT      0x14 //Shift Cursor right
#define DISPLAYLEFT      0x18 //Shift Display Left
#define NB_LINES        2
#define NB_COL          16
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
    void lcdShiftRight(void);
    void lcdShiftLeft(void);
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

