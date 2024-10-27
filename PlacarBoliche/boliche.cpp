#include<stdio.h>

// 9 frames (dois lançamentos no máximo, um strike no máximo) 
// + 1 frame (tres lançamentos no máximo, se o primeiro lançamento for strike, tres strikes no máximo)

int bonus (int* vetor, int Pstrike, int tamanho, int strike) {
    int bonus = 0;
    Pstrike++;
    for (int I = Pstrike; I < (Pstrike + strike) && I < tamanho; I++) {
        bonus += vetor[I];
    }
    return bonus;
}

void mostarPlacar (int* vetor, int tamanho) {
    int total = 0;
    int I = 0;
    for (int frame = 0; frame < 9; I += 2, frame++) {
        int L1 = vetor[I];
        if (L1 != 10) {
            int L2 = vetor[I + 1];
            if ((L1 + L2) == 10) {
                printf("%d / | ", L1);
                total += 10 + bonus(vetor, (I+1), tamanho, 1);
            } else {
                printf("%d %d | ", L1, L2);
                total += L1 + L2;
            }
        } else {
            printf("X _ | ");
            total += 10 + bonus(vetor, I, tamanho, 2);
            I--;
        }
    }
    for (int jogadas = 2, lances = 0; lances < jogadas && I < tamanho; lances++, I++) {
        if (vetor[I] == 10) {
            printf("X ");
            total += 10;
            if (lances == 0) {
                jogadas++;
            }
        } else {
            if (lances == 1 && (vetor[I - 1] + vetor[I]) == 10 && jogadas < 3) {
                printf("/ ");
                total += vetor[I];
                jogadas++;
            } else {
                printf("%d ", vetor[I]);
                total += vetor[I];
            }
        }
    }


    // decimo frame

    printf("\n%d", total);
}

int main () {
    int vetor[21];
    int tamanho = 0;

    for (int frames = 0, lances = 20, I = 0; frames < lances; I++, frames++, tamanho++) {
        scanf("%d", &vetor[I]);
        if (frames < 18) {
            if (vetor[I] == 10) {
                frames++;
            } 
        } else {
            if (frames == 18 && vetor[I] == 10) {
                lances++;
            } else if (frames == 19 && (vetor[I] + vetor[I - 1]) == 10 && lances < 21) {
                lances++;
            }
        }
    }
    

    mostarPlacar(vetor, tamanho);

    return 0;
}   