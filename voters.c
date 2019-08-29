#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "voters.h"

int t[80][25],
    v[256] = {0},
	h[256] = {0},
	d[4000];

int		x, x1, x2, y, y1, y2, b, c, s, i, m, f, t1;
int		k, c1;
bool	g, e;
char	l;
time_t	tt;

void GotoXY(int a, int b) {
	printf("\x1b[%i;%iH",b,a);
}

void inizializza() {
	// Inserimento dei dati di partenza
	printf(CLRSCR);

	g= true;
	k = 0;
	f = 0;

	printf ("Censimento automatico ? (S/N) "); scanf("%c", &l);
	if (toupper(l) == 'S') {
		do {
			printf("PERIODO DI CENSIMENTO    : "); scanf ("%i", &c1);
		} while (c1<0); 
	} else
		 g = false;

	if (g) 
		m = 74;
	else
		m = 80;

	do {
		printf("NUMERO RIGHE (MAX 25)    : "); scanf("%i", &y);
	} while ((y < 0) || (y > 26));
	do {
		printf("NUMERO COLONNE (MAX %i)  : ", m); scanf("%i", &x);
	} while ((x < 0) || (x > m + 1));

	c = x * y;
	printf("NUMERO CELLE = %i\n", c);
	do {
		printf("NUMERO STATI (MAX 256) : "); scanf("%i", &s);
	} while ((s < 1) || (s > 257));

	b = c;
	int step = b / s;
	for (i = 1; i <= (s - 1); i++) {
		v[i] = step;
		b = b - v[i];
		h[i] = v[i];
	}
	v[s] = b;
	h[s] = b;
	
	printf(CLRSCR);
}

void situazione()
{
	for (i = 1; i <= s; i++)
	{
	 	GotoXY(77,i); printf ("%4i",h[i]);
	}
	GotoXY(75,s+3); printf ("%8i", k);
}

int main() {
	e = false;

	do {
		inizializza(); 

		// Generazione griglia

		/* Intializes random number generator */
		srand((unsigned) time(&tt));
   
		for (i = 1; i <= s; i++) {
			do {
    			x1 = (rand() % x ) + 1;
				y1 = (rand() % y ) + 1;
    			if (t[x1][y1] == 0) {     
		     		t[x1][y1] = i;
					v[i] = v[i]-1;

					GotoXY(x1, y1); 

					printf("\x1b[48:5:%im " RESET_COLOR, t[x1][y1]-1);
				}
			} while (v[i] != 0);
		}

		if (g) {
			for (i = 1; i <= s; i++) {
				GotoXY(76, i);
				printf ("\x1b[48:5:%im " RESET_COLOR, i-1); 
			}
			GotoXY(75, s+2);
			printf ("CICLI:");
		}

		// Questo ciclo termina con la fine della Democrazia
		do {
			// Ciclo elementare
			do {
				// Sceglie casualmente l'elettore influenzante e quello influenzato
				// e ne calcola la posizione all'interno della matrice
				x1 = (rand() % x) + 1;
				y1 = (rand() % y) + 1;
				t1 = (rand() % 8) + 1;

				switch (t1) {
					case 0 : { x2=x1;   y2=y1-1; if (y2==0) y2=y; break; }
					case 1 : { x2=x1+1; y2=y1-1; if (x2>x)  x2=1; if (y2==0) y2=y; break; }
					case 2 : { x2=x1+1; y2=y1;   if (x2>x)  x2=1; break; }
					case 3 : { x2=x1+1; y2=y1+1; if (x2>x)  x2=1; if (y2>y) y2=1; break; }
					case 4 : { x2=x1;   y2=y1+1; if (y2>y)  y2=1; break; }
					case 5 : { x2=x1-1; y2=y1+1; if (x2==0) x2=x; if (y2>y) y2=1; break; }
					case 6 : { x2=x1-1; y2=y1;   if (x2==0) x2=x; break; }
					case 7 : { x2=x1-1; y2=y1-1; if (x2==0) x2=x; if (y2==0) y2=y; break; }
				}

				// Esegue il censimento automatico
				if (g) {                             
					if ((k % c1) == 0)
					{
						for (i = 1; i <= s; i++)
						{
						 	GotoXY(77,i); printf ("%4i",h[i]);
						}
						GotoXY(75,s+3); printf ("%8i", k);
					}
				}

				h[t[x1][y1]] = h[t[x1][y1]] - 1;
				h[t[x2][y2]] = h[t[x2][y2]] + 1;
				// Aggiorna f = numero di partiti chiusi
				if (h[t[x1][y1]] == 0)
					f = f + 1;
				t[x1][y1] = t[x2][y2];                   // Avviene il mutamento di partito 

				GotoXY(x1, y1); 
				printf("\x1b[48:5:%im " RESET_COLOR, t[x1][y1]-1);

				k = k + 1;	// Aggiorna ciclo

			} while (f != s-1);
		} while (f != s-1);
		situazione();		
	} while (e);
	printf("\n");
	return 0;
}
