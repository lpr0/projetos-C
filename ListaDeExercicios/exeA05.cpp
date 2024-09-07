#include <stdio.h>

int main () {
    int x, y;
    scanf("%d %d", &x, &y);

    int z = x / y;
    printf("%.2f \n", (float) x / y);
    printf("%d \n", z);
    printf("%d \n", (x - (y * z)));
}
