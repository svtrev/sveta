#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double integral(int n)
{
    int i;
    double x, h, integ = 0;
    h = (M_PI) / n;

    for (i = 0; i <= n; i++)
    {
        x = -M_PI_2 + i * h + (h / 2);

        if (x <= 0)
            integ += ((x * x) - 2 * (x * x * x)) * cos(x * x);
        else if (x <= M_PI_2)
            integ += exp(sin(2 * x));
    }

    return integ * h;
}

int main()
{
    double e, k = 1.0, s = 0.0, d = 1.0;
    int n = 1;

    printf("Введите требуемую точность e = ");
    scanf("%lf", &e);

    while (d >= e)
    {
        d = (fabs(k - s)) / 3;
        s = k;
        n *= 2;
        k = integral(2 * n);
        printf("%lf\t%lf\t%d\n", k, d, n);
    }

    printf("Значение интеграла I = %.5lf\n", k);

    return 0;
}
