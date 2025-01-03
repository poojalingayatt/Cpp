#include<stdio.h>
int calculateGCD(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int calculateLCM(int a,int b)
{
    return(a*b)/calculateGCD(a,b);
}
int main()
{
    int num1,num2,lcm;
    printf("Enter the first number:");
    scanf("%d",&num1);
    printf("Enter the second number:");
    scanf("%d",&num2);

    if(num1==0 || num2==0)
    {
        printf("LCM of 0 with any number is undefined.\n");
    }
    else
    {
        lcm=calculateLCM(num1,num2);
        printf("The LCM of %d and %d is: %d\n",num1,num2,lcm);
    }
    printf("\n");
    printf("\n24CE060_POOJA\n");
}
