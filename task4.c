#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reverse_number(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

void run_task(void) {
    int A[30];
    srand((unsigned int)time(NULL));

    printf("Исходный массив A[30]:\n");
    for (int i = 0; i < 30; i++) {
        A[i] = 10 + rand() % (99999 - 10 + 1);
        printf("%6d ", A[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    printf("\nМассив после переворота цифр:\n");
    for (int i = 0; i < 30; i++) {
        A[i] = reverse_number(A[i]);
        printf("%6d ", A[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("\n===================================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 4 (Переворот чисел)\n");
        printf("===================================================\n");
        printf("1. Сгенерировать и обработать массив\n");
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