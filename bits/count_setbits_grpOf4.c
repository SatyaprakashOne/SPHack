/*
* Count set bits in group of 4
*/ 

#include<stdio.h>

int table[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

void a_displaybits(unsigned int x)
{
    for(int j = 31; j>=0; j--)
    {
        int mask = 1 << j;
        putchar((x & mask)? '1' : '0');
    }
}

#ifdef GRP8 
/*
* In case we want to count the number of set bits in group of 8
* In this case we have to consider the array int table[] = {0,.....,256}; 
*/ 
int count_setbits8(unsigned int x )
{
    int count  = 0;
    while(x)
    {
        count = count + table[x & 0xFF];
        x = x >> 8;    
    }

    return count;
}
#endif //GRP8

int count_setbits4(unsigned int x )
{
    int count = 0;
    while( x != 0 )
    {
        //00000000000000000000010001100100 & 1111 = 00000000000000000000000000000100
        //count = count + table[00000000000000000000000000000100] :: count = count + table[4]
        //count = 0 + table[4] :: count = 0 + 1 :: count = 1
        count = count + table[x & 0xF]; 
        printf("count = %d table[x & 0xF] = %d\n",count, table[x & 0xF]);
        //00000000000000000000010001100100 >> 4 = 
        x = x >> 4;
        printf("result after x >> 4 \n");
        a_displaybits(x);
        printf("\n");
    }
    return count;
}

int main()
{
    unsigned int x = 1124;   
    
    printf("Binary of 1124 :\n");
    a_displaybits(x);
    printf("\n");

    printf("%d \n",count_setbits4(x));
    
    return 0;
}