#include<stdio.h>
#include<string.h>


void displaybits(int n)
{
    int mask = 0;
    for(int i = 31; i>=0; i--)
    {
        mask = 1<<i;
        putchar((n & mask)? '1' : '0');     
    }
}

unsigned int setbits(int n, int p, int w)
{
    
    
    //create a amask with w bit set to 1
    unsigned int mask = (1 << w) - 1;
    printf("\n Initial mask: \n");
    displaybits(mask);
    printf("\n Final mask: \n");
    // Shift the mask to the correct position
    mask = mask << p;
    displaybits(mask);
    printf("\n");
    printf("Final result post shifting - \n");
    // Set the bits in num using bitwise OR
    displaybits(n | mask);
    return n | mask;

}

int main()
{

    unsigned int num = 6;
    int p = 4;
    int w = 3;
    printf("num = %u \n",num);
    displaybits(num);
    unsigned int result  = setbits(num, p, w);
    printf("\n result = %u \n",result);
    return 0;
}


