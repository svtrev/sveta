#include <math.h>
#include <stdio.h>

int main()

{
    float f, h, x;
    printf("Введите шаг h=");
    scanf("%f", &h);
    printf("\tx\t f(x)\n");
    printf("__________________________\n");
    for(x=-1.5;x<=1.5;x+=h)
    {
        if (x<=0)
            f=(pow(x,2)-2*(pow(x,3)))*cos(pow(x,2));
        else
            f=exp(sin(2*x));
        printf("%8.2f\t %8.4f\n", x, f);
    }
    return 0;
}
