#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, z;
    printf("Enter x {-2.4 < x < 0.29} -> \t");
    scanf("%f", &x);
    if (x > -2.4 && x < 0.29)
    {
        y = acos((2 * x) / ((x * x) + 1));
        z = log(sin(M_PI / y));
        printf ("y= %f \nz= %f \n", y, z);
    }
    else
        printf("X ne podhodit \n");
    return 0;
}
