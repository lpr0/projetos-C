#include <stdio.h>
#include <math.h>


int main () {
    float x, y;
    scanf("%f %f", &x, &y);
    printf("%.2f", sqrt((x * x) + (y * y)));
}
