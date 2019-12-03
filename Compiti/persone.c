/*
 * Scrivi un programma che nel main chieda in input N persone e le salvi in
 * un vettore.
 * In un'altra funzione dovrai trovare e stampare a schermo la più vecchia.
 * Un'altra funzione dovrà stampare solo i minorenni.
 * Un'altra funzione dovrà in loop chiedere un intero in input e stampare
 * le persone con età maggiore dell'input
 */
#include "../useful/useful.h"		// Ignoralo, questo serve solo per il mio PC tu cancellalo

#include <stdio.h>	// Include alcune funzioni già definite per l'interazione (I/O, Input/Output)

#define LEN 2		// Definisce una costante in tutto il programma

// Definiamo una struct
struct persona {
	char nome[20];
	int anni;
};

// Diamo un nome al nostro nuovo tipo
typedef struct persona persona;

// Prototipi
int vecchio(persona persone[]);
void minorenni(persona tutti[]);
void piu_grande(persona alunni[], persona vecchio);

int _persone(int argc, char* argv[]) {
	persona persone[LEN];		// Dichiariamo un array di interi
	int i, vecchissimo;

	// Facciamo un ciclo su ogni elemento dell'array
	for (i = 0; i < LEN; i++) {
		printf("Inserisci il nome: ");
		scanf("%s", persone[i].nome);
		fflush(stdin);
		printf("Inserisci l'età: ");
		scanf("%d", &persone[i].anni);
		fflush(stdin);
	}
	vecchissimo = vecchio(persone);		// Salviamo il risultato della funzione max()
	printf("Il più vecchio è %s\n", persone[vecchissimo].nome);
	minorenni(persone);
	piu_grande(persone, persone[vecchissimo]);

	return 0;
}

int vecchio(persona persone[]) {		// Implementiamo la funzione max() che si aspetta di ricevere un array di interi

	int indice_vecchio = 0;		/* Dichiariamo e inizializziamo una variabile che conterrà la posizione della persona più veccchia.
						   La inizializziamo al primo valore del nostro array così abbiamo un valore di partenza corretto */

	// Troviamo il più vecchio
	int i;
	for (i = 0; i < LEN; i++) {
		if (persone[i].anni > persone[indice_vecchio].anni)		// Aggiorniamo l'indice solo se uno ha più anni
			indice_vecchio = i;
	}
	return indice_vecchio;		// Restituiamo il valore trovato
}

void minorenni(persona tutti[]) {
	int i;
	puts("I minorenni sono:");
	// Facciamo un ciclo su ogni elemento dell'array
	for (i = 0; i < LEN; i++) {
		if (tutti[i].anni < 18)		// Stampiamo solo se ha meno di 18 anni
			printf("%s\n", tutti[i].nome);
	}
}

void piu_grande(persona alunni[], persona vecchio) {

	printf("Sappiamo che il più vecchio è %s con %d anni\n", vecchio.nome, vecchio.anni);

	int input = -1;		// Usiamo questa come variabile di controllo, non importa quale valore le mettiamo adesso
	int numero, i;

	while (input != 0) {		// Il ciclo continua finché l'utente non preme '0'
		printf("Inserisci un'età: ");
		scanf("%d", &numero);
		fflush(stdin);
		puts("Le seguenti persone sono più vecchie:");
		for (i = 0; i < LEN; i++) {
			if (alunni[i].anni < numero)
				printf("\t%s, %d\n", alunni[i].nome, alunni[i].anni);
		}
		printf("Premi '0' se vuoi smettere, un altro tasto per continuare: ");
		fflush(stdin);
		scanf("%d", &input);
		fflush(stdin);
	}
}