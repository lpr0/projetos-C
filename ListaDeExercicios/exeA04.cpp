#include <stdio.h>

int main() {
	char nome[20];
	float x, y;
	printf("Nome do aluno: \n");
	fgets(nome, 20, stdin);
	for (int I; I < 19; I++) {
		if (nome[I] == '\n') {
			nome[I] = '\0';
		}
	}
	nome[19] = '\0';
	printf("Notas: \n");
	scanf(" %f %f", &x, &y);
	printf("%s obtve %0.2f de media.", nome, ((x + y) / 2));
}
