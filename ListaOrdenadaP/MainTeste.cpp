#include <stdlib.h>
#include <stdio.h>
#include "listaOrdenadaPedida.h"

int main () {

    t_ordered_list* lista = create_ordered_list(10);

    for (int I = 0; I < lista->max; I++) {
        insert(lista, lista->max - I);
    }

    print_ordered_list(lista);
    

    remove_by_value(lista, 7);

    print_ordered_list(lista);

    printf("%d \n", size(lista));


    return 0;
}