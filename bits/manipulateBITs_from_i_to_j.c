#include<stdio.h>


void displaybits(unsigned int x)
{
    for(int i = 31; i>=0; i--)
    {
        unsigned int mask = 1 << i;
        putchar((mask & x)? '1' : '0');
    }
}

int main()
{
    int i = 2;
    int j = 7;
    int x;
    //mask for manipulating bit from i to j
    int mask = ~0;

    displaybits(mask);

    //set bits

    //clear bits

    //invert

    return 0;
}