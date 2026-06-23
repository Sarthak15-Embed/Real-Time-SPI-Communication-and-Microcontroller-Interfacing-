#include"Arm_SPI.h"
void Master_Init()
{
	// Configure pins: P0.4=SCK0, P0.5=MOSI0, P0.6=MISO0, P0.7=SSEL0
	PINSEL0 |= 0x00001500; //Configure P0.4–P0.7 for SPI0
  IODIR0 &=~ (1<<MISO);//MISO Input
	IODIR0 |=((1<<MOSI)|(1<<SCK)|(1<<SS_SELECT));//MOSI-SCK-SS = Output
	S0SPCR=0x20;  // Enable SPI in Master mode, CPOL/CPHA default
	//S0SPCCR=8; // SPI clock = PCLK/8
	S0SPCCR=96; // SPI clock = PCLK/8 for pic
}
void Slave_Init()
{
	PINSEL0 |= 0x00005500; //Configure P0.4–P0.7 for SPI0
	IODIR0 |= (1<<MISO);//MISO Output
	IODIR0 &=~((1<<MOSI)|(1<<SCK)|(1<<SS_SELECT));//MOSI-SCK-SS = Input
	S0SPCR=0x00000000;  // Enable SPI in Slave mode, CPOL/CPHA default
	S0SPCCR=12;
}
void SPI_Write(unsigned char Tx_Data)
{
	S0SPDR=Tx_Data; //Write data to buffer Reg.
	while(!(S0SPSR & (1<<7))); //Wait until SPIF=1 (bit 7) ? transfer complete
}
unsigned char SPI_Read()
{
	while(!(S0SPSR & (1<<7)));//Wait until SPIF=1 (bit 7) ? transfer complete
	return S0SPDR; //Read received data
}