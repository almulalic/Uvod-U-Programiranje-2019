#include <stdio.h>
#define DUZINA 10

int main() {
	
	int nizA[DUZINA]={0};
	int nizB[DUZINA]={0};
	int nizC[DUZINA * 2]={0};

	int i;
	int broj;
	int brojElemenataA=0;
	int brojElemenataB=0;
	
	printf("Unesite elemente niza A: ");
	for(i=0;i<DUZINA;i++) {
		scanf("%d",&broj);
		if(broj != -1) {
			nizA[i] = broj;
			brojElemenataA++;
		}
		else
			break;
		
	}
	
	printf("Unesite elemente niza B: ");
	for(i=0;i<DUZINA;i++) {
		scanf("%d",&broj);
		if(broj != -1) {
			nizB[i] = broj;
			brojElemenataB++;
		} else
			break;
		
	}

	
	for(i=0;i<brojElemenataA+brojElemenataB;i++){
		if(i<brojElemenataA)
			nizC[i] = nizA[i];
		else 
			nizC[i] = nizB[i-brojElemenataA];
	}
	
	printf("Niz C glasi: ");
	for(i=0;i<brojElemenataA+brojElemenataB;i++)
		if(i!=brojElemenataA+brojElemenataB-1)
			printf("%d,",nizC[i]);
		else 
			printf("%d",nizC[i]);
	
	return 0;
}
