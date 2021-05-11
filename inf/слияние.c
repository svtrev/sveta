#include <stdio.h>
void fill(int n, int a[200]) // функция заполнения//
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void print(int n, int a[200]) // функция выведения//
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d ", a[i]);
    }
    printf("\n");
}

void Merge(int a[200], int first, int last)
{
    int middle, start, final, i;
    int mas[200];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (i = first; i <= last; i++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (a[start] < a[final])))
        {
            mas[i] = a[start];
            start++;
        }
        else
        {
            mas[i] = a[final];
            final++;
        }
    //возвращение результата в список
    for (i = first; i <= last; i++)
    {
        a[i] = mas[i];
    }
}

void MergeSort(int a[], int first, int last) //рекурсивная процедура сортировки
{
    if (first < last)
    {
        MergeSort(a, first, (first + last) / 2);  //сортировка левой части
        MergeSort(a, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(a, first, last);  //слияние двух частей
    }
}

void main()
{
    int n;
    printf("Введите кол-во элементов = ");
    scanf("%d", &n);
    int A[200];
    printf("Введите элементы через пробел:");
    fill(n, A); //заполнение массива с клавиатуры//
    printf("Исходный массив:\n");
    print(n, A); //выведение исходного массива//

    MergeSort(A, 1, n); //функция сортировки//

    printf("Сортированный массив:\n");
    print(n, A); //выведение сортированного массива//
}
