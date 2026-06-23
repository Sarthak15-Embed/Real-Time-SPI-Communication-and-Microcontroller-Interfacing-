#include<lpc214x.h>
#include"Arm_Adc.h"
#include"Arm_Lcd.h"
void Adc_Init()
{
	AD0CR = 0x00200F04;//Adc read
	PINSEL1 |= 0x04000000;//config Pot pin
}
unsigned int Arm_Adc_Read()
{
	//unsigned int Adc_Data;
	 AD0CR |= (1<<24);//Start Conversion
	 delay(5);
	 while(!(AD0DR2&(1<<31)));//Monitor
	 return ((AD0DR2>>6)& 0x3FF);//Extract 10bit Adc_data[15:6
	//return ((AD0GDR >> 6) & 0x03FF);
}

void Adc_Display(unsigned int Adc_value)
{
	Lcd_Data((Adc_value/1000)+'0');
	Lcd_Data(((Adc_value/100)%10)+'0');
	Lcd_Data((Adc_value/10)%10+'0');
  Lcd_Data((Adc_value%10)+'0');	
}