#include<stdio.h>

void displaybits(int x)
{
    for(int i = 31; i>=0; i--)
    {
        int mask = 1<<i;
        putchar((x & mask)? '1' : '0');
    }
}
int main()
{
    int x = 5;

    displaybits(x);
    printf("\n");
    x = x & (x-1);

    displaybits(x);
    return 0;
}