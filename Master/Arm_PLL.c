#include<lpc214x.h>
#include"Arm_PLL.h" 
 void PLL_SET()
 {
	 PLL0CON=0x01;//PLL Enable
	 PLL0CFG=0x24;//PLL Multiplier'M' & Divider 'P' values
	 PLL0FEED=0xAA;
	 PLL0FEED=0x55;
	 while(!PLL0STAT & (1<<10));
	 PLL0CON=0x03;//PLL Enable & Connect
	 PLL0FEED=0xAA;
	 PLL0FEED=0x55;
	 VPBDIV=0x01;
 }