/*
 * Scrivi un programma che nel main chieda in input N interi e li salvi in un
 * vettore.
 * In un'altra funzione dovrai trovare e stampare a schermo il massimo
 * di questo vettore.
 * Un'altra funzione dovrà stampare solo i numeri pari
 * Un'altra funzione dovrà in loop chiedere un intero in input e dire se è
 * maggiore del nostro massimo, fino a che l'input non sarà 0 
 */
#include "../useful/useful.h"		// Ignoralo, questo serve solo per il mio PC tu cancellalo

#include <stdio.h>	// Include alcune funzioni già definite per l'interazione (I/O, Input/Output)

#define LEN 2		// Definisce una costante in tutto il programma

// Prototipi
int max(int vettore[]);
void stampa_pari(int tutti[]);
void input_maggiore(int vettore[], int max);

int main(int argc, char *argv[]) {
	int numeri[LEN];		// Dichiariamo un array di interi
	int i, massimo;

	// Facciamo un ciclo su ogni elemento dell'array
	for (i = 0; i < LEN; i++) {
		printf("Inserisci un numero: ");
		scanf("%d", &numeri[i]);
		fflush(stdin);
	}
	massimo = max(numeri);		// Salviamo il risultato della funzione max()
	printf("Il massimo è %d\n", massimo);
	stampa_pari(numeri);
	input_maggiore(numeri, massimo);

	return 0;
}

int max(int vettore[]) {		// Implementiamo la funzione max() che si aspetta di ricevere un array di interi

	int max = vettore[0];		/* Dichiariamo e inizializziamo una variabile che conterrà il nostro massimo.
								   La inizializziamo al primo valore del nostro array così abbiamo un valore di partenza corretto */

	// Troviamo il massimo
	int i;
	for (i = 0; i < LEN; i++) {
		if (vettore[i] > max)
			max = vettore[i];
	}
	return max;		// Restituiamo il valore trovato
}

void stampa_pari(int tutti[]) {
	int i;
	puts("I numeri pari sono:");
	// Facciamo un ciclo su ogni elemento dell'array
	for (i = 0; i < LEN; i++) {
		if (tutti[i] % 2 == 0)		// Stampiamo solo se il resto della divisione per 2 è 0 (quindi sono pari)
			printf("%d\n", tutti[i]);
	}
}

void input_maggiore(int vettore[], int max) {
	int input = -1;		// Usiamo questa come variabile di controllo, non importa quale valore le mettiamo adesso
	int numero;

	while (input != 0) {		// Il ciclo continua finché l'utente non preme 'x'
		printf("Inserisci un numero: ");
		scanf("%d", &numero);
		fflush(stdin);
		if (numero < max)
			puts("Il tuo numero è più piccolo");
		else if (numero > max)
			puts("Il tuo numero + più grande");
		else
			puts("Il tuo numero è uguale!");
		printf("Premi '0' se vuoi smettere, un altro tasto per continuare: ");
		fflush(stdin);
		scanf("%d", &input);
		fflush(stdin);
	}
}