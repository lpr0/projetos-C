#include <stdio.h>

int CparaI (char a) {
	char numeros[] = "0123456789";
	for (int I = 0; I < 10; I++) {
		if (a == numeros[I]) {
			return I;
		}
	}
}

int numOUnao (char a) {
	char numeros[] = "0123456789";
	for (int II = 0; II < 10; II++) {
		if (a == numeros[II]) {
			return 1;
		}
	}
	return 0;	
}

void formarN (float* x, int N) {
	*x = (*x * 10) + N;
}

int opeOUnao (char a) {
	char operacoes[] = "+-/*";
	for (int II = 0; II < 4; II++) {
		if (a == operacoes[II]) {
			return operacoes[II];
		}
	}
	return 0;
}

int calcular (char s, float x, float y) {
	switch (s) {
		case '+':
			return (x + y);
		case '-':
			return (x - y);
		case '*':
			return (x * y);
		case '/':
			if (y != 0) {
				return (x / y);
			}
		default:
			printf("Operacao invalida. \n");
	}
}


#define Tamanho 20

int main () {
	
	float x = 0, y = 0;
	char s = '+';
	char EX[Tamanho + 1];
	
	fgets(EX, (Tamanho), stdin);
	EX[Tamanho] = '\0';

	for (int I =0; I < Tamanho; I++) {
	
		if (EX[I] == '\n' || EX[I] == '\0') {
			break;
		}

		if (numOUnao(EX[I])) {
			formarN(&y, CparaI(EX[I]));
		} 
		
		if (opeOUnao(EX[I])) {
			x = calcular(s, x, y);
			y = 0;
			s = opeOUnao(EX[I]);		
		}


		/*	
		if (EX[I] == '\n' || EX[I] == '\0') {
			if (NumDet == 3) {
				if (negativo1) {
				x = -x;
				negativo1 = 0;
				}
				if (negativo2) {
					y = -y;
					negativo2 = 0;
				}
				x = calcular(s, x, y);
			}
			break;
		}
		if (EX[I] == '-' && numOUnao(EX[(I + 1)])) {
			if (NumDet <= 1) {
				negativo1 = 1;
			} else {
				negativo2 = 1;
			}
		}
		if (!numOUnao(EX[I]) && NumDet == 3) {
			if (negativo1) {
				x = -x;
				negativo1 = 0;
			}
			if (negativo2) {
				y = -y;
				negativo2 = 0;
			}
			x = calcular(s, x, y);
			y = 0;
			NumDet = 2;
		}
		if (opeOUnao(EX[I]) && NumDet >= 1) {
			s = opeOUnao(EX[I]);
			NumDet = 2;
		}
		if (numOUnao(EX[I]) && NumDet >= 2) {
			formarN(&y, CparaI(EX[I]));
			NumDet = 3;
		} else if (numOUnao(EX[I]) && NumDet <= 1) {
				formarN(&x, CparaI(EX[I]));
				NumDet = 1;
		}*/
	}	
	x = calcular(s, x, y);
	printf("%f", x);

}
