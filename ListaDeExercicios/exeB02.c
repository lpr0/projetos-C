#include<stdio.h>

int main() {

    int l, v;
    float m, a;

    scanf(" %d %f %f %d", &l, &m, &a, &v);

    if (v > l) {
        printf("%.2f", (m + (a * (v - l))));
    } else {
        printf("0.00");
    }
}