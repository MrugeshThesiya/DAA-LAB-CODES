#include <stdio.h>

int Power(int x, int y) {
    if (y == 0)
        return 1;

    int temp = Power(x, y / 2);

    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main() {
    int x, y;
    printf("Enter the base and exponent: ");
    scanf("%d %d", &x, &y);

    int res = Power(x, y);
    printf("Result: %d\n", res);

    return 0;
}
