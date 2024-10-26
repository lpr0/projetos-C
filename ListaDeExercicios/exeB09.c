#include<stdio.h>

void troca (int* x, int* y) {
    int w = *x;
    *x = *y;
    *y = w;
}

int main () {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x > y) {
        troca(&x, &y);
    }
    if (y > z) {
        troca(&y, &z);
    }
    if (x > y) {
        troca(&x, &y);
    }
    printf("%d %d %d", x, y, z);
    return 0;
}