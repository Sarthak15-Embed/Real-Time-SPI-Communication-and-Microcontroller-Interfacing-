#include<lpc214x.h>
void Master_Init(void);
void Slave_Init(void);
void SPI_Write(unsigned char);
unsigned char SPI_Read(void);
#define SCK  4
#define MISO 5
#define MOSI 6
#define SS_SELECT 7