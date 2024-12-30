#include<stdio.h>
#include<math.h>

void main()
{
    int n,i,sum=0;
    printf("Enter the number of digits:");
    scanf("%d",&n);
    int num[n];


         for(i=0; i<n; i++)
         {
             printf("\nEnter the %d number:",i+1);
             scanf("%d",&num[i]);
             sum+= pow(num[i],n);
         }

    if(sum == num)
    printf("\nNumber is Armstrong Number");
}

