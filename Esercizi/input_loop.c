#pragma warning(disable: 4996)
#include <stdio.h>

int _input_loop(void)
{
	int a, b;
	char risposta, input[50], * risultato;
	puts("Hello World!");

	// TODO: Input di più di 50 caratteri
	// TODO: Input di lunghezza variabile
	// TODO: flush stdin


	/*
	 * Chiedi in input due numeri e fanne la somma.
	 * Chiedi in loop se vuole farlo ancora.
	 */
	printf("Vuoi sommare due numeri [S\\n]? ");
	while ((risultato = fgets(input, sizeof(input), stdin)) && printf("La tua risposta è: %s", input)) {
		if (1 != sscanf(input, "%c", &risposta) || ('S' != risposta && 'n' != risposta)) {
			printf("Per favore, rispondi solo S o n. Vuoi sommare due numeri? ");
			continue;
		}
		if ('n' == risposta)
			break;
		puts("Inserisci due numeri da sommare:");
		while ((risultato = fgets(input, sizeof(input), stdin)) && printf("Hai inserito: %s", input)) {
			if (2 != sscanf(input, "%d %d", &a, &b)) {
				printf("Per favore, inserisci solo i numeri da sommare separati da uno spazio: ");
				continue;
			}
			printf("%d + %d = %d", a, b, a + b);
			printf("Vuoi sommare altri due numeri [S\\n]? ");
		}
		if (!risultato)
			break;
	}

	if (risultato)
		puts("Ciao!");
	else {
		puts("Errore nella lettura da stdin");
		return 1;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
