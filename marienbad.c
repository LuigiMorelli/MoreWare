/***********************************************
 *              MARIENBAD                      *
 *   File associato all'articolo pubblicato    * 
 * il 17-08-2019 su http://www.moreware.org/wp *
 *                                             *
 *            (C) MoreWare 2019                *
 ***********************************************/
#include <stdio.h>

int fiammiferi = 16;
int scelta;

void print_defs() {
	printf("\nMARIENBAD\n");
	printf("=========\n\n");
	printf("Ci sono 16 fiammiferi sul tavolo.\n");
	printf("Al tuo turno puoi prenderne 1, 2, 3 o 4.\n"); 
	printf("Chi prende l'ultimo perde!\n\n");

	return;
}

void giocatore() {
	do {
		scelta = 0;
		printf("Quanti fiammiferi prendi? ");
		scanf("%i", &scelta);
	} while ((scelta < 1) || (scelta > 4));

	return;
}

void ai(){
	printf("Io ne prendo %i!\n", 5 - scelta);
	fiammiferi = fiammiferi - 5;
	if (fiammiferi > 1)
		printf("Ora ne restano %i.\n", fiammiferi);
	return;
}

int main() {
	// Definizioni
	print_defs();
	
	do {
		// Mossa giocatore
		giocatore();

		// Mossa AI
		if (fiammiferi > 1)
			ai();
	
		// valutazione gioco

		// Uscita
	} while (fiammiferi != 1);

	printf("\nNe e' rimasto solo uno! Hai perso!\n\n");

	return 0;
}
