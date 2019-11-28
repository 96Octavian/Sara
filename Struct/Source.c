#pragma warning(disable: 4996)
#include <stdio.h>

#define ANNO 2019

typedef struct persona {
	char nome[20];
	char cognome[20];
	int anno_di_nascita;
} persona;

void calcola_anni(persona* classe, int alunni) {
	for (int i = 0; i < alunni; ++i) {
		printf("%s ha %d anni\n", classe[i].nome, classe[i].anno_di_nascita - ANNO);
	}
	classe[0].anno_di_nascita = 100;
	printf("Modificato: %d", classe[0].anno_di_nascita);

}

int _main(void) {
	persona classe[3];

	puts("Presentami delle persone:");
	for (int i = 0; i < 3; ++i) {
		scanf("%s %s %d", &classe[i].nome, &classe[i].cognome, &classe[i].anno_di_nascita);
	}
	puts("Conosco queste persone:");
	for (int i = 0; i < 3; ++i) {
		printf("%s %s %d\n", classe[i].nome, classe[i].cognome, classe[i].anno_di_nascita);
	}

	calcola_anni(classe, 3);
	printf("Modificato: %d", classe[0].anno_di_nascita);
}