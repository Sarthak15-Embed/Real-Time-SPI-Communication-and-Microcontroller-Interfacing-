#include<lpc214x.h>
#include"Arm_Adc.h"
#include"Arm_Lcd.h"
#include"Arm_PLL.h"
#include"Arm_SPI.h"
#include"Delay.h"
void SPI_Data(unsigned int);
unsigned int val;
int main()
{
	PLL_SET();
	Adc_Init();
	Arm_Lcd_Init();
	Master_Init();
	Lcd_Cmd(0x80);
	Lcd_Str("SPI_Master:");
	while(1)
	{
		val=Arm_Adc_Read();
		Lcd_Cmd(0xC0);
		Adc_Display(val);
		SPI_Data(val);
		delay(100);
	}
}
void SPI_Data(unsigned int val)
{
	 SPI_Write(':');
   SPI_Write((val/1000)+'0');
	 SPI_Write(((val/100)%10)+'0');
	 SPI_Write((val/10)%10+'0');
   SPI_Write((val%10)+'0');
}