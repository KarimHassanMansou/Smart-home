#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void HLCD_voidInatialize(void);
void HLCD_voidSendCommand(u8 copy_u8Command);
void HLCD_voidSendData(u8 copy_u8Data);
void HLCD_voidSendString(const char *ptr_charData);
void LCD_Go_To (u8 line ,u8 x);
void HlCD_voidClearLcd();
void HLCD_voidWriteNumber(u8 number);

#endif
