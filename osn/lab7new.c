/* Преобразовать матрицу в симметричную, отразив тот треугольник матрицы,
   сумма элементов которого меньше.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int *mx, int a, int b)
{
    int i, j;
    srand(time(NULL));
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++)
            mx[i * b + j] = rand()%10;
}

void print(int *mx, int a, int b)
{
    int i, j;
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
            printf("%d ", mx[i * b + j]);
        printf("\n");
    }
}

int main()
{
    int a, b;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d%d", &a, &b);

    int *matrix = (int *) malloc (a * b * sizeof (int));

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
        for(j = 0; j < b; j++)
        {
        if (i < j)
            sum1 += matrix[i * b + j];
        else if(i > j)
            sum2 += matrix[i * b + j];
        }
    }
    printf("\nsum1 = %d   sum2 = %d\n\n", sum1, sum2);

    if (a > b)

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            if(sum1 < sum2 && i < j)
                matrix[j * b + i] = matrix[i * b + j];
            else
                matrix[i * b + j] = matrix[j * b + i];
        }
    }

    if (sum1 < sum2)
        a = b;
    else
        b = a;

    printf("Обработанная матрица:\n");
    print(matrix, a, b);
    free (matrix);

    return(0);
}
