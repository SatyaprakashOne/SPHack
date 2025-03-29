#include<stdio.h>

int main()
{
    unsigned int n = 0x1;
    char *num = (char *)&n;

    printf("%x \n",*num);
    if(*num == 0x1)
    {
        printf("Your system is little endian \n");
    }
    return 0;
}