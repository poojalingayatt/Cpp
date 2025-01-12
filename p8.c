#include<stdio.h>
void main()
 {
    int n; // Number of forces
    scanf("%d", &n);

    // Initialize the sum components of the force vectors
    int sum_x = 0, sum_y = 0, sum_z = 0;

    // Loop to process each vector
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        // Add each component to the corresponding sum
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    // Check if all sums are zero
    if (sum_x == 0 && sum_y == 0 && sum_z == 0)
     printf("YES\n"); // The body is in equilibrium

    else
     printf("NO\n"); // The body is not in equilibrium
}
