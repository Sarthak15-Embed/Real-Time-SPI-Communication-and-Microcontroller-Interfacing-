#include <xc.h>
#include <pic16f877a.h>

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data1);
void lcd_str (unsigned char *str); 
#define _XTAL_FREQ 20000000
#define Lcd_Port PORTD
#define Lcd_Port_dir TRISD
#define Rs 0
#define En 1