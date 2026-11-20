#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

void run_task(void) {
    double eps;
    printf("Введите точность расчетов (например, 0.0001): ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("Ошибка: точность должна быть положительным числом.\n");
        while (getchar() != '\n');
        return;
    }

    int n = 2;
    double pi_prev = 0.0, pi_curr = 0.0;
    double h = 0.0;

    do {
        pi_prev = pi_curr;
        h = 1.0 / n;
        double sum = f(0.0) + f(1.0);
        for (int i = 1; i < n; i++) {
            sum += 2.0 * f(i * h);
        }
        pi_curr = 2.0 * h * sum;
        n *= 2;
    } while (fabs(pi_curr - pi_prev) > eps && n < 10000000);

    printf("Подобранный шаг h: %.10f\n", h);
    printf("Вычисленное Pi:    %.10f\n", pi_curr);
    printf("Константа M_PI:    %.10f\n", M_PI);
    printf("Погрешность:       %.10f\n", fabs(pi_curr - M_PI));
}

int main(void) {
    int choice;
    while (1) {
        printf("\n==========================================\n");
        printf("Студент: Сафонов Андрей | Группа: ИТПМ-126\n");
        printf("Лабораторная работа №3 | Задание 1 (Число Pi)\n");
        printf("==========================================\n");
        printf("1. Запустить вычисление\n");
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