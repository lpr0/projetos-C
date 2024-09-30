#include<stdio.h>
#include<stdlib.h>

int PotDois(int y) {
    if (y == 0) {
        return 1;
    }
    for (int I = 2; I <= y; I= I *2) {
        if (y == I) {
            return 1;
        }
    }
    return 0;
}

int eliminacaoX (int x, int n) {
    if (x <= n / 2) {
        return x * 2;
    }
    return 0;
}

int ganhador(int n) {
    if (PotDois(n)) {
        return 1;
    }
    return 0;
}


int main () {
    int n, x;
    scanf("%d %d", &n, &x);

    printf("%d\n", ganhador(n));
    printf("%d", eliminacaoX(x, n));

    // ele sempre elimina os números pares primeiro (todos eles)
    // 2 (1 eleminado), 4 (2 eliminado), 6 (3 eliminado), ... , 100 (50 eliminado)
    // o ganhador é sempre impar

    // (N = 2k) Ao eliminar os 4k + 1 e os pares só sobra os 4k + 3
    // (N = 2k + 1) Ao eliminar os 4k + 3 e os pares só sobra os 4k + 1

    // N = 1 -> G = 1 ()
    // N = 2 -> G = 1 (elimina os pares)
    // N = 3 -> G = 3 (elimina os pares, elimina os 4k + 1)
    // N = 4 -> G = 1 (elimina os pares, elimina os 4k + 3)
    // N = 5 -> G = 3 (elimina os pares, elimina os 4k + 1)
    // N = 6 -> G = 5 (elimina os pares, elimina os 4k + 3, elimina o 1)
    // N = 7 -> G = 7 (elimina os pares, elimina os 4k + 1, elimina o 3)
    // N = 8 -> G = 1 (elimina os pares, elimina os 4k + 3, elimina o 5)
    // N = 9 -> G = 3 (elimina os pares, elimina os 4k + 1, elimina o 7)
    // N = 10 -> G = 5 (elimina os pares, elimina os 4k + 3, elimina os 8k + 1)
    // N = 16 -> G = 1 (elimina os pares, elimina os 4k + 3, ...)
    // N = 19 -> G = 7 (elimina os pares, elimina os 4k + 1, elimina os 8k + 3, elimina os 16k + 15)
    // N = 20 -> G = 9 (elimina os pares, elimina os 4k + 3, elimina os 8k + 5, eliminar os 16k + 1)
    
    return 0;
}