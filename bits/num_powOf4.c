#include<stdio.h>

int main()
{
    int n = 64;
    if(n && !(n & (n-1)) && (n & 0x55555555))
    {
        printf("n = %d is power of 4 \n", n);
    }
    else
    {
        printf("n = %d is not power of 4 \n",n);
    }
    return 0;
}