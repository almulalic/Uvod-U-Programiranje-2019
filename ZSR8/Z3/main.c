#include <stdio.h>
#include <math.h>

#define epsilon 0.000001

void sortiraj(double* niz,int n) {
	double temp;
	int i,j;
	double *max = niz;
	
	for(i=0;i<n;i++) {
		max = niz+i;
		for(j=i;j<n;j++) {
			if(*(niz+j) > *max)
				max = niz+j;
		}
		temp = *(niz+i);
		*(niz+i) = *max;
		*max = temp;
	}
	
}

int main() {
		
	double niz[50];
	int n;
	
	printf("Unesite duzinu: ");
	scanf("%d",&n);
	printf("Unesite niz: ");
	
	for(int i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	
	sortiraj(niz,n);
	
	for(int i=0;i<n;i++) {
		printf("%lf ",niz[i]);
	}
	
	return 0;
}
