#include <stdio.h>

#define BROJ_EL 200

int main() {
	
	int i;
	int niz[BROJ_EL];
	int broj_puta=0,index=0;
	int broj_elemenata=0;
	
	
	printf("Unesite brojeve:");
	for(i=0;i<BROJ_EL;i++){
	    scanf("%d",&niz[i]);
	    broj_elemenata++;
	    if((niz[i] < 0 || niz[i] > 100) && niz[i]!=-1){
	        printf("\nBrojevi moraju biti izmedju 0 i 100!");
	        broj_elemenata--;}
	    if(niz[i]==-1){
	        broj_elemenata--;
	    	break;
	    }
	}
	
	index=0;
	
	if(broj_elemenata>0) {
		
		do {
			
		for(i=0;i<=broj_elemenata;i++){
			if(index==niz[i])
				broj_puta++;
		}
		
		if(broj_puta>0){
			printf("\nBroj %d se javlja %d puta.",index,broj_puta);
		}
		broj_puta=0;
		index++;
		} while(index<101);
	}
	
	return 0;
}
