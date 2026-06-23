#include <xc.h>
#include <pic16f877a.h>
#include "Lcd_8bit.h"
void lcd_init()
{
TRISC&=~((1<<Rs)|(1<<En));//Clearing Rs & En
Lcd_Port_dir=0x00;//Clearing Direction of Port
__delay_ms(20);
lcd_cmd (0x38);
lcd_cmd (0x0C);
lcd_cmd (0x06);
lcd_cmd (0x01);
}
void lcd_cmd(unsigned char cmd)
{
	PORTC&=~(1<<Rs);//Rs=0
    Lcd_Port=cmd;
    PORTC|=(1<<En);//En=1
	__delay_ms(5);
	PORTC&=~(1<<En);//En=0
}
void lcd_data(unsigned char data1)
{
	PORTC|=(1<<Rs);//Rs=1
    Lcd_Port=data1;
    PORTC|=(1<<En);//En=1
	__delay_ms(5);
	PORTC&=~(1<<En);//En=0
}
void lcd_str(unsigned char *str)
{
	/*int i=0;
	 while (str[i] != "\0") {
        lcd_data(str[i]);
        i++;
    }*/
	while(*str)
	{
		lcd_data(*str++);

	}
}