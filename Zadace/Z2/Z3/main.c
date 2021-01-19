#include <stdio.h>
#include <math.h>

#define inicijalniBroj 200
#define epsilon 0.0001

int main() {
	
	int i,j,histogramBrojac=0;
	int brojClanova=0;
	double niz[inicijalniBroj]={0};
	int nizCifri[inicijalniBroj]={0};
	int histogram[10]={0,1,2,3,4,5,6,7,8,9};
	
	do {	
		printf("Unesite broj clanova niza: ");
		scanf("%d",&brojClanova);
	} while(brojClanova <= 0 || brojClanova>100);
	
	printf("Unesite niz: ");
	for(i=0;i<brojClanova;i++) {
		scanf("%lf",&niz[i]);
	}
	
	for(i=0;i<brojClanova;i++) {
		
		if( brojClanova+1 < inicijalniBroj && fabs(niz[i+1]-niz[i]*2) < epsilon ) {
			
			j=brojClanova+1;
			
			while(j>i+1) {
				niz[j]=niz[j-1];
				j--;
			}
			
			niz[i+1] = (niz[i]+niz[i+1])/2;
			brojClanova++;
		
		}
		
		nizCifri[i]=(int)(niz[i]*10)%10;
		
	}
	
	printf("Nakon ubacivanja niz glasi: \n");
	for(i=0;i<brojClanova;i++) {
		printf("%g ",niz[i]);
	}
	
	for(i=0;i<10;i++) {
		for(j=0;j<brojClanova;j++) {
			if(histogram[i]==nizCifri[j])
				histogramBrojac++;
		}
		
		if(histogramBrojac > 0)
			printf("\nCifra %d se ponavlja %d puta.",i,histogramBrojac);
		
		histogramBrojac=0;
	}
	
	return 0;
}
