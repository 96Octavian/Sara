#include "../useful/useful.h"
#include <stdio.h>
#include <time.h>

#define N 50

void carica(int* vett);
double media_func(int* vett);

int main(int argc, char* argv[]) {
	int n, vett[N];
	double media;
	printf("Inserire un numero per il comando: ");
	scanf("%d", n);

	switch (n) {
	case 1:
		carica(vett);
		break;
	case 2:
		media = media_func(vett);
		printf("La media %lf", media);
		break;
	default:
		puts("Comando non riconosciuto");
		break;
	}
}

void carica(int* vett) {
	int n, i;
	srand(time(NULL));
	for (i = 0; i < N; ++i) {
		n = rand() % 100 + 1;
		vett[i] = n;
	}
}

double media_func(int* vett) {
	int somma = 0, i = 0;
	double media;
	for (i = 0; i < N; ++i) {
		somma += vett[i];
	}
	media = somma / N;
	return media;
}