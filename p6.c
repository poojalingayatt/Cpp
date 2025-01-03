#include<stdio.h>
#include<string.h>
void binaryToOctal(char binary[])
{
    int length=strlen(binary);
    int remainder=length%3;
    if(remainder!=0)
    {
        int padding = 3-remainder;
        for(int i=length-1;i>=0;i--)
        {
            binary[i+padding]=binary[i];
        }
        for(int i=0;i<padding;i++)
        {
             binary[i]='0';
        }

    binary[length+padding]='\0';
    length+=padding;
}
int value=0;
printf("The octal equivalent is: ");
for(int i=0;i<length;i++)
{
    value=value*2+(binary[i]- '0');
    if((i+1)%3==0)
    {
        printf("%d",value);
        value=0;
    }
}
 printf("\n");
    printf("\n24CE060_POOJA\n");
}
int main()
{
    char binary[100];
    printf("Enter Binary Number=");
    scanf("%s",binary);
    binaryToOctal(binary);
    return 0;
}
