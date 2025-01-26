#include <iostream>
#include <stdio.h>
#include "main.h"
#include "acttable.h"
#include <windows.h>
using namespace std;
bool change = 0;
eCMD MenuShow()
{
    while(true)
    {
        printf("\n1) Редактирование данных\n");
        printf("2) Добавление записи\n");
        printf("3) Удаление записи\n");
        printf("4) Сортировка данных\n");
        printf("5) Поиск по ключевому слову\n");
        printf("6) Арифметические действия\n");
        printf("7) Выход\n");
        char a[2];
        fflush(stdin);
        scanf("%2s", &a);
        fflush(stdin);
        switch(a[0])
        {
            case 49:
                return CMD_EDIT;
            case 50:
                return CMD_ADD;
            case 51:
                return CMD_DELETE;
            case 52:
                return CMD_SORT;
            case 53:
                return CMD_FIND;
            case 54:
                return CMD_CALC;
            case 55:
                return CMD_EXIT;
            default: printf("Неверная команда!\n"); system ("pause"); return CMD_NONE;
        }
    }
}
void Output(Specific* List, int &count )
{
    eCMD cmd = CMD_NONE;
    while(true)
    {
        system("cls");
        const char* t_BrandName="Бренд";
        const char* t_ModelName="Модель";
        const char* t_BodyMat="Корпус";
        const char* t_Price = "Цена";
        printf("--------------------------------------------\n");
        printf("| № |%9s|%13s|%8s|%5s|\n",t_BrandName,t_ModelName,t_BodyMat, t_Price);
        printf("--------------------------------------------\n");
        for (int i=0; i<count; i++)
        {
            printf("| %-2d|%9s|%13s|%8s|%5d|\n", i + 1, List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
            printf("--------------------------------------------\n");
        }
        cmd = MenuShow();
        if(cmd == CMD_EXIT)
        {
            break;
        }
        switch(cmd)
        {
            case CMD_EDIT:
                Edit(List,count);
                break;
            case CMD_ADD:
                Add(List,count);
                break;
            case CMD_DELETE:
                Delete(List,count);
                break;
            case CMD_SORT:
                Sort(List,count);
                break;
            case CMD_FIND:
                Find(List,count);
                break;
            case CMD_CALC:
                Calc(List,count);
                break;
        }
    }
}

void Find(Specific* List, int &count) {
    system("cls");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char s[40];
    int notfindind = 0;
    system("cls");
    printf ("Введите ключевое слово для поиска:\n");
    scanf ("%s", &s);
    fflush(stdin);
    system ("cls");
    int wordlen = 0, repindex[count], printcount = 0;
    for (int j = 0; j <  count; j++) {
        repindex[j] = 0;
    }
    for (; s[wordlen] != 0; wordlen++);
    for (int i = 0; i < count; i++) {
        int k = 0;
        for (int p = 0; p < wordlen; p++) {
            if (List[i].BrandName[p] == s[p]) {
                k++;
                if (repindex [i] == 1) {
                    continue;
                }
                if (k == wordlen) {
                    if (printcount == 0) {
                        printf("--------------------------------------------\n");
                    }
                    printf("| %-2d|%9s|%13s|%8s|%5d|\n", i + 1, List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
                    printf("--------------------------------------------\n");
                    k = 0;
                    repindex[i] = 1;
                    printcount++;
                }
            }
            else {
                k = 0;
            }
        }
        for (int p = 0; p < wordlen; p++) {
            if (List[i].ModelName[p] == s[p]) {
                k++;
                if (repindex [i] == 1) {
                    continue;
                }
                if (k == wordlen) {
                    if (printcount == 0) {
                        printf("--------------------------------------------\n");
                    }
                    printf("| %-2d|%9s|%13s|%8s|%5d|\n", i + 1, List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
                    printf("--------------------------------------------\n");
                    k = 0;
                    repindex[i] = 1;
                    printcount++;
                }
            }
            else {
                k = 0;
            }
        }
        for (int p = 0; p < wordlen; p++) {
            if (List[i].BodyMat[p] == s[p]) {
                k++;
                if (repindex [i] == 1) {
                    continue;
                }
                if (k == wordlen) {
                    if (printcount == 0) {
                        printf("--------------------------------------------\n");
                    }
                    printf("| %-2d|%9s|%13s|%8s|%5d|\n", i + 1, List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
                    printf("--------------------------------------------\n");
                    k = 0;
                    repindex[i] = 1;
                    printcount++;
                }
            }
            else {
                k = 0;
            }
        }
        for (int i = 0; i < count; i++) {
            if (repindex[i] == 0) notfindind++;
        }
    }
    if ((notfindind) == count) {
        system ("cls");
        printf ("По данному запросу не найдено элементов.\n");
    }
    wordlen = 0;
    system("pause");
    system("cls");
}

void Edit(Specific* List, int &count) {
    char s[2], k [2];
    int s1 = 0;
    Specific y;
    while (true) {
        system("cls");
        printf("Введите номер строки, которую хотите изменить: ");
        scanf("%s", &s);
        fflush(stdin);
        if (s[1] != 0) {
            printf("Ошибка ввода\n");
            system ("pause");
            fflush(stdin);
            continue;
        }
        else {
            fflush(stdin);
        }
        sscanf(s, "%[0-9]", &s1);
        fflush(stdin);
        s1 -= 48;
        break;
    }
    if ((s1 > count) || (s1 < 1)) {
        fflush(stdin);
        printf ("Ошибка ввода\n");
        system ("pause");
        return;
    }
    system("cls");
    printf("-----------------------------------------------------------------------------\n");
    printf("|%9s|%13s|%8s|%5d|\n",List[s1-1].BrandName,List[s1-1].ModelName,List[s1-1].BodyMat,List[s1-1].Price);
    printf("-----------------------------------------------------------------------------\n");
    int k1 = 0;
    while (true) {
        printf("Введите номер столбца, который хотите изменить: ");
        scanf("%s", &k);
        fflush(stdin);
        if (k[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            continue;
        }
        sscanf(k, "%[0-9]", &k1);
        fflush(stdin);
        k1 -= 48;
        break;
    }
    switch (k1) {
        case 1: {
        fflush(stdin);
        printf("Введите бренд: ");
        scanf("%39[^\n]", y.BrandName);
        strcpy(List[s1 - 1].BrandName, y.BrandName);
        change = 1;
        break;
        }
        case 2: {
            fflush(stdin);
            printf("Введите название модели: ");
            scanf("%39[^\n]", y.ModelName);
            strcpy(List[s1 - 1].ModelName, y.ModelName);
            change = 1;
            break;
        }
        case 3: {
            fflush(stdin);
            printf("Введите материал корпуса: ");
            scanf("%39[^\n]", y.BodyMat);
            strcpy(List[s1 - 1].BodyMat, y.BodyMat);
            change = 1;
            break;
        }
                case 4: {
                    fflush(stdin);
                    printf("Введите цену: ");
                    scanf("%d", &y.Price);
                    List[s1 - 1].Price = y.Price;
                    change = 1;
                    break;
                }
                default:
                    printf("Ошибка ввода\n");
                    system("pause");
                    Output(List, count);
            break;
    }
}


void Add(Specific* List, int &count)
{
    system("cls");
    count++;
    List=(Specific*)realloc(List, count*sizeof(Specific));
    fflush(stdin);
    printf("Введите бренд: ");
    scanf("%39[^\n]",List[count-1].BrandName);
    fflush(stdin);
    printf("Введите модель: ");
    scanf("%39[^\n]",List[count-1].ModelName);
    fflush(stdin);
    printf("Введите материал: ");
    scanf("%39[^\n]",List[count-1].BodyMat);
    fflush(stdin);
    printf("Введите цену: ");
    scanf("%d",&List[count-1].Price);
    change = 1;
}

void Delete(Specific* List, int &count)
{
    system("cls");
    const char* t_BrandName="Бренд";
    const char* t_ModelName="Модель";
    const char* t_BodyMat="Корпус";
    const char* t_Price="Цена";

    char s[2];
        printf("------------------------------------------------\n");
        printf("| № |%9s|%13s|%8s|%5s|\n", t_BrandName, t_ModelName, t_BodyMat, t_Price);
        printf("------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("| %-2d|%9s|%13s|%8s|%5d|\n", i + 1, List[i].BrandName, List[i].ModelName, List[i].BodyMat,
                   List[i].Price);
            printf("------------------------------------------------\n");
        }
    while (true) {
        printf("Введите номер строки, которую хотите удалить.(Отмена - 0)\n");
        scanf("%s", &s);
        fflush(stdin);
        if (s[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            system ("cls");
            continue;
        }
        else {
            break;
        }
    }
    int s1 = 0;
    sscanf(s, "%[0-9]", &s1);
    s1 -= 48;
    if (s1 > count) {
        system("cls");
        printf ("Ошибка ввода\n");
        system ("pause");
        Output(List, count);
    }
    s1--;
    count--;
    if(s1>=0){
        for(;s1<count + 1;s1++)
        {
            for (int i = 0; i < 24; i++) {
                List[s1].BrandName[i] = List[s1 + 1].BrandName[i];
                List[s1].ModelName[i] = List[s1 + 1].ModelName[i];
                List[s1].BodyMat[i] = List[s1 + 1].BodyMat[i];
            }
            List[s1].Price=List[s1+1].Price;
        }
        change = 1;
        system("cls");
    }


}

void Calc(Specific* List, int &count) {       // Функция подсчета среднего
    system("cls");
    char but[2];
    while (true) {
        printf("1) Расчет среднего значения\n");
        printf("2) Нахождение максимального \n");
        printf("3) Нахождение минимального\n");
        scanf("%s", &but);
        if (but[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            system("cls");
            continue;
        } else {
            break;
        }
    }
    system("cls");
    switch (but[0]) {
            case 49: {
                int n = 0;
                double Average = 0;
                for (int j = 0; j < count; j++) {
                    Average += List[j].Price;
                    n++;
                }
                printf("Среднее значение цены: ");
                printf("%g\n", Average / n);
                break; }
            case 50: {
                int max = 0;
                for (int i = 0; i < count; i++) {
                    if (List[i].Price > max) max = List[i].Price;
                }
                printf("Максимальное значение цены: ");
                printf("%d\n", max);
                break; }
            case 51: {
                int min = 0;
                for (int i = 0; i < count; i++) {
                    if (List[i].Price > min) min = List[i].Price;
                }
                for (int i = 0; i < count; i++) {
                    if (List[i].Price < min) min = List[i].Price;
                }
                printf("Минимальное значение цены: ");
                printf("%d\n", min);
                break; }
            default:
                printf ("Введена неверная команда\n");
                break;

    }
    system("pause");
}


    void Sort(Specific *List, int &count)        // Функция сортировки
    {
        system("cls");
        char g[2];
        char f[2];
        while (true) {
            printf("Введите номер столбца, который хотите сортировать(1-4): ");
            scanf("%s", &g);
            fflush(stdin);
            if (g[1] != 0) {
                printf("Ошибка ввода\n");
                system("pause");
                system("cls");
                continue;
            } else {
                break;
            }
        }
        fflush(stdin);
        while (true) {
            printf("Для сортировки по возрастанию введите '1', по убыванию - '2'\n");
            scanf("%s", &f);
            fflush(stdin);
            if (f[1] != 0) {
                printf("Ошибка ввода\n");
                system("pause");
                system("cls");
                continue;
            } else {
                break;
            }
        }
        if ((f[0] != 49) && (f[0] != 50)) {
            system("cls");
            printf ("Неверная команда!\n");
            system ("pause");
            Output(List, count);
        }
        fflush(stdin);
        int g1 = 0;
        sscanf (g, "%[0-9]", &g1);
        g1 -= 48;
        printf ("%d", g1);
        if (g1 > 0 && g1 < 5) {
            int i, j;
            Specific tmp;
            for (i = 0; i < count - 1; ++i) {
                for (j = 0; j < count - 1; ++j) {
                    if (f[0] == '1') {
                        switch (g1) {
                            case 1:
                                if (List[j].BrandName[0] > List[j + 1].BrandName[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 2:
                                if (List[j].ModelName[0] > List[j + 1].ModelName[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 3:
                                if (List[j].BodyMat[0] > List[j + 1].BodyMat[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 4:
                                if (List[j].Price > List[j + 1].Price) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;

                        }
                    } else if (f[0] == '2') {
                        switch (g1) {
                            case 1:
                                if (List[j].BrandName[0] < List[j + 1].BrandName[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 2:
                                if (List[j].ModelName[0] < List[j + 1].ModelName[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 3:
                                if (List[j].BodyMat[0] < List[j + 1].BodyMat[0]) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                            case 4:
                                if (List[j].Price < List[j + 1].Price) {
                                    tmp = List[j + 1];
                                    List[j + 1] = List[j];
                                    List[j] = tmp;
                                }
                                break;
                        }
                    }
                }

            }
        }
        else {
            printf("Неверный номер столбца\n");
            system ("pause");
        }
        change = 1;
    }

    void Create(Specific* List, int &count) {
        for (int j = 0; j < count; j++) {
            for (int i = 0; i < 24; i++) {
                List[j].BrandName[i] = 0;
                List[j].ModelName[i] = 0;
                List[j].BodyMat[i] = 0;
            }
            List[j].Price= 0;
        }
        count = 0;
    while (true) {
            system("cls");
            count++; int but = -1;
            List=(Specific*)realloc(List, count*sizeof(Specific));
            fflush(stdin);
            printf("Введите бренд: ");
            scanf("%39[^\n]",List[count-1].BrandName);
            fflush(stdin);
            printf("Введите модель: ");
            scanf("%39[^\n]",List[count-1].ModelName);
            fflush(stdin);
            printf("Введите материал: ");
            scanf("%39[^\n]",List[count-1].BodyMat);
            fflush(stdin);
            printf("Введите цену: ");
            scanf("%d",&List[count-1].Price);
            fflush(stdin);
            change = 1;
            system ("cls");
            while ((but != 1)&&(but != 0)) {
                printf("Продолжить? 1 - Да, 0 - Нет\n");
                scanf("%d", &but);
                fflush(stdin);
                if (but == 1) {
                    continue;
                }
                if (but == 0) {
                    return;
                }
                if ((but != 1)&&(but != 0)) {
                    printf("Ошибка ввода\n");
                    system("pause");
                }
            }
        }
    }

