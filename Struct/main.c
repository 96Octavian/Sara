#include "../useful/useful.h"
#include <stdio.h>
#include <string.h>

#define LEN 4

struct prova {
	char stringa[20];
	int numero;
};

typedef struct prova container_t;

void modifica_valore(container_t giorgio);
void modifica_riferimento(container_t* giorgio);
void modifica_valore_vett(container_t oggetti[]);

int main(void) {
	container_t giorgio;
	strcpy(giorgio.stringa, "Giorgio");
	giorgio.numero = 20;
	printf("Nel main:\n\t%s, %d\n", giorgio.stringa, giorgio.numero);
	modifica_valore(giorgio);
	printf("Nel main dopo modifica_valore:\n\t%s, %d\n", giorgio.stringa, giorgio.numero);
	modifica_riferimento(&giorgio);
	printf("Nel main dopo modifica_riferimento:\n\t%s, %d\n", giorgio.stringa, giorgio.numero);

	container_t oggetti[LEN];
	strcpy(oggetti[0].stringa, "Luca");
	oggetti[0].numero = 20;
	strcpy(oggetti[1].stringa, "Giovanni");
	oggetti[1].numero = 21;
	strcpy(oggetti[2].stringa, "Andrea");
	oggetti[2].numero = 22;
	strcpy(oggetti[3].stringa, "Giacomo");
	oggetti[3].numero = 23;
	puts("Nel main:");
	for (int i = 0; i < LEN; ++i) {
		printf("\t%s, %d\n", oggetti[i].stringa, oggetti[i].numero);
	}
	modifica_valore_vett(oggetti);
	puts("Nel main dopo modifica_valore_vett:");
	for (int i = 0; i < LEN; ++i) {
		printf("\t%s, %d\n", oggetti[i].stringa, oggetti[i].numero);
	}
}

void modifica_valore(container_t giorgio) {
	printf("In modifica_valore prima della modifica:\n\t%s, %d\n", giorgio.stringa, giorgio.numero);
	strcpy(giorgio.stringa, "Paolo");
	giorgio.numero = 120;
	printf("In modifica_valore dopo la modifica:\n\t%s, %d\n", giorgio.stringa, giorgio.numero);
}

void modifica_riferimento(container_t* giorgio) {
	printf("In modifica_riferimento prima della modifica:\n\t%s, %d\n", (*giorgio).stringa, giorgio->numero);
	strcpy(giorgio->stringa, "Paolo");
	giorgio->numero = 120;
	printf("In modifica_riferimento dopo la modifica:\n\t%s, %d\n", (*giorgio).stringa, giorgio->numero);
}

void modifica_valore_vett(container_t oggetti[]) {
	puts("In modifica_valore_vett prima della modifica:");
	for (int i = 0; i < LEN; ++i) {
		printf("\t%s, %d\n", oggetti[i].stringa, oggetti[i].numero);
	}
	for (int i = 0; i < LEN; ++i) {
		strcpy(oggetti[i].stringa, "ANONIMO");
		oggetti[i].numero -= LEN;
	}
	puts("In modifica_valore_vett dopo la modifica:");
	for (int i = 0; i < LEN; ++i) {
		printf("\t%s, %d\n", oggetti[i].stringa, oggetti[i].numero);
	}
}
