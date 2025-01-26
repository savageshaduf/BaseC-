#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include "actfile.h"
#include "acttable.h"
#include "encrypt.h"
Specific* List=new Specific[10*sizeof(Specific)];
eCMD Menu()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while(true) {
        system("cls");
        system("color F0");
        printf("1) Открыть файл\n");
        printf("2) Вывести таблицу\n");
        printf("3) Ввести свои данные\n");
        printf("4) Запись в файл\n");
        printf("5) Запись в новый файл\n");
        printf("6) Выход\n");
        char a[2];
        fflush(stdin);
        scanf("%2s", &a);
        if (a[1] != 0) {
            fflush(stdin);
            printf("Команда не определена\n");
            system("pause");
        } else {
            switch (a[0]) {
                case 49:
                    return CMD_READ;
                case 50:
                    return CMD_SHOW;
                case 51:
                    return CMD_CREATE;
                case 52:
                    return CMD_SAVE;
                case 53:
                    return CMD_SAVE_NEW;
                case 54:
                    return CMD_EXIT;
                default:
                    printf("Команда не определена\n");
                    system("pause");
            }
        }
    }
}
int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    for (int i = 0; i < 9; i++) {
        filenamein[i] = argv[1][i];
    }
    FILE* mainfile = fopen(filenamein, "r");
    eCMD cmd = CMD_NONE;
    int str = 0;
    while (!feof(mainfile)) {
        fscanf(mainfile, "%[^;];%[^;];%[^;];%d;\n", List[str].BrandName, List[str].ModelName, List[str].BodyMat,
               &List[str].Price);
        str++;
    }
        count = unsigned(str);
    if (List[count-1].Price == 666) {
        ReadEncryption(List, count);
    }
            while (true) {
                cmd = Menu();
                if (cmd == CMD_EXIT) {
                    char t[2];
                    if (change == true) {
                        while (true) {
                            system ("cls");
                            printf("Файл был изменен. Сохранить изменения? Да - 1, Нет - 0.\n");
                            fflush(stdin);
                            scanf("%s", &t);
                            if (t[1] != 0) {
                                fflush(stdin);
                                printf("Команда не определена\n");
                                system("pause");
                                continue;
                            }
                            else {
                                break;
                            }
                        }
                            fflush(stdin);
                            if (t[0] == '1') {
                                Preservation(List, count);
                                delete[] List;
                                printf("Файл был сохранен\n");
                                system("pause");
                                return 0;
                            } else if (t[0] == '0') {
                                delete[] List;
                                printf("Работа завершена \n");
                                system("pause");
                                return 0;
                            }
                         else {
                                delete[] List;
                                printf("Работа завершена \n");
                                system("pause");
                                return 0;
                            }
                        }
                    }
                switch (cmd) {
                    case CMD_SHOW:
                        Output(List, count);
                        break;
                    case CMD_READ:
                        Reading(List, count);
                        break;
                    case CMD_SAVE:
                        Preservation(List, count);
                        break;
                    case CMD_SAVE_NEW:
                        Preservation_New(List, count);
                        break;
                    case CMD_CREATE:
                        Create(List, count);
                        break;
                }
            }
        }