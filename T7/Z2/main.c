#include <stdio.h>

long long int faktorijel(int n) {
	
	int i;
	long long int rezultat=1;
	
	for(i=2;i<=n;i++)
		rezultat*=i;
		
	
	return rezultat;
	
}

int main() {
	
	int i,n;
	double x,suma=0;
	
	printf("Unesite broj n u intervalu [1, 12]: ");
	scanf("%d",&n);
	printf("Unesite realan broj x: ");
	scanf("%lf",&x);
	
	for(i=1;i<=n;i++) {
		suma+=(x/faktorijel(i));
	}
	
	printf("Suma od 1 do %d za x = %.3lf je %.3lf",n,x,suma);
	
	
	return 0;
}
