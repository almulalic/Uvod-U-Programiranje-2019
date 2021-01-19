#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

	int randBroj,korisnikUnos;
	
	srand(time(0));
	
	randBroj = rand() % 100 + 1;
	
	printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz).\n");
	
	do {
		
		printf("Unesite broj: ");
		scanf("%d",&korisnikUnos);
		
		if (korisnikUnos == -1) {
			printf("Kraj igre.");
			return 1;
		}
		
		else if(randBroj > korisnikUnos)
			printf("VEĆI\n");
		else if(randBroj < korisnikUnos)
			printf("MANJI\n");
		else if (randBroj == korisnikUnos) {
			printf("JEDNAK\n");
			printf("Kraj igre.");
			return 0;
		}
		
	} while(korisnikUnos != randBroj);
	

	return 0;
}
