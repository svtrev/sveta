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


/* ���� ����� � ������ */
void inputClub(struct Club *list)
{
    fflush(stdin);
    printf("Name club: ");
    scanf("%s", list->name);

    printf("Address: ");
    scanf("%s", list->address);

    printf("Theme: ");
    scanf("%s", list->theme);

    while(1)
    {
        printf("Open time and Close time: ");
        fflush(stdin);
        scanf("%d%*c%d%d%*c%d", &list->openHours, &list->openMinutes, &list->closeHours, &list->closeMinutes);
        int start = 60 * list->openHours + list->openMinutes;
        int end = 60 * list->closeHours + list->closeMinutes;

        if (list->openHours > 24 || list->closeHours > 24)
            printf("Error! try again\n");

        else if(list->openMinutes > 59 || list->closeMinutes > 59)
            printf("Error! try again\n");
        else if(end - start <= 0)
            printf("Error! try again\n");
        else
            break;
    }

    printf("Karaoke? (0 - no, 1 - yes): ");
    scanf("%d", &list->karaoke);
}


/* ����� ������ ������ */
void printList(struct Club *list)
{
    printf("Name club: ");
    puts(list->name);

    printf("Address: ");
    puts(list->address);

    printf("Theme: ");
    puts(list->theme);

    printf("Open time: %02d:%02d\n", list->openHours, list->openMinutes);
    printf("Close time: %02d:%02d\n", list->closeHours, list->closeMinutes);

    printf("Karaoke? ");
    if(list->karaoke == 0)
        printf("No\n");
    else
        printf("Yes\n");
    printf("------------------------\n");
}


/* ����� ��������������� ���� � ������ */
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


void addClub(struct Club list[])
{
    struct Club fisrt = {"Romashka", "Mira", "night", 17, 0, 19, 0, 0};
    struct Club second = {"Fialka", "Lenina", "restaraunt", 10, 0, 22, 30, 0};
    struct Club third = {"Fenechka", "Dorozhkina", "time", 8, 0, 17, 30, 1};

    list[0] = fisrt;
    list[1] = second;
    list[2] = third;
}


/* ���������� ����� */
void saveFile(struct Club list[], int n)
{
   FILE *file;
   file = fopen("clubs.txt", "w");
   if(!file)
   {
      fprintf(stderr, "Save error.\n");
      return;
   }

   int i;
   fprintf(file, "%d\n", n);
   for (i = 0; i < n; i++)
      fprintf(file, "%s %s %s %d %d %d %d %d\n",
         list[i].name, list[i].address, list[i].theme,
         list[i].openHours, list[i].openMinutes, list[i].closeHours, list[i].closeMinutes, list[i].karaoke);
   printf("Save succesful!\n");

   fclose(file);
}


/* �������� ����� */
void loadFile(struct Club **list, int *n)
{
   FILE *file;
   file = fopen("clubs.txt", "r");
   if(!file)
   {
      fprintf(stderr, "Load error.\n");
      return;
   }


   int i;
   fscanf(file, "%d", n);
   *list = malloc(*n*sizeof(struct Club));
   for (i = 0; i < *n; i++)
   {
      if (fscanf(file, "%s%s%s%d%d%d%d%d",
            (*list)[i].name, (*list)[i].address, (*list)[i].theme,
            &(*list)[i].openHours, &(*list)[i].openMinutes, &(*list)[i].closeHours, &(*list)[i].closeMinutes, &(*list)[i].karaoke) != 8)
            break;
   }

   printf("Load succesful!\n");
   fclose(file);
}


int main()
{
    struct Club *list = NULL, temp;
    int i, j, key;
    int num, n = 0, mtime = 0;
    loadFile(&list, &n);
    if(!list)
    {
        n = 3;
        list = (struct Club *) malloc(n* sizeof(struct Club));
        if(!list)
        {
            printf("Not enough memory!\n");
            return 1;
        }
        addClub(list);
    }

    do
    {
        printf("Kol-vo clubov in list: %d\n\n", n);
        printf("What do you want to do: \n");
        printf("1. Vivesty club list;\n");
        printf("2. Dobavit' club;\n");
        printf("3. Delete club;\n");
        printf("4. Karaoke;\n");
        printf("5. Club, kotoriy dolshe vsex rabotaet;\n");
        printf("6. Exit\n");

        scanf("%d", &key);
        switch (key)
        {
            case 1:  /* ������� ������ ������ */
                for (i = 0; i < n; i++)
                    printList(&list[i]);
                break;

            case 2:  /* �������� ���� */
                printf("Vvedite info club:\n");

                list = (struct Club*) realloc(list, (n+1)*sizeof(struct Club));
                inputClub(&list[n]);
                n++;

                printf("Succes!\n");
                break;

            case 3:  /* ������� ���� */
                printf("Kakoy club do you want to delete?\n\n");

                if(n < 1)
                {
                    printf("ERROR: there's no club in listn\n");
                    break;
                }

                for (i = 0; i < n; i++)
                {
                    printf("%d - ", i+1);
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
                printf("Succes!");
                break;

            case 4:  /* ������� */
                for(i = 0; i < n; i++)
                    if(list[i].karaoke == 1)
                        printList(&list[i]);
                break;

            case 5:  /* ������ ���� �������� */
                printList(&list[maxTime(list, n, mtime)]);
                break;

            case 6:  /* ����� */
                saveFile(list, n);
                free(list);
                list = NULL;
                n = 0;
                return 0;
                break;

            default:
                printf("Nepravilniy vvod!\n");
                break;
        }
    } while(1);

    return 0;
}
