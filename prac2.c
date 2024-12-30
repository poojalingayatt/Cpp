#include<stdio.h>
void main()
{
    char string[25];
    int i;
    printf("Enter string:");
    gets(string);

    for(i=0; string[i]!='\0'; i++)
    {
         if(string[i]>=65 && string[i]<=91)
         string[i]+=32;

         else if(string[i]>=97 && string[i]<=123)
         string[i]-=32;
    }

    puts(string);
}
