#include <stdio.h>
#include <stdlib.h>

unsigned int lcm_cycle(unsigned int lcm, unsigned int a, unsigned int b)
{
    unsigned int i;
    for (i = lcm;; i++)
    {
        if (!(i % a) && !(i % b))
            break;
    }
    return i;
}

unsigned int lcm_recurse(unsigned int lcm, unsigned int a, unsigned int b)
{
    if (lcm % a || lcm % b)
        return lcm_recurse(lcm + 1, a, b);
    else
        return lcm;
}

int main()
{
    unsigned int a, b, lcm;

    printf("Введите два натуральных числа (через пробел): ");
    scanf("%u%u", &a, &b);

    if (a >= b)
        lcm = a;
    else
        lcm = b;

    printf("Наименьшее общее кратное (через цикл) - %u\n", lcm_cycle(lcm, a, b));
    printf("Наименьшее общее кратное (через рекурсию) - %u\n", lcm_recurse(lcm, a, b));
}
