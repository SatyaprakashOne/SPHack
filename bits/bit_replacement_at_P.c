#include <stdio.h>

void displaybits(int x)
{
    for(int i = 31; i >=0; i--)
    {
        int mask = 1 << i;
        putchar((mask & x)? '1':'0');
    }
}

unsigned int func(unsigned int x, unsigned int y, int p, int n)
{
    unsigned int mask = ~(~0 << n) << p-n+1;
    //mask          = 00000000 00000000 00000000 11110000 
    //Y             = 00000000 00000000 00000101 01010111
    //(y & mask)    = 00000000 00000000 00000000 01010000

    //~mask         = 11111111 11111111 11111111 00001111
    //x             = 00000010 00110001 01110011 10110100

    //(x & ~mask)   = 00000010 00110001 01110011 00000100
    //(y & mask)    = 00000000 00000000 00000000 01010000
    //------------------------------------------------------------
    //    OR        = 00000010 00110001 01110011 01010100              

    //(x & ~mask)|(y & mask) = 

    printf("\n value of mask : \n");

    displaybits(mask);
    printf("\n value of k = (x & ~mask): \n");
    unsigned int k = (x & ~mask);
    displaybits(k);
    printf("\n value of l = (y & mask): \n");
    unsigned int l = (y & mask);
    displaybits(l);

    return (x & ~mask)|(y & mask);
}

int main()
{
    unsigned int y, x, z; 
    int p = 7, n = 4;
    x = 0x23173b4;
    y = 0x557;
    
    printf("\n Binary of X: \n");
    displaybits(x);
    printf("\n Binary of Y: \n");
    displaybits(y);
    z = func(x,y,p,n);

    printf("\n After conversion value of X: \n");
    displaybits(z);

    return 0;
}