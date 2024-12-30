#include<stdio.h>
void main()
{
    char string[10];
    int i, length=0;
    gets(string);

    for(i=0; string[i]!='\0'; i++)
    {
        length++;
    }
    printf("%d",length);
}
