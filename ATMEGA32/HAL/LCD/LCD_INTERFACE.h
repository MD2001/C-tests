/***********************************************************************************************************/
/***************************** Author : Mohamed diaa********************************************************/
/***************************** Layer : HAL *****************************************************************/
/***************************** SWC : LCD *******************************************************************/
/***************************** Version : 1.2 ***************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#include "../../LIB/STD_TYPES.h"

void LCD_Init(void);

void LCD_WriteCommand(u8 Command);

void LCD_WriteData(u8 Data);

void LCD_WriteString(char *Ptr);


void LCD_GoToXY(u8 X_Pos , u8 Y_Pos);

void LCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum);
void LCD_voidDisplayIntegar(u32 COPY_u32Number);


#define line1 1
#define line2 2
#define lcd_clr 0b00000001
#define shiftright 0b00011100
#define shiftleft 0b00011000
#define cursorleft 0b00010000
#define cursorright 0b00010100



#endif
