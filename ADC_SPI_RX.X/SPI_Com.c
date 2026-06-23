#include<xc.h>
#include<pic16f877a.h>
#include"SPI_Com.h"
void Master_Init()
{
    SSPSTAT=0x80;
    SSPCON=0x20;
    TRISC3 = 0;            // SCK is output in Master mode
    TRISC4 = 1;            // SDI is input (data coming in)
    TRISC5 = 0;            // SDO is output (data going out)
 //   TRISA5 = 1;            // SS is output (Master drives this low to select slave)
}
void Slave_Init()
{
    SSPSTAT=0x00;
    SSPCON=0x24;
    TRISC3 = 1;           // SCK is input in Slave mode
    TRISC4 = 1;           // SDI is input (data coming in)
    TRISC5 = 0;           // SDO is output (data going out)
    TRISA5 = 1;           // SS is input (Slave Select driven by Master
}
void SPI_Tx(char Tx_data)
{
    SSPBUF=Tx_data;
    while(SSPIF==0);
    SSPIF=0;
}
unsigned char SPI_Rx()
{
    while(SSPIF==0);
    SSPIF=0;
     return SSPBUF;
}