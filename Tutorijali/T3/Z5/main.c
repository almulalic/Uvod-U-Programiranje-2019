#include <stdio.h>
#include <math.h>


int main() {
	
	int i,n;
	double suma=0;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	for(i=1;i<=n;i++) {
		suma += (pow(-1,i-1))/i;
	}
	
	printf("Koristeci %i clanova suma je %.3lf.",n,suma);
	
	return 0;
}
