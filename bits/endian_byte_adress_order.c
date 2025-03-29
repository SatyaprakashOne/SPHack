#include <stdio.h>
 
int main(void)
{
    unsigned int value = 0x11223344;
    int i;
    char *r = (char *) &value;

    printf("r = %p \n",r);  //this gives address of variable value
    printf("r = %p \n",*r); //As intel is little endian architecture , LSB 0x44 is going to be stored in the lower memory address.
 
    for(i=0; i<4; i++) 
    {
        printf("Address of 0x%x = %p \n", r[i], &r[i]);
    }


 return 0;
}