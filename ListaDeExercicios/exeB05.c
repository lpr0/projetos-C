#include<stdio.h>

int main() {
    int ano;
    scanf("%d", &ano);
    if (ano < 0) {
        printf("-1");
        return 0;
    }
    if ((ano % 4) == 0) {
        if (ano % 400 == 0) {
            printf("1");
        } else if (ano % 100 == 0) {
            printf("0");
        } else {
            printf("1");
        }
        return 0;
    }
    printf("0");
    return 0;
}