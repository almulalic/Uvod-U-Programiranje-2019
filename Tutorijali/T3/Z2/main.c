#include <stdio.h>

int main() {
	
	int broj,suma=0,i;
	
	for(suma=0;suma<=100;i++) {
		printf("Unesite broj: ");
		scanf("%d",&broj);
		suma+=broj;
	}
	
	printf("Suma je: %d",suma);
	
	return 0;
}
