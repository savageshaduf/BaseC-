#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "encrypt.h"
void Encryption(Specific* List, int &count ) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 24; j++) {
            if (List[i].BrandName[j] != 0) {
                List[i].BrandName[j] += 1;
            }
            if (List[i].ModelName[j] != 0) {
                List[i].ModelName[j] += 1;
            }
            if (List[i].BodyMat[j] != 0) {
                List[i].BodyMat[j] += 1;
            }
        }
        int thous, hund, ten, one;
        thous = List[i].Price / 1000;
        hund = (List[i].Price - thous * 1000) / 100;
        ten = (List[i].Price % 100) / 10;
        one = List[i].Price % 10;
        List[i].Price = (thous + 1) * 1000 + (hund + 1) * 100 + (ten + 1) * 100 + (one + 1);
    }
    count++;
    char flag[] = "Encrypted";
    for (int i = 0; i < 24; i++) {
        List[count-1].BrandName[i] = flag[i];
    }
    for (int i = 0; i < 24; i++) {
        List[count-1].ModelName[i] = flag[i];
    }
    for (int i = 0; i < 24; i++) {
        List[count-1].BodyMat[i] = flag[i];
    }
    List[count - 1].Price = 666;
}
void ReadEncryption(Specific* List, int &count) {
    for (int i = 0; i < 24; i++) {
        List[count - 1].BrandName[i] = List[count].BrandName[i];
        List[count - 1].ModelName[i] = List[count].ModelName[i];
        List[count - 1].BodyMat[i] = List[count].BodyMat[i];
    }
    List[count-1].Price=List[count].Price;
    count--;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 24; j++) {
            if (List[i].BrandName[j] != 0) {
                List[i].BrandName[j] -= 1;
            }
            if (List[i].ModelName[j] != 0) {
                List[i].ModelName[j] -= 1;
            }
            if (List[i].BodyMat[j] != 0) {
                List[i].BodyMat[j] -= 1;
            }
        }
        int thous, hund, ten, one;
        thous = List[i].Price / 1000;
        hund = (List[i].Price - thous * 1000) / 100;
        ten = (List[i].Price % 100) / 10;
        one = List[i].Price % 10;
        List[i].Price = (thous - 1) * 1000 + (hund - 1) * 100 + (ten - 1) * 100 + (one - 1);
    }
}