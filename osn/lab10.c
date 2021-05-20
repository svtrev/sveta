#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int *mx, int a, int b)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
            mx[i * a + j] = rand() % 10;
}

void print(int *mx, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            printf("%d ", mx[i * a + j]);
        printf("\n");
    }
}

int main()
{
    int a, b;

    printf("Введите количество строк и столбцов : ");
    scanf("%d%d", &a, &b);

    int *matrix = (int *)malloc(a * b * sizeof(int));

    if (!matrix)
    {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    fill(matrix, a, b);
    printf("Исходная матрица:\n");
    print(matrix, a, b);

    int i, j;
    int sum1 = 0, sum2 = 0;

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (i < j)
                sum1 += matrix[i * a + j];
            else if (i > j)
                sum2 += matrix[i * a + j];
        }
    }

    printf("\nsum1 = %d sum2 = %d\n\n", sum1, sum2);

    if (a > b)
        a = b;
    else
        b = a;

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (sum1 < sum2)
                matrix[i * a + j] = matrix[j * b + i];
            else
                matrix[j * b + i] = matrix[i * a + j];
        }
    }

    printf("Обработанная матрица:\n");
    print(matrix, a, b);
    free(matrix);
    return 0;
}
