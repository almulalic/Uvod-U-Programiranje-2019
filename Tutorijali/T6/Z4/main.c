#include <stdio.h>

#define DUZINA 10

int main() {
	
	int i,j,broj;
	int elementZaIzbaciti;
	int brojElemenata;
	int niz[DUZINA]={0};
	
	
	printf("Unesite elemente niza: ");
	for(i=0;i<DUZINA;i++) {
		scanf("%d",&broj);
		if(broj != -1) {
			niz[i] = broj;
			brojElemenata++;
		}
		else
			break;
	}
	
	
	
	printf("Unesite element koji treba izbaciti: ");
	scanf("%d",&elementZaIzbaciti);
	
	
	for(i=0;i<brojElemenata-1;i++) {
		
		if(niz[i] ==  elementZaIzbaciti) {
			
			for(j=i;j<DUZINA-1;j++) 
				niz[j] = niz[j+1];

			brojElemenata--;
			i--;
			
		}
		
	}

	
	
	
	
	return 0;
}
