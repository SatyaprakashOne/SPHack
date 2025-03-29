#include<stdio.h>

#define CONVERT(x)  ((x & 0x000000FF) << 24 | (x & 0x0000FF00) << 8 | (x & 0x00FF0000) >> 8 | (x & 0xFF000000) >> 24)

int main()
{
    unsigned int n = 0x12345678;
    unsigned int result = CONVERT(n);

     printf("after conversion result = 0x%x  \n",result);
    return 0;
    
}