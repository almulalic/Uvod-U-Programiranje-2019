#include <stdio.h>

int drugi(int niz[],int duzina){
	
	int i,max=niz[0];
	int drugiMax=niz[1];
	int indexDrugog=0;
	
	if(duzina==2)
		return max > drugiMax ? 0 : 1;
	
	for(i=0;i<duzina;i++) {
		if(niz[i]>max){
			indexDrugog=i-1;
			max=niz[i];
		}
	}
	
	return indexDrugog;
}

int main() {

	int niz[100];
	int i,unos;
	
	printf("Unesite niz brojeva:");
	
	for(i=0;i<100;i++) {
		scanf("%d",&unos);
		if(unos==-1)
			break;
		else
			niz[i]=unos;
	}
	
	printf(" Indeks drugog po velicini je: %d",drugi(niz,i--));

	return 0;
}
