#include <stdio.h>

int A[2][2][2][2];
int	G1, G2, G3, G4;
int	X1, TC, TU;
int Ch;
int Valore;
int w, x, y, z;

int main() {
	// Matrix initialization
	for (w = 0; w < 2; w++)         	  	    /* Inizializzazione della matrice      */
		for (x = 0; x < 2; x++)     	        /* delle frequenze di uscita delle     */
	  		for (y = 0; y < 2; y++)	        	/* diverse combinazioni.               */
				for (z = 0; z < 2; z++)
		  			A[w][x][y][z] = 0;
	TC = 0;            	                		/* Punteggio computer                  */
	TU = 0;                              		/* Punteggio gioccatore                */
	printf ("\nSimulazione del gioco del pari e dispari con apprendimento dall'esperienza.\n");
	printf ("Io vinco se la somma e' pari, tu se la somma e' dispari.\n");
	printf ("Gioca 0 per pari, 1 per dispari, 2 per uscire.\n");
	G1 = 0;
	G2 = 1;                              		/* Inizializzazione valori di partenza */
	G3 = 0;                              		/* (Puo' essere anche gestita tramite  */
	G4 = 1;                              		/*       un generatore random)         */
	do {
		if (A[G1][G2][G3][0] > A[G1][G2][G3][1])
			X1 = 0;                        		/* Ricerca della mossa migliore */
		else 
			X1 = 1;

		do {
			printf("Pari o dispari?  ");
		  	scanf("%i", &Ch);
		} while ((Ch < 0) || (Ch > 2));

		Valore = Ch; 

		if (Valore < 2) {
			if (X1 == Valore)
				TC = TC + 1;      					/* Aggiornamento punteggi       */
			else 
				TU = TU + 1;

			A[G1][G2][G3][Valore] = A[G1][G2][G3][Valore] + 1;
			G1 = G2;
			G2 = G3;
			G3 = Valore;

			printf ("Computer ---> %4i     Giocatore ---> %4i", TC, TU);
			if (TU != 0) 
				printf ("  -     \%% Comp./Gioc. --->  %4.5f",(double)TC/(double)TU);
			printf("\n");
		}
  } while (Ch != 2);
}
