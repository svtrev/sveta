#include <time.h>      //Контрольная работа. Задание 2. 2 вариант.//
#include <stdio.h>     //Создайте одномерный массив. Заполните его случайными числами от-10 до 10. Выведите на экран массив и его же в обратном порядке.//
#include <stdlib.h>    //Найдите минимальное значение и его индекс ( первый если таких значений несколько).//

int main()
{
    int i, n, d, min = 10;
    srand(time(NULL));
    printf("Vvedite kolvo elementov = ");
    scanf("%d", &n);
    int a[n];
    printf("Массив:         ");
    for (i = 0; i < n; i++) //заполняем случайными числами [-10;10] и выводим//
    {
        a[i] = rand() % 21 - 10;
        printf("%5d ", a[i]);
    }
    printf("\n");
    printf("Обратный массив:");
    for (i = n-1; i >= 0; i--) //выводим в обратном порядке//
    {
        printf("%5d ", a[i]);
        if (a[i] < min) //ищем минимальное//
        {
            min = a[i];
            d = i; //индекс минимального//
        };
    }
    printf("\n"); 
    printf("Индекс минимального: %d\n", d);
    printf("Минимальное: %d\n", min);
}
