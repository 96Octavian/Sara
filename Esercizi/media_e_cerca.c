#include "../useful/useful.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2

typedef struct {
	char nome[20];
	char cognome[20];
	int eta;
} persona_t;

void carica(persona_t* vett);
void cerca(persona_t* vett, char* nome);
double media(persona_t* vett);

int _media_e_cerca(void) {
	persona_t vett[N];
	char nome[20];
	double ris;
	carica(vett);
	fflush(stdin);
	printf("Inserire il nome da cercare: ");
	scanf("%s", nome);
	fflush(stdin);
	cerca(vett, nome);
	ris = media(vett);
	printf("L'età media è %lf\n", ris);
	system("PAUSE");
	return 0;
}

void carica(persona_t* vett) {
	for (int i = 0; i < N; i++) {
		printf("Inserire il nome: ");
		scanf("%s", vett[i].nome);
		fflush(stdin);
		printf("Inserire il cognome: ");
		scanf("%s", vett[i].cognome);
		fflush(stdin);
		printf("Inserire l'età: ");
		scanf("%d", &vett[i].eta);
		fflush(stdin);
	}
}

void cerca(persona_t* vett, char* nome) {
	int i = 0;
	while (i < N && strcmp(nome, vett[i].nome) != 0)
		i++;
	if (i < N && strcmp(nome, vett[i].nome) == 0)
		printf("L'età di %s è %d\n", nome, vett[i].eta);
	else
		printf("%s non è presente\n", nome);
}

double media(persona_t* vett) {
	int somma = 0;
	for (int i = 0; i < N; i++)
		somma += vett[i].eta;
	return somma / N;
}