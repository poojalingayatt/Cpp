#include<stdio.h>
void main()
{
    int i,Num ,sum=0;
    printf("Enter the number:");
    scanf("%d",&Num);

    for(i=1; i<=(Num/2); i++)
    {
        if(Num%i==0)
            sum+=i;
    }
        if(sum==Num)
            printf("YES perfect Number");
        else
            printf("NO not a perfect Number");

        printf("\n");
    printf("\n24CE060_POOJA\n");
}

