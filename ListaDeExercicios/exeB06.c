#include<stdio.h>
#include<math.h>

int main (){
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    float soma = -b  / a;
    float delta = (b * b) - (4 * a * c);

    if (delta >= 0) {
        printf("%.2f", soma);
    } else {
        printf("MAN");
    }
    return 0;
}
