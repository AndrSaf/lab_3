#include <stdio.h>
#include <string.h>

void run_task(void) {
    char str[512];
    while (getchar() != '\n');
    printf("Введите строку со словами, разделенными пробелами: ");
    if (!fgets(str, sizeof(str), stdin)) return;
    str[strcspn(str, "\n")] = '\0';

    int len = (int)strlen(str);
    printf("Слова по возрастанию длины:\n");

    for (int target_len = 1; target_len <= len; target_len++) {
        int i = 0;
        while (i < len) {
            while (i < len && str[i] == ' ') i++;
            int start = i;
            while (i < len && str[i] != ' ') i++;
            int word_len = i - start;

            if (word_len == target_len) {
                for (int k = start; k < i; k++) {
                    putchar(str[k]);
                }
                putchar('\n');
            }
        }
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\n======================================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 6 (Сортировка слов)\n");
        printf("======================================================\n");
        printf("1. Ввести строку и вывести слова\n");
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