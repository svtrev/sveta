/* Преобразовать матрицу в симметричную, отразив тот треугольник матрицы,
   сумма элементов которого меньше.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int mx[100][100], int a, int b)
{
    int i, j;
    srand(time(NULL));
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++)
            mx[i][j] = rand()%10;
}

void print(int mx[100][100], int a, int b)
{
    int i, j;
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
            printf("%d ", mx[i][j]);
        printf("\n");
    }
}

void main()
{
    int matrix[100][100];
    int a, b;

    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d%d", &a, &b);

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
            sum1 += matrix[i][j];
        else if(i > j)
            sum2 += matrix[i][j];
        }
    }
    printf("\nsum1 = %d   sum2 = %d\n\n", sum1, sum2);



    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            if(sum1 < sum2 && i < j)
                matrix[j][i] = matrix[i][j];
            else
                matrix[i][j] = matrix[j][i];
        }
    }

    if (sum1 < sum2)
        a = b;
    else
        b = a;

    printf("Обработанная матрица:\n");
    print(matrix, a, b);
}
