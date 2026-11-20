#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void run_task(void) {
    char str[512];
    while (getchar() != '\n');
    printf("Введите строку: ");
    if (!fgets(str, sizeof(str), stdin)) return;
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("Пустая строка.\n");
        return;
    }

    if (isalpha((unsigned char)str[0])) {
        srand((unsigned int)time(NULL));
        int shift = 1 + rand() % 9;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'A' + (str[i] - 'A' + shift) % 26;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = 'a' + (str[i] - 'a' + shift) % 26;
            }
        }
        printf("Зашифрованная строка: %s\n", str);
        printf("Ключ (сдвиг):         %d\n", shift);
    } else if (isdigit((unsigned char)str[0])) {
        int shift = str[0] - '0';
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'A' + (str[i] - 'A' - shift + 26) % 26;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = 'a' + (str[i] - 'a' - shift + 26) % 26;
            }
        }
        printf("Расшифрованная строка (ключ %d): %s\n", shift, str);
    } else {
        printf("Ошибка: строка должна начинаться с латинской буквы или цифры.\n");
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\n==============================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 5 (Шифр Цезаря)\n");
        printf("==============================================\n");
        printf("1. Зашифровать / расшифровать строку\n");
        printf("0. Выход\n");
        printf("Выберите пункт: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода.\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice == 0) break;
        if (choice == 1) run_task();
        else printf("Неверный пункт меню.\n");
    }
    return 0;
}