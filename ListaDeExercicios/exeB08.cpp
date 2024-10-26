#include<stdio.h>

int main () {

    int a, b;
    scanf("%d", &b);
    for (int I = 0; I < 2; I++) {
        scanf("%d", &a);
        if (a > b) {
            b = a;
        }
    }
    printf("%d", b);

    return 0;
}
