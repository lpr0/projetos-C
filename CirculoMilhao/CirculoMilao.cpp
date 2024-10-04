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

float intFloat (int x) {
    float y = x;
    return y;
}

int eliminacaoX (int x, int n) {
    if (x <= n / 2) {
        return x * 2;
    }

    int eli = 1;
    for (int I = ((n - x) * 2) + 1; I < n; I++) {
        if (eli < I) {
            eli += 2;
        } else {
            eli = 1;
        }
    }
    return eli;

    /*
    
    N = 2   -> 2 
    N = 3   -> 2, 1
    N = 4   -> 2, 4, 3
    N = 5   -> 2, 4, 1, 5
    N = 6   -> 2, 4, 6, 3, 1
    N = 7   -> 2, 4, 6, 1, 5, 3
    N = 8   -> 2, 4, 6, 8, 3, 7, 5
    N = 9   -> 2, 4, 6, 8, 1, 5, 9, 7
    N = 10  -> 2, 4, 6, 8, 10, 3, 7, 1, 9
    N = 11  -> 2, 4, 6, 8, 10, 1, 5, 9, 3, 110
    N = 12  -> 2, 4, 6, 8, 10, 12, 3, 7, 11, 5, 1
    N = 13  -> 2, 4, 6, 8, 10, 12, 1, 5, 9, 13, 7, 3
    N = 14  -> 2, 4, 6, 8, 10, 12, 14, 3, 7, 11, 1, 9, 5
    N = 15  -> 2, 4, 6, 8, 10, 12, 14, 1, 5, 9, 13, 3, 11, 7
    N = 16  -> 2, 4, 6, 8, 10, 12, 14, 16, 3, 7, 11, 15, 5, 13, 9

    N = 24 -> 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 3, 7, 11, 15, 19, 23, 5, 13, 21, 9, 1
    */
}

int ganhador(int n) {
    int pd = PotDois(n), res;
    res = n - pd;
    return 1 + (res * 2);
}


int main () {
    int n, x;
    scanf("%d %d", &n, &x);

    if (x > 0 && x < n) {
        printf("Eliminado %d: %d\n",x, eliminacaoX(x, n));
    } else {
        printf("Eliminacao invalida.\n");
    }

    if (n > 0) {
        printf("Ganhador: %d\n", ganhador(n));
    } else {
        printf("Nao ha ganhador.\n");
    }
    
    

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


    /* N = 16 -> G = 1
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
        1 3 5 7 9 11 13 15                      2 4 6 8 10 12 14 16
        1 5 9 13                                3 7 11 15
        1 9                                     5 13
        1                                       9
    */

    /* N = 17 -> G = 3
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
        1 3 5 7 9 11 13 15 17                       2 4 6 8 10 12 14 16
        3 7 11 15                                   1 5 9 13 17
        3 11                                        7 15
        3                                           11
    */

   /* N = 18 -> G = 5
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        1 3 5 7 9 11 13 15 17                           2 4 6 8 10 12 14 16 18
        1 5 9 13 17                                     3 7 11 15
        5 13                                            1 9 17
        5                                               13
    */    
    return 0;
}
