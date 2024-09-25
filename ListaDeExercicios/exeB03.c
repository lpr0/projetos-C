#include<stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x > 15 && x < 71) {
        if (x > 17) {
            printf("Obrigatoio\n");
        } else {
            printf("Facultativo\n");
        }
    } else {
        printf("Dispensado\n");
    }
}
