#include <stdlib.h>
#include <stdio.h>
#include "listaOrdenadaPedida.h"

// Lucas Pereira Rubens

t_ordered_list* create_ordered_list(int max) {
    t_ordered_list* lis = (t_ordered_list*) malloc(sizeof(t_ordered_list));
    lis->n = 0;
    lis->max = max;
    lis->items = (int*) malloc(sizeof(int) * max);
    return lis;
}

int size(t_ordered_list* lis) {
    return lis->n;
}

int is_empty(t_ordered_list* lis) {
    return (lis->n <= 0);
}

int is_full(t_ordered_list* lis) {
    return (lis->n >= lis->max);
}

void destroy(t_ordered_list* lis) {
    free(lis->items);
    free(lis);
}

void clear(t_ordered_list* lis) {
    lis->n = 0;
}

void moverD (t_ordered_list* lis, int ini) {
    for (int I = lis->n; I > ini; I--) {
        lis->items[I] = lis->items[I - 1];
    }
}

void moverE (t_ordered_list* lis, int ini) {
    for (int I = ini; I < lis->n - 1; I++) {
        lis->items[I] = lis->items[I + 1];
    }
}

t_ordered_list* ampliarVetor (t_ordered_list* lis) {
    t_ordered_list* novaLista = create_ordered_list(lis->max + 10);
    for (int I = 0; I < lis->n; I++) {
        novaLista->items[I] = lis->items[I];
    }
    destroy(lis);
    return novaLista;
}

int insert(t_ordered_list* lis, int x) {
    if (is_full(lis)) {
        lis = ampliarVetor(lis);
    }   
    int I;
    for (I = 0; I < lis->n; I++) {
        if (lis->items[I] > x) {
            break;
        }
    }

    moverD(lis, I);
    lis->items[I] = x;
    lis->n++;

    return 1;
}

int search(t_ordered_list* lis, int x) {
    int ini = 0, fim = lis->n;
    for (int mid = (ini + fim) / 2; ini < fim; mid = (ini + fim) / 2) {
        if (lis->items[mid] < x) {
            ini = mid + 1;
        } else if (lis->items[mid] > x) {
            fim = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int remove_by_index(t_ordered_list* lis, int I) {
    if (is_empty(lis)) {
        return 0;
    }
    moverE(lis, I);
    lis->n--;
    return 1;
}

int remove_by_value(t_ordered_list* lis, int x) {
    x = search(lis, x);
    if (x == -1) {
        return 0;
    }
    return remove_by_index(lis, x);
}

int remove_end(t_ordered_list* lis) {
    if (is_empty(lis)) {
        return 0;
    }
    lis->n--;
    return 1;
}

void print_ordered_list(t_ordered_list* lis) {
    for (int I = 0; I < lis->n; I++) {
        printf("%d, ", lis->items[I]);
    }
    printf("\n");
}

t_ordered_list* merge(t_ordered_list* lista1, t_ordered_list* lista2) {
    t_ordered_list* listaM = create_ordered_list(lista1->max + lista2->max);
    
    int L1 = 0, L2 = 0;
    while (listaM->n < (lista1->n + lista2->n)) {
        if (lista1->items[L1] < lista2->items[L2]) {
            listaM->items[listaM->n] = lista1->items[L1];
            L1++;
            if (L1 >= lista1->n) {
                while (L2 < lista2->n) {
                    listaM->n++;
                    listaM->items[listaM->n] = lista2->items[L2];
                    L2++;
                }
            }
        } else {
            listaM->items[listaM->n] = lista2->items[L2];
            L2++;
            if (L2 >= lista2->n) {
                while (L1 < lista1->n) {
                    listaM->n++;
                    listaM->items[listaM->n] = lista1->items[L1];
                    L1++;
                }
            }
        }
        listaM->n++;
    }

    return listaM;
}
