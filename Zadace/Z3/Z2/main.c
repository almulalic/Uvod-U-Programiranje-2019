#include <stdio.h>
#include <math.h>

#define epsilon 0.0001

double stepen(double x){
	
	static int stepen = 1;
	static double prosloX=0;
	
	if(fabs(prosloX-x)<epsilon){
		stepen++;
		prosloX=x;
	} else {
		prosloX=x;
		stepen=1;
	}
	
	return pow(x,stepen);
	
}

void stepenuj_niz(double A[], int s[], int duzina){
	
	int i,j;
	double suma=0;
	
	for(i=0;i<duzina;i++) {
		for(j=0;j<s[i];j++) {
		    suma=stepen(A[i]);
		}
		A[i]=suma;
		stepen(1);
		
	}
}

int main() {
	
	double A[100];
	int s[100];
	int i,duzina;
	
	printf("Unesite duzinu nizova: ");
	scanf("%d",&duzina);
	
	printf("Unesite niz koji se stepenuje: ");
	for(i=0;i<duzina;i++) {
		scanf("%lf",&A[i]);
	}

	printf("Unesite stepene: ");
	for(i=0;i<duzina;i++) {
		scanf("%d",&s[i]);
	}
	
	stepenuj_niz(A, s, 5);
	
	return 0;
}
