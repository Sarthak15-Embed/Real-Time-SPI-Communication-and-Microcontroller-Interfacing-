#include"config.h"
#include<xc.h>
#include<pic16f877a.h>
#define _XTAL_FREQ 20000000
#include"SPI_Com.h"
#include"Lcd_8bit.h"
void SPI_Data(unsigned int Adc_Value);
void Received(char *ptr,char length);
//unsigned int Adc_value;
void main()
{
   // TRISC2=1;
    unsigned char Rx_data[5];
    Slave_Init();
    lcd_init();
	lcd_cmd(0x80);		
	lcd_str("SPI_Received:");
    while(1)
    {
      Received(Rx_data,5 );
      Rx_data[4]='\0';
      lcd_cmd(0xC0);
     lcd_data(Rx_data[0]);  
     lcd_data(Rx_data[1]);// display on LCD
     lcd_data(Rx_data[2]);
     lcd_data(Rx_data[3]);
    //  lcd_str(Rx_data);
	}
}
void Received(char*ptr,char length)
{
	int i;
	char temp=SPI_Rx();
	if(temp==':')
	{
	for(i=0;i<length;i++)
	*(ptr+i)=SPI_Rx();
	}
}
   


