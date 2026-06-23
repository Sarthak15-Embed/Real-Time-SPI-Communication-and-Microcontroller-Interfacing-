#include<lpc21xx.h>
void Arm_Lcd_Init();
void Lcd_Cmd(unsigned char);
void Lcd_Data(unsigned char);
void Lcd_Str(unsigned char *);
void delay(unsigned int) ;
#define Rs 17
#define Rw 18
#define En 19