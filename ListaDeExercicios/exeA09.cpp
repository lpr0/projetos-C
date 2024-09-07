#include <stdio.h>
#include <math.h>

int main () {
    float a, b, c, D;
    scanf("%f %f %f", &a, &b, &c);
    D = (b * b) - (4 * a * c);
    if (D > 0) {
        printf("%.2f \n", ((-b + sqrt(D)) / (2 * a)));
        printf("%.2f \n", ((-b - sqrt(D)) / (2 * a)));
    } else if (D < 0) {
        printf("Raiz não real");
    } else {
        printf("%.2f \n", ((-b / (2 * a))));
    }
}
