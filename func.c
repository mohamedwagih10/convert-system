#include <stdio.h>
#include <string.h>
#include "func.h"
void Dec2Bin(unsigned num){
    int mask=1<<31;
    int counter=0;
    for(counter=0; counter<32; counter++){
        putchar(num&mask?'1':'0');
        if (counter%4==0)
        {
            printf(" ");
        }
        
    }
    printf("\n");

}
char * negative_converter(char *bits){
    char check=0;
    for (int i =strlen(bits)-1 ; i >=0; i--)
    {
        if (!check)
        {
            if (bits[i]=='1')
            {
                bits[i]='1';
                check=1;
            }
            else
            {
                bits[i]='0';
            }
            
            
        }
        else
        {
            bits[i]^=1;
        }
        
        
    }
    return bits;
}
int Bin2dec(char *arr )
{
    // check if its a negative number
    char ngtv = 0 ;
    if( *arr == '1')
    {
        arr = negative_converter(arr);
        ngtv =  1 ;
    }

    unsigned int weight = 1;
    int result =0;
    for(int i = strlen(arr)-1 ; i>=0 ; i--)
    {
        short k= 1 ;
        if(arr[i] == '1')
            result += weight ;
        weight *= 2;
    }
    return ngtv ? -result : result ;
}