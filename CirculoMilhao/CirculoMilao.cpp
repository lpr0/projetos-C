#include<stdio.h>
#include<stdlib.h>

int PotDois(int y) {
    if (y == 1) {
        return 1;
    }
    int I;
    for (I = 2; (I * 2) <= y; I= I *2) {}
    return I;
}

int eliminacaoX (int x, int n) {
    if (x <= n / 2) {
        return x * 2;
    }
    return 0;
}

int ganhador(int n) {
    int pd = PotDois(n), res;
    res = n - pd;
    return 1 + (res * 2);
}


int main () {
    int n, x;
    scanf("%d %d", &n, &x);

    if (n > 0) {
        printf("Ganhador: %d\n", ganhador(n));
    } else {
        printf("Nao ha ganhador.\n");
    }
    
    printf("Eliminado %d: %d\n",x, eliminacaoX(x, n));

    // ciclo potencias de 2 intervalor entre elas

    // ele sempre elimina os números pares primeiro (todos eles)
    // 2 (1 eleminado), 4 (2 eliminado), 6 (3 eliminado), ... , 100 (50 eliminado)
    // o ganhador é sempre impar

    // N = 1 -> G = 1 
    // N = 2 (2)-> G = 1 
    // N = 3 (2 + 1)-> G = 3 
    // N = 4 (4 + 0)-> G = 1 
    // N = 5 (4 + 1)-> G = 3 
    // N = 6 (4 + 2)-> G = 5 
    // N = 7 (4 + 3)-> G = 7 
    // N = 8 (8 + 0)-> G = 1 
    // N = 9 (8 + 1)-> G = 3 
    // N = 10 (8 + 2)-> G = 5 
    // N = 16 (16 + 0)-> G = 1 
    // N = 19 (16 + 3)-> G = 7 
    // N = 20 (16 + 4)-> G = 9 
    
    return 0;
}
