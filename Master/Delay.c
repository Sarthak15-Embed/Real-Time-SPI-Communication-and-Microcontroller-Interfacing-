void delay(unsigned int time) 
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 6000; j++);
}