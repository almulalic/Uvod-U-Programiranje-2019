#include <stdio.h>

int main() {
	
	int broj,cifra,pomnozenBrojBC=0,brojBezCifara=0,mnozilac=1 ;
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	printf("Unesite cifru: ");
	scanf("%d",&cifra);	
	
	
	do {
		
		if(broj % 10 != cifra) { 
			brojBezCifara += mnozilac * (broj % 10);
			pomnozenBrojBC = brojBezCifara * 2;
			mnozilac*=10;
		}
		
		broj/=10;

	} while(broj!=0);
	
	
	printf("\nNakon izbacivanja broj glasi %d",brojBezCifara);
	printf("Nakon izbacivanja broj glasi %d",pomnozenBrojBC);
	
	
	return 0;
}
