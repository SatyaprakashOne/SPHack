#include<stdio.h>

int main()
{
    //Always power of 2 number has only one bit set. That one is the right most bit 
    //To  check the right most set bit we use the method n & (n-1) : 
    //Example 8 = 1000 , 7 = 0111 , 1000 & 0111 = 000000

    int n = 16; //10000

    if(n && !(n & (n-1)))
    {
        printf("n = %d is power of 2 \n",n);
    }
    return 0;
}