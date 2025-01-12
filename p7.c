#include<stdio.h>
void main()
{
    int n,m,a;
    printf("Enter the dimensions of square (n x m):");
    scanf("%d %d",&n,&m);
    printf("\nEnter the dimensions of flagstone (a x a):");
    scanf("%d",&a);

    if (n>=m && n>=a)
    {
        int flagstones_in_length = (n + a - 1) / a;
        int flagstones_in_width = (m + a - 1) / a;
        int total_flagstones = flagstones_in_length * flagstones_in_width;
        printf("Total flagstones required are:%d",total_flagstones);
    }
    printf("\n");
    printf("\n24CE060_POOJA\n");
}
