#include <math.h>
#include <stdio.h>

int main()
{
    float f, h, x, n, x0;
    int i;
    printf("Введите шаг h=");
    scanf("%f", &h);
    printf("\tx\t f(x)\n");
    printf("__________________________\n");
    n = (1.5 - (-1.5)) / h;
    x0 = -1.5;
    i = 0;
    while (i <= n)
    {
        x = x0 + i * h;
        if (x <= 0)
            f = ((x * x) - 2 * (x * x * x)) * cos(x * x);
        else
            f = exp(sin(2 * x));
        printf("%f\t %8.4f\n", x, f);
        i++;
    }
    return 0;
}
