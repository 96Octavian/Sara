#include "../useful/useful.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	double x, y;
	char nome;
} punto_t;

void inserimento(punto_t* p);

int _inserimento(void) {
	punto_t a, b;
	inserimento(&a);
	inserimento(&b);
	printf("Primo punto: %c(%.2lf, %.2lf)\n", a.nome, a.x, a.y);
	system("PAUSE");
	return 0;
}

void inserimento(punto_t* p) {
	printf("Inserire la coordinata x: ");
	scanf("%lf", &p->x);
	printf("Inserire la coordinata y: ");
	scanf("%lf", &p->y);
	do {
		printf("Inserire il nome del punto (una sola lettera): ");
		scanf("%c", &p->nome);
		fflush(stdin);
	} while (!isupper(p->nome) || !isalpha(p->nome));
}