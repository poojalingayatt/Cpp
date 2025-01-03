#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c;
    printf("Enter the constants of Equation: ax^2 + bx + c");
    printf("\nEnter a:");
    scanf("%d",&a);
    printf("\nEnter b:");
    scanf("%d",&b);
    printf("\nEnter c:");
    scanf("%d",&c);

    float D= (pow(b,2))- (4*a*c);

    if(D>0)
    {
        printf("\nReal roots are:");
      float  x1= (-b + sqrt(D))/ 2*a ;
      float  x2= (-b - sqrt(D))/ 2*a ;
      printf("\n%0.1f and %0.1f",x1,x2);
    }

    else if(D=0)
    {
        printf("\nOne Real Root Exists:");
        float  x= (-b + sqrt(D))/ 2*a ;
        printf("\n%0.1f",x);
    }

    else
    {
        printf("\nNo Real Roots Exists");
    }
    printf("\n");
    printf("\n24CE060_POOJA\n");
}
