#include <stdio.h>

void displaybits(unsigned int x)
{
    for(int i = 31; i>=0; i--)
    {
        unsigned int mask = 1 << i;
        putchar((mask & x)? '1' : '0');
    }
}

unsigned int func(unsigned int x, unsigned int y, int p, int n)
{
    printf("\n displaying x: \n");
    displaybits(x);

    printf("\n displaying y: \n");
    displaybits(y);

    unsigned int mask  = ~(~0<<n) << p-n+1; //13-6+1 = 8 
    printf("\n displaying mask: \n");
    displaybits(mask);
    //mask      =   00000000 00000000 00111111 00000000
    //~mask     =   11111111 11111111 11000000 11111111
    //x         =   00000010 00110001 01110011 10110100
    //x&~mask   =   00000010 00110001 01000000 10110100

    //mask      =   00000000 00000000 00111111 00000000
    //y         =   00000000 00000000 00000000 00101111
    //y<<p-n+1  =   00000000 00000000 00101111 00000000

    //OR        =   00000010 00110001 01101111 10110100 

    return (x&~mask)|(y<<p-n+1);
} 

int main()
{
    unsigned int x = 0x23173b4, y = 0x2F;
    int p = 13,n = 6;

    x =  func(x,y,p,n);

    printf("\n displaying resultant x: \n");
    displaybits(x);

    return 0;
}