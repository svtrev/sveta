#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int i, p, A[20];
    int c, k, m;
    m=0;
    printf("Введите кол-во элементов = ");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
    {
        A[i] = rand()%51-25;
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Введите искомое число = ");
    scanf("%d", &k);

    for (i = 0; i < p; i++)
    {
        if (A[i] == k)
            break;
        m++;
    }

    if (m!=0)
    {
        for (i = 0; i < m; i++)
        {
            c = A[i];
            A[i] = A[m - 1 - i];
            A[m - 1 - i] = c;
        }
        for (i = m + 1; i < p; i++)
        {
            c = A[i];
            A[i] = A[p - 1 - i];
            A[p - 1 - i] = c;
        }
    };
    if (m == 0)
    {
        for (i = 0; i < (p / 2); i++)
        {
            c = A[i];
            A[i] = A[p - 1 - i];
            A[p - 1 - i] = c;
        }
    }

    for (i = 0; i < p; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
