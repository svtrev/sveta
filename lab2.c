#include <stdio.h>
#include <math.h>

int main()

{
    float x, y, z;
    double pi=acos(-1.0);
    printf("vvedite x \t");
    scanf("%f", &x);
    y=acos((2*x)/(pow(x,2)+1));
    if (sin(pi/y)>0)
    {
        z=log(sin(pi/y));
        printf ("y= %f \nz= %f \n", y, z);
    }
    else
        printf("X ne podhodit \n");
    return 0;
}
