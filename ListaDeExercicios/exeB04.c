#include<stdio.h>

int main() {
    int x, a;
    float v1, v2;

    scanf("%d %f %f %d", &x, &v1, &v2, &a);

    if (a > x) {
        printf("%.2f", (a * v2));
    } else {
        printf("%.2f", (a * v1));
    }
}