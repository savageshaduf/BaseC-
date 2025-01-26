#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <cstring>
#include "main.h"
#include "actfile.h"
#include "encrypt.h"
using namespace std;
int count; char filenamein[50];

void Preservation(Specific* List, int count) {
    char but[2];
    while (true) {
        printf("Зашифровать файл? Да - 1, Нет - 0 \n");
        fflush(stdin);
        scanf("%d", &but);
        fflush(stdin);
        if (but[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            system ("cls");
            continue;
        }
        else {
            break;
        }
    }
    switch (but[0]) {
        case 49:
            Encryption(List, count);
            break;
        case 48:
            break;
        default:
            printf("Ошибка ввода");
            system("pause");
            break;
    }
    FILE *file=fopen(filenamein,"w");
    if (!file) {
        printf ("Не удалось сохранить");
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file,"%s;%s;%s;%d;\n",List[i].BrandName,List[i].ModelName,List[i].BodyMat, List[i].Price);
    }
    fclose(file);
    change = 0;
}

void Preservation_New (Specific* List, int count) {
    char f[2], h[2];
    while (true) {
        system("cls");
        printf("Для сохранения в формате txt нажмите '1', в csv - '2'\n");
        fflush(stdin);
        scanf("%s", &f);
        if (f[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            system ("cls");
            continue;
        }
        else {
            break;
        }
    }
    while (true) {
        system("cls");
        printf("Для сохранения в зашифрованном виде нажмите '1', для отказа нажмите - '0'\n");
        fflush(stdin);
        scanf("%s", &h);
        fflush(stdin);
        if (h[1] != 0) {
            printf("Ошибка ввода\n");
            system("pause");
            system ("cls");
            continue;
        }
        else {
            break;
        }
    }
    system ("cls");
    char filename[50];
    switch (f[0]) {
            case 49: {
                printf("Введите имя файла:\n");
                scanf("%s", filename);
                char a1[] = ".txt";
                strcat(filename, a1);
                fflush(stdin);
                break;
            }
            case 50: {
                printf("Введите имя файла:\n");
                scanf("%s", filename);
                char a2[] = ".csv";
                strcat(filename, a2);
                fflush(stdin);
                break;
            }
            default:
                printf("Команда не определена!");
                system("pause");
                break;
    }
    switch (h[0]) {
            case 49:
                Encryption(List, count);
                break;
            case 48:
                break;
            default:
                printf("Ошибка ввода");
                system("pause");
                break;
    }
    FILE *file = fopen(filename, "w");
    switch (f[0]) {
            case 49:
                for (int i = 0; i < count; i++) {
                    fprintf(file, "%s;%s;%s;%d;\n", List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
                }
                break;
            case 50:
                for (int i = 0; i < count; i++) {
                    fprintf(file, "%s;%s;%s;%d;\n", List[i].BrandName, List[i].ModelName, List[i].BodyMat, List[i].Price);
                }
                break;
            }
            fclose(file);
}

    void Reading(Specific *List, int &count) {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        char filename[50], filename1[50];
        int str = 0;
        system ("cls");
        printf("Введите имя файла: \n");
        scanf("%s", filename);
        fflush(stdin);
        for (int i = 0; filename[i] != 0; i++) {
            filename1[i] = filename[i];
        }
        char a[] = ".txt";
        char a1[] = ".csv";
        strcat(filename, a);
        strcat(filename1, a1);
        FILE *file = fopen(filename, "r");
        FILE *file1 = fopen(filename1, "r");
        int readind = 0;
        if ((file == NULL) && (file1 == NULL)) {
            system ("cls");
            printf("Файл не найден.\n");
            system("pause");
        }
        else {
            if (file == NULL) {
                while (!feof(file1)) {
                    fscanf(file1, "%[^;];%[^;];%[^;];%d;\n", List[str].BrandName, List[str].ModelName, List[str].BodyMat,
                           &List[str].Price);
                    str++;
                    readind = 2;
                }
            }
            else {
                if (file1 == NULL) {
                    while (!feof(file)) {
                        fscanf(file, "%[^;];%[^;];%[^;];%d;\n", List[str].BrandName, List[str].ModelName, List[str].BodyMat,
                               &List[str].Price);
                        str++;
                        readind = 1;
                    }
                }
                else {
                    if ((file != NULL) && (file1 != NULL)) {
                        printf("Для открытия файла типа txt - 1, для csv - 2\n");
                        fflush(stdin);
                        int but;
                        scanf("%d", &but);
                        switch (but) {
                            case 1: {
                                while (!feof(file)) {
                                    fscanf(file, "%[^;];%[^;];%[^;];%d;\n", List[str].BrandName, List[str].ModelName,
                                           List[str].BodyMat,
                                           &List[str].Price);
                                    str++;
                                    readind = 1;
                                }
                                break;
                            }
                            case 2: {
                                while (!feof(file1)) {
                                    fscanf(file1, "%[^;];%[^;];%[^;];%d;\n", List[str].BrandName, List[str].ModelName,
                                           List[str].BodyMat,
                                           &List[str].Price);
                                    str++;
                                    readind = 2;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            count = unsigned(str);
            if (List[count-1].Price == 666) {
                ReadEncryption(List, count);
            }
            int maxmem = 10;
            List = (Specific*)malloc(sizeof(Specific) * 10);
            if (count > maxmem) {
                while (maxmem < count) {
                    List = (Specific *) malloc(sizeof(Specific) * 10);
                    maxmem += 10;
                }
            }
            fflush(stdin);
            system("cls");
            fclose(file);
            fclose(file1);
            char filetran [50];
            sscanf(filename, "%[^.]", filetran);
            switch (readind) {
                case 1: strcat(filetran, a); break;
                case 2 : strcat(filetran, a1); break;
            }
            for (int i = 0; i < 50; i++) {
                filenamein[i] = filetran[i];
            }
            }
            system("pause");
        }

