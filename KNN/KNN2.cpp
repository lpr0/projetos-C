#include <stdlib.h>
#include <stdio.h>


typedef struct {
    float sl, sw, pl, pw;
    char* especie;
    float distancia;
} flor;

flor* CriarFlor (float* vet, char* esp) {
    flor* F = (flor*) malloc(sizeof(flor));
    F->sl = vet[0];
    F->sw = vet[1];
    F->pl = vet[2];
    F->pw = vet[3];
    F->especie = esp;

    return F;
}

// calcula a distância de F2 a F1
void calcularDistancia (flor* F1, flor* F2) {
    float dis = 0;
    for (int I = 0; I < 4; I++) {
        dis += (*((float*) F2 + I) - *((float*) F1 + I)) * (*((float*) F2 + I) - *((float*) F1 + I));
    }
    F2->distancia = dis;
}

void troca(flor** vet, int X, int Y) {
    flor* Z = vet[X];
    vet[X] = vet[Y];
    vet[Y] = Z;
}

void particao (int* pilha, int* size, flor** vet, int ini, int fim) {
    int piv = (ini + fim) / 2;
    int I = ini, F = fim;

    int cont = 0;
    while (ini < fim) {
        if (cont > 1) {
            troca(vet, ini, fim);
            if (ini == piv) {
                piv = fim;
            } else if (fim == piv) {
                piv = ini;
            }
            cont = 0;
        }

        if (cont) {
            if (fim == piv || vet[fim]->distancia < vet[piv]->distancia) {
                cont++;
            } else {
                fim--;
            }
        } else {
            if (ini == piv || vet[ini]->distancia > vet[piv]->distancia) {
                cont++;
            } else {
                ini++;
            }
        }
    }

    if (I < F) {
        pilha[*size] = I;
        pilha[*size + 1] = piv;
        pilha[*size + 2] = piv + 1; 
        pilha[*size + 3] = F;
        *size = *size + 4;
    }   
}

void Quirk(flor** vet, int size) {
    int pilha[size];
    int sizeP = 0;

    pilha[0] = 0;
    pilha[1] = size -1;
    sizeP = 2;

    if (size < 2) {
        sizeP = 0;
    }

    while (sizeP != 0) {
        int ini = pilha[sizeP - 2], fim = pilha[sizeP - 1];
        sizeP = sizeP - 2;
        particao(pilha, &sizeP, vet, ini, fim);
    }
}

int ComapararSTR (char* vet, int idx, char* str) {
    int I = 0;
    while (1) {
        if (vet[I + 4 + (idx * (4 + 32))] != str[I]) {
            return -1;
        }
        if (vet[I + 4 + (idx * (4 + 32))] == '\0') {
            break;
        }
        I++;
    }
    return I; 
}

void copiarSTR (char* str1, char* str2) {
    int I = 0;
    while (1) {
        str2[I] = str1[I];
        if (str1[I] == '\0') {
            break;
        }
        I++;
    }
}


char* Classificar(flor** memoria, int sizeM) {
    char espe[7 * (4 + 32)];
    int size = 0;
    for (int I = 0; I < 7 && I < sizeM; I++) {
        if (memoria[I]->distancia == 0) {
            char* res = (char*) malloc(sizeof(char) * 32);
            copiarSTR(memoria[I]->especie, res);
            return res;
        }

        // checar se a especie já está no vetor;
        if (size > 0) {
            for (int II = 0; II < size; II++) {
                int indx = ComapararSTR(espe, II, memoria[I]->especie);
                if (indx != -1) {
                    // Se sim atualizar o valor int em 1 / distância;
                    *((float*)(espe + (indx * (4 + 32)))) += 1 / memoria[I]->distancia;
                    break;
                } else if (II + 1 >= size) {
                    // se não adicionar uma nova especie ao vetor;
                    *((float*)(espe + (size * (4 + 32)))) = 1 / memoria[I]->distancia;
                    copiarSTR(memoria[I]->especie,  (espe + 4 + (size * (4 + 32))));
                    size++;
                }
            }
        } else {
            *((float*)(espe + (size * (4 + 32)))) = 1 / memoria[I]->distancia;
            copiarSTR(memoria[I]->especie,  (espe + 4 + (size * (4 + 32))));
            size++;
        }
    }
    
    char* resultado;
    int peso = -1;
    // pega o maior valor
    printf("\n%d\n", size);
    for (int I = 0; I < size; I++) {
        printf("%s, ", (espe + 4 + (I * (4 + 32))));
        if (*((float*)(espe + (I * (4 + 32)))) > peso) {
            resultado = (espe + 4 + (I * (4 + 32)));
        }
    }

    char* res = (char*) malloc(sizeof(char) * 32);
    copiarSTR(resultado, res);
    return res;
}


void TratarFgets (char* vet) {
    int I = 0;
    while (vet[I] != '\0') {
        if (vet[I] == '\n') {
            vet[I] = '\0';
            break;
        }
        I++;
    }
}

int virgulas (char* vet, int ini) {
    for (int I = ini; I < 64; I++) {
        if (vet[I] == ',' || vet[I] == '\0') {
            return I;
        }
    }
}

float strFloat (char* str,  int ini, int fim) {    
    float N = 0;
    int number = 0, racional = 0;;
    for (int I = ini; I < fim; I++) {
        if (str[I] > 47 && str[I] < 58) {
            N = (N * 10) + (str[I] - 48);
            number = 1;
            if (racional) {
                racional++;
            }
        } else if (str[I] == '.') {
            racional = 1;
        }
    }
    while (racional > 1) {
        N = N / 10;
        racional--;
    }
    if (number) {
        return N;
    }
    return NULL;
}

// divide a str1 em duas partes uma metade fica na str1 e outra na str2
void cortar (char* str1, char* str2, int x) {
    int I = 0, II = 0;
    while (str1[I] != '\0') {
        if (I >= x) {
            if (I == x) {
                str1[I] = '\0';
            } else {
                str2[II] = str1[I];
                II++;
            }
        }   
        I++;
    }
    str2[II] = '\0';
}

flor* lerDados(char* dados) {
    float vet[4];

    int V = 0;
    for (int I = 0; I < 4; I++) {
        int V2 = virgulas(dados, V);
        vet[I] = strFloat(dados, V, V2);
        V = V2 + 1;
    }

    char* esp = (char*) malloc(sizeof(char) * 32);
    cortar(dados, esp, V - 1);

    flor* F = CriarFlor(vet, esp);
    return F;
}


// 1 == dados lidos; 0 == nenhum dado lido
int CarregarDados (char* arquivo, flor** memoria, int* sizeM) {
    FILE* arq = fopen(arquivo, "r");

    char teste[64];
    char* res;

    res = fgets(teste, 64, arq);

    res = fgets(teste, 64, arq);
    TratarFgets(teste);

    int C = 0;
    while (res != NULL) {
        memoria[*sizeM] = lerDados(teste);
        *sizeM += 1;
        
        C = 1;

        res = fgets(teste, 64, arq);
        TratarFgets(teste);
    }

    fclose(arq);
    return C;
}


void freeMemoria(flor** memoria, int size) {
    size = size - 1;
    while (size > -1) {
        //free(memoria[size]->especie);
        free(memoria[size]);
        size = size - 1;
    }
    free(memoria);
}

void resolveProblema (flor** entradas, flor** memoria, int sizeM, int I) {
    // Alterar a especia da entrada;

    // Calcular a distância de todos os pontos da memória ao ponto da entrada;
    for (int II = 0; II < sizeM; II++) {
        calcularDistancia(entradas[I], memoria[II]);
    }

    // Ordernar o vetor da memória da menor para a maior distância;
    Quirk(memoria, sizeM);

    // Calcular a especie da entrada, 7 pontos mais proximos inversamente proporcional à distância;
    free(entradas[I]->especie);
    entradas[I]->especie = Classificar(memoria, sizeM);
}

void escreverSaida (flor** entradas, int sizeE, char* arquivo = "saida.data") {
    FILE* arq = fopen(arquivo, "a");
    fprintf(arq, "sepal_length,sepal_width,petal_length,petal_width,specie\n");

    for (int I = 0; I < sizeE; I++) {
        fprintf(arq, "%.1f,%.1f,%.1f,%.1f,%s\n", entradas[I]->sl, entradas[I]->sw, entradas[I]->pl, entradas[I]->pw, entradas[I]->especie);
    }
    fclose(arq);
}


int main () {

    // Ler os dados base e salva na memória
    flor** memoria = (flor**) malloc(sizeof(flor*) * 200);
    int sizeM = 0;

    if (!CarregarDados("iris.data", memoria, &sizeM)) {
        printf("Nenhum dado foi lido");
        return 1;
    }

    // Ler os dados de entrada e salva na memória
    flor** entradas = (flor**) malloc(sizeof(flor*) * 200);
    int sizeE = 0;

    if (!CarregarDados("entrada.data", entradas, &sizeE)) {
        printf("Nenhuma entrada foi lida");
        return 2;
    }

    // Atribui uma especie a cada elemento da entrada
    for (int I = 0; I < sizeE; I++) {
        resolveProblema(entradas, memoria, sizeM, I);
    }

    // escreve a saida em um arquivo de texto
    escreverSaida(entradas, sizeE);

    freeMemoria(memoria, sizeM);
    freeMemoria(entradas, sizeE);

    return 0;
}
