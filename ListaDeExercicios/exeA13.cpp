#include <stdio.h>

int main() {
    int s, m, h, d;
    scanf("%d", &s);
    m = s / 60;
    s = s % 60;
    h = m / 60;
    m = m % 60;
    d = h / 24;
    h = h % 24;
    printf("Dias %d \nHoras %d \nMinutos %d \nSegundos %d", d, h, m, s);
}