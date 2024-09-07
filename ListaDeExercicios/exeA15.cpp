#include <stdio.h>

int main() {
    int E, B, N, V;
    float e, b, n, v;
    scanf("%d %d %d %d", &E, &B, &N, &V);
    b = (float) B / E * 100;
    n = (float) N / E * 100;
    v = (float) V / E * 100;
    e = 100 - (b + n + v);
    printf("Nulos %.2f%% \nBrancos %.2f%% \nValidos %.2f%% \nAusentes %.2f%% \n", n, b, v, e);
}
