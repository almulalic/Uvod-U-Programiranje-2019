#include <stdio.h>
#define BROJ_EL 10


int main() {
	
	int niz[BROJ_EL],sumaParni=0,sumaSvi=0,i,parni=0;
	int min,max;
	float prosjekSvi=0,prosjekParni=0;
	
	
	for(i=0;i<BROJ_EL;i++) {
		
		printf("Unesite %d. cijeli broj: ",i+1);
		scanf("%d",&niz[i]);
		
		if(i==0) {
			min = niz[i];
			max = niz[i];
		}
		
		if(niz[i] % 2 == 0){
			sumaParni+=niz[i];
			parni++;
		}
			
		if(niz[i] > max)
			max = niz[i];
		
		if(niz[i] < min)
			min = niz[i];
			
		sumaSvi+=niz[i];
			
	}
	
	prosjekSvi = (float)sumaSvi/BROJ_EL;
	prosjekParni = (float)sumaParni/parni;

	printf("Srednja vrijednost unesenih brojeva je %.2f.\n",prosjekSvi);
	printf("Srednja vrijednost parnih brojeva je %.2f.\n",prosjekParni);
	printf("Najveci element je %d a najmanji %d.",max,min);
	
	
	return 0;
}
 