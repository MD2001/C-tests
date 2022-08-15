#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H







void LCD_SendCommand(u8 command);
void LCD_SendData(u8 data);
void LCD_Init(void);
void LCD_WriteString(char *ptr);




#endif
