#include <stdio.h>
#include <stdlib.h>

int obrniBroj(int broj) {
	
	int obrnutiBroj=0;
	int ostatak = 0;
	int predznak = broj < 0 ? -1 : broj > 0 ? 1:0;
	
	broj = abs(broj);
	
	while(broj > 0) {
		ostatak = broj % 10;
        obrnutiBroj = obrnutiBroj * 10 + ostatak;
        broj /= 10;
	}
	
	return predznak*obrnutiBroj;
	
}

void obrni_cifre(int *pocetak,int n) {
	
	for(int i=0;i<n;i++) {
		*(pocetak + i) = obrniBroj(*(pocetak+i));
	}
	
}

int main() {
		
	int niz[50];
	int n;
	
	printf("Unesite duzinu: ");
	scanf("%d",&n);
	printf("Unesite niz: ");
	
	for(int i=0;i<n;i++) {
		scanf("%d",&niz[i]);
	}
	
	obrni_cifre(niz+1,0);
	
	for(int i=0;i<n;i++) {
		printf("%d ",niz[i]);
	}
	
	return 0;
}