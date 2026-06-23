#include<lpc21xx.h>
#include"Arm_lcd.h"
void Arm_Lcd_Init()
{
	IODIR1|=0xFFFF00FF;
	Lcd_Cmd(0x02);//Initialize 4_bit
	Lcd_Cmd(0x28);//2 lines
	Lcd_Cmd(0x0C);//Display on cursor off
	Lcd_Cmd(0x06);//Auto Increment cursor
	Lcd_Cmd(0x01);//Display clear
}
void Lcd_Cmd(unsigned char cmd)
{
    // --- Upper Nibble ---
    // Mask upper 4 bits, shift to P1.16-P1.19
    IOPIN1 = ((IOPIN1 & 0xFF010000) | ((cmd & 0xF0) << 16));
    IOCLR1 = ((1<<Rs)|(1<<Rw)); // RS=0, RW=0
    IOSET1 = (1<<En);           // Enable High
    delay(5);
    IOCLR1 = (1<<En);           // Enable Low
    delay(5);

    // --- Lower Nibble (FIXED) ---
    // Mask lower 4 bits (0x0F), shift to P1.20-P1.23 (<< 20)
    IOPIN1 = ((IOPIN1 & 0xFF010000) | ((cmd & 0x0F) << 20)); 
    IOCLR1 = ((1<<Rs)|(1<<Rw)); // RS=0, RW=0
    IOSET1 = (1<<En);           // Enable High
    delay(5);
    IOCLR1 = (1<<En);           // Enable Low
    delay(5);
}   

void Lcd_Data(unsigned char data)
{
	//Upper Nibble
	// Mask upper 4 bits, shift to P1.16-P1.19
	IOPIN1=((IOPIN1 & 0xFF010000)|((data & 0xF0)<<16));
	IOSET1=(1<<Rs);//Rs=1
	IOCLR1=(1<<Rw);//Rw=0
	IOSET1=(1<<En);
	delay(5);
	IOCLR1=(1<<En);
	delay(5);
	//Lower Nibble
	// Mask lower 4 bits (0x0F), shift to P1.20-P1.23 (<< 20)
	IOPIN1=((IOPIN1 & 0xFF010000)|((data & 0x0F) << 20));
	IOSET1=(1<<Rs);//Rs=1
	IOCLR1=(1<<Rw);//Rw=0
	IOSET1=(1<<En);
	delay(5);
	IOCLR1=(1<<En);
	delay(5);
}
void Lcd_Str(unsigned char *str)
{
	while(*str)
	{
		Lcd_Data(*str++);
	}
}