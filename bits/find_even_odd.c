#include<stdio.h>

int main()
{
    int n = 5;
    if (!(n & 0x1))
    {
        printf("Number is even \n");
    }
    else
    {
        printf("Number is odd \n");
    }
return 0;
}

