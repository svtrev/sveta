#include <math.h>
#include <stdio.h>

int main()

{
    float f, h, x;
    printf("Введите шаг h=");
    scanf("%f", &h);
    printf("\tx\t f(x)\n");
    printf("__________________________\n");
    for(x=0; x<1.6; x+=h)
    {
        if (x!=0)
        {
            f=exp(sin(2*x));
            printf("%8.3f\t %8.4f\n", x, f);
        }
    }
    return 0;
}
