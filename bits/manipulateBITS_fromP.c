#include<stdio.h>

void displaybits(int x)
{
    for(int i = 31; i>=0; i--)
    {
        int mask = 1 << i;
        putchar((mask & x)? '1' : '0' );
    }
}

int main()
{
    int mask,p,n,x;
    p = 7;
    n = 4;

    // 0                    =      00000000 00000000 00000000 00000000
    //~0                    =      11111111 11111111 11111111 11111111
    //~0 << n               =      11111111 11111111 11111111 11110000
    //~(~0 << n)            =      00000000 00000000 00000000 00001111 
    //~(~0 << n) << (p-n)+1 =      00000000 00000000 00000000 11110000
    mask = ~(~0 << n) << p-n + 1;
    printf("\n displaying mask \n");
    displaybits(mask);

    printf("\n displaying x \n");
    x = 10345;
    displaybits(x);

    //set bits
    x = x | mask;
    printf("\n After setting bits: \n");
    displaybits(x);
    //clear bits
    x = 10345;
    printf("\n After clearing bits: \n");
    x = x & ~mask;
    displaybits(x);
    //invert bits
    x = 10345;
    printf("\n After inverting bits: \n");
    x = x ^ mask;
    displaybits(x);

    return 0;
}