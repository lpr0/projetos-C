#include<stdio.h>

int main() {
    float x, y;
    scanf("%f %f", &x, &y);
    if (x > y) {
        float z = x;
        x = y;
        y = z;
    }
    printf("%.4f, %.4f", x, y);
    return 0;
}
