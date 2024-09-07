#include <stdio.h>

int main() {
    int x, y = 0;
    scanf("%d", &x);
    while (x > 0) {
        y = y * 10;
        y = y + (x % 10);
        x = x / 10;
    }
    printf("%d", y);
}
