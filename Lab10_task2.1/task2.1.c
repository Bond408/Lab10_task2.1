#include <locale.h>
#include <stdio.h>
#include <math.h>
double sin_n(double x, int N) {
    double sum = 0;
    double element = x;
    int sign = 1;
    for (int k = 1; k <= N; k++) {
        sum += sign * element;
        element *= x * x / (2 * k * (2 * k + 1));
        sign = -sign;
    }
    return sum;
}

double sin_eps(double x, double eps) {
    double sum = 0;
    double element = x;
    int sign = 1;
    int k = 1;

    while (fabs(element) > eps) {
        sum += sign * element;
        element *= x * x / (2 * k * (2 * k + 1));
        sign = -sign;
        k++;
    }
    return sum;
}
int main() {
    setlocale(LC_ALL, "RUS");
    double x, eps;
    int N, max_N;
    printf("¬ведите значение x: ");
    scanf_s("%lf", &x);
    printf("¬ведите максимальное количество членов N: ");
    scanf_s("%d", &max_N);
    printf("¬ведите количество членов N: ");
    scanf_s("%d", &N);
    printf("¬ведите eps: ");
    scanf_s("%lf", &eps);

    double sin_x = sin(x);
    double sin_macloren = sin_n(x, N);
    double sin_eps1 = sin_eps(x, eps);

    printf("\nN |   sin_N   | ќтклонение\n");
    printf("--+-----------+-----------\n");
    for (int N = 1; N <= max_N; N++) {
        double sin_maclaurin = sin_n(x, N);
        double deviation = fabs(sin_x - sin_maclaurin);
        printf("%2d | %9.4lf | %+.4e\n", N, sin_maclaurin, deviation);
    }
}