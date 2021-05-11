#include <time.h>      //Контрольная работа 1. Задание 3. Вариант 2. Создать матрицу по рисунку//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, k = 1;
    printf("Введите кол-во строк и столбцов квадратной матрицы = ");
    scanf("%d", &n);
    int a[n][n];
    printf("Массив:\n");
    for (i = 1; i <= n; i++)
    {   for (j = 1; j <= n; j++)
        {
        if (i + j == n + 1)
            {
            a[i][j] = k;
            k++;
            }
        else a[i][j] = 0;
        printf("%5d ", a[i][j]);
        }
    printf("\n");
    }
}
