#include <stdio.h>

int main() {
    float L, A, C, R;
    scanf("%f %f %f %f", &L, &A, &C, &R);
    A = L * A;
    R = A / R;
    L = R - (int) R;
    R = R - L;
    if (L != 0) {
        R++;
    }
    C = C * R;
    printf("%.2f Latas \nCusto: %.2f \n", R, C);
}
