#include <math.h>
#include <stdio.h>
#include <stdlib.h>
# include <time.h>
void fill( int n , int a[])
{
		int i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 51 - 25;
    }
}
int main()
{
    int i, n, t, k, j, m = 0, c;
		srand(time(NULL));
    printf("Vvedite kolvo elementov = ");
    scanf("%d", &n);
		int A[n];

    fill(n, A);

		for (i = 0; i < n; i++)
    {
        printf("%5d ", A[i]);
    }
    printf("\n");

		printf("Vvedite iskomoe chislo = ");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        if (A[i] == k)
            break;
        m++;
    }

    if (m != 0)
    {
        for (i = 0; i < m / 2; i++)
        {
            t = A[i];
            A[i] = A[m - 1 - i];
            A[m - 1 - i] = t;
        }
        c = (n - m) / 2;
        for (i = m + 1, j = 0; c > 0; c--, j++)
        {
            t = A[i + j];
            A[i + j] = A[n - 1 - j];
            A[n - 1 - j] = t;
        }
    }

    if (m == 0)
    {
        for (i = 0; i < (n / 2); i++)
        {
            t = A[i];
            A[i] = A[n - 1 - i];
            A[n - 1 - i] = t;
        }
    }

    for (i = 0; i < n; i++)
        printf("%5d ", A[i]);
    printf("\n");
    return 0;
}
