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

    int max_len = 1, max_start = 0;
    int curr_len = 1, curr_start = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curr_len++;
            if (curr_len > max_len) {
                max_len = curr_len;
                max_start = curr_start;
            }
        } else {
            curr_len = 1;
            curr_start = i;
        }
    }

    printf("Максимальная строго возрастающая последовательность (длина %d): ", max_len);
    for (int i = max_start; i < max_start + max_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main(void) {
    int choice;
    while (1) {
        printf("\n====================================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 3 (Возраст. участок)\n");
        printf("====================================================\n");
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