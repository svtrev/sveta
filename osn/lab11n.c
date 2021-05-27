#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Club
{
    char name[32], address[32], theme [32];
    int openHours, openMinutes;
    int closeHours, closeMinutes;
    int karaoke;
};



/* Ввод клуба в список */
void inputClub(struct Club *list)
{

    fflush(stdin);

    printf("Name club: ");
    scanf("%s", list->name);

    printf("Address: ");
    scanf("%s", list->address);

    printf("Theme: ");
    scanf("%s", list->theme);

    printf("Open time and Close time: ");
    scanf("%d%*c%d%d%*c%d", &list->openHours, &list->openMinutes, &list->closeHours, &list->closeMinutes);
    while (((60 * list->closeHours + list->closeMinutes) - (60 * list->openHours + list->openMinutes) < 0) || (list->openHours > 23) ||  (list->closeHours > 23) || (list->openMinutes > 59) || (list->closeMinutes > 59) )
    {
        printf("Время указано неправильно\n");
        printf("Try again!\n");
        printf("Open time and Close time: ");
        scanf("%d%*c%d%d%*c%d", &list->openHours, &list->openMinutes, &list->closeHours, &list->closeMinutes);
    }


    printf("Karaoke? (0 - no, 1 - yes): ");
    scanf("%d", &list->karaoke);
}


/* Вывод списка клубов */
void printList(struct Club *list)
{
    printf("\n-------------------------\n");

    printf("Name club: %s\n", list->name);

    printf("Address: %s\n", list->address);

    printf("Theme: %s\n", list->theme);

    printf("Open time: %02d:%02d\n", list->openHours, list->openMinutes);
    printf("Close time: %02d:%02d\n", list->closeHours, list->closeMinutes);

    printf("Karaoke? ");
    if(list->karaoke == 0)
        printf("No\n");
    else
        printf("Yes\n");
}


/* Самый долгоработающий клуб в списке */
int maxTime(struct Club list[], int n, int mtime)
{
    int i;
    int max = 0;
    int start = 0, end = 0;

    for(i = 0; i < n; i++)
    {
        start = 60 * list[i].openHours + list[i].openMinutes;
        end = 60 * list[i].closeHours + list[i].closeMinutes;
        if(end - start > max)
        {
            max = end - start;
            mtime = i;
        }
    }
    return mtime;
}

void addClubs(struct Club list[])
{
    struct Club h = {"Romashka", "Mira 39", "night club", 17, 0, 19, 0, 0};
    struct Club z  = {"Fialka", "Lenina 21", "restaraunt", 10, 0, 22, 30, 0};
    list[1] = h;
    list[2] = z;
}


int main()
{
    struct Club *list = NULL, temp;
    int i, j, s, key;
    int num, n = 3, mtime = 0;

    list = (struct Club *) malloc(n * sizeof(int));
    if(!list)
    {
        printf("memory allocation error!");
        return -1;
    }

    addClubs(list);

    do
    {
        printf("\nKol-vo clubov in list: %d\n\n", n-1);
        printf("What do you want to do: \n");
        printf("1. Vivesty club list;\n");
        printf("2. Dobavit' club;\n");
        printf("3. Delete club;\n");
        printf("4. Karaoke;\n");
        printf("5. Club, kotoriy dolshe vseh rabotaet;\n");
        printf("6. Exit\n\n");

        scanf("%d", &key);
        switch (key)
        {
            case 1:  /* Вывести список клубов */
                for (i = 0; i < n - 1; i++)
                    printList(&list[i+1]);

                break;

            case 2:  /* Добавить клуб */
                printf("Vvedite info club:\n");

                inputClub(&list[n]);
                list = realloc(list, n+1);
                n++;

                printf("Succes!\n");
                break;

            case 3:  /* Удалить клуб */
                printf("Kakoi club do you want to delete?\n\n");

                if(n < 1)
                {
                    printf("ERROR: there's no club in listn\n");
                    break;
                }

                for (i = 1; i < n; i++)
                {
                    printf("%d - ", i);
                    puts(list[i].name);
                }

                scanf("%d", &num);
                for (i = num-1; i < n-1; i++)
                {
                    for(j = num; j < n; j++)
                    {
                        temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
                n--;
                printf("Success!\n");
                break;

            case 4:  /* Караоке */
                for(i = 0; i < n; i++)
                {
                    if(list[i].karaoke == 1)
                    {
                        printList(&list[i]);
                        s++;
                    }
                }
                if (s == 0)
                    printf ("\nКлубов с караоке нет!\n");

                break;

            case 5:  /* Дольше всех работает */
                printList(&list[maxTime(list, n, mtime)]);
                break;

            case 6:  /* Выход */
                return 0;
                break;

            default:
                printf("Nepravilniy vvod!\n");
                break;
        }
    } while(1);

    return 0;
}
