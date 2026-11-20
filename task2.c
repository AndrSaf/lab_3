#include <stdio.h>
#include <stdlib.h>

void run_task(void) {
    int n;
    printf("Введите длину массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка: длина массива должна быть больше 0.\n");
        while (getchar() != '\n');
        return;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return;

    for (int i = 0; i < n; i++) {
        printf("Элемент A[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка ввода элемента.\n");
            while (getchar() != '\n');
            free(arr);
            return;
        }
    }

    printf("Локальные максимумы: ");
    int found = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            printf("%d (индекс %d)  ", arr[i], i);
            found = 1;
        }
    }
    if (!found) printf("отсутствуют");
    printf("\n");

    free(arr);
}

int main(void) {
    int choice;
    while (1) {
        printf("\n==================================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 2 (Лок. максимумы)\n");
        printf("==================================================\n");
        printf("1. Запустить задание\n");
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