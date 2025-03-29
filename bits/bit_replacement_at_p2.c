
#include<stdio.h>


void displaybits(unsigned int n)
{
    for(int i = 31; i >= 0; i--)
    {
        unsigned int mask = 1 << i;
        putchar((mask & n)? '1' : '0');
    }
}

unsigned int func(unsigned int x, unsigned int y, int p, int n)
{
    unsigned int mask = ~(~0<<n) << p-n+1;
    printf("\n displaying mask \n");
    displaybits(mask);
    //mask =    00000000 00000000 00000000 11110000
    //~mask =   11111111 11111111 11111111 00001111
    //x =       00000010 00110001 01110011 10110100
    //x&~mask = 00000010 00110001 01110011 00000100

    //mask =            00000000 00000000 00000000 11110000
    //y =               00000000 00000000 00000101 01010111
    //y<<n =            00000000 00000000 01010101 01110000
    //mask & y<<p-n+1 = 00000000 00000000 00000000 01110000
    //x&~mask =         00000010 00110001 01110011 00000100
    //OR  =             00000010 00110001 01110011 01110100

    return (x&~mask)|(mask & y<<p-n+1); 
}
int main()
{
    int p = 7, n = 4;
    unsigned int x = 0x23173b4;
    unsigned int y = 0x557;
    printf("\n displaying x \n");
    displaybits(x);
    printf("\n displaying y \n");
    displaybits(y);
    x = func(x,y,p,n);
    printf("\n displaying resulatant x \n");
    displaybits(x);
    return 0;
}