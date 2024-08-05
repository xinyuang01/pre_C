#include <stdio.h>

#define swap(t, x, y) \
    do { \
        t temp = x; \
        x = y; \
        y = temp; \
    } while (0)

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap: a = %d, b = %d\n", a, b);

    double c = 3.14, d = 2.71;
    printf("Before swap: c = %.2f, d = %.2f\n", c, d);
    swap(double, c, d);
    printf("After swap: c = %.2f, d = %.2f\n", c, d);

    return 0;
}