#include<stdio.h>
#include<math.h>

void main()
{
    int i, Digit, Num, sum=0;
    printf("Enter the number of digits:");
    scanf("%d",&Digit);

    printf("Enter the number:");
    scanf("%d",&Num);

    int t=Num;

    for(i=0; i<Digit; i++)
    {
        int square= pow((Num%10),Digit);
        Num=Num/10;
        sum+= square;
    }

    Num=t;

    if(sum == Num)
    printf("\nNumber is Armstrong Number");
    else
    printf("\nNumber is not Armstrong Number");
    printf("\n");
    printf("\n24CE060_POOJA\n");
}
