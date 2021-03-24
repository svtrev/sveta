#include <math.h>
#include <stdio.h>

int main()

{
    float f, i, h;
    printf("Введите шаг h=");
    scanf("%f", &h);
    printf("\tx\t f(x)\n");
    printf("________________________\n");
    i=-1.5;
    while (i<=0)
    {
        f=(pow(i,2)-2*(pow(i,3)))*cos(pow(i,2));
        printf("%8.3f\t %8.4f\n", i, f);
        i+=h;
    }
    return 0;
}
