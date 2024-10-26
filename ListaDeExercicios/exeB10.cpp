#include<stdio.h>


int main () {
    float x[3];
    scanf("%f %f %f", &x[0], &x[1], &x[2]);
    if ((x[0] + x[1]) > x[2] && (x[0] + x[2]) > x[1] && (x[2] + x[1]) > x[0]) {
        if (x[0] == x[1] || x[1] == x[2] || x[0] == x[2]) {
            if (x[0] == x[1] && x[1] == x[2]) {
                printf("Equilatero");
            } else {
                printf("Isoceles");
            }
        } else {
            printf("Escaleno");
        }
    } else {
        printf("Nao forma triangulo");
    }

    return 0;
}
