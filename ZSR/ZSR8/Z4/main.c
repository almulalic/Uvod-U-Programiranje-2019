#include <stdio.h>

void prekopiraj(const int *izvor,int *odrediste,int n) {
	
	for(int i=0;i<n;i++) {
		*(odrediste + i) = *(izvor + i);
	}
	
}

int main() {
		
	int niz[50];
	int n;
	
	printf("Unesite duzinu: ");
	scanf("%d",&n);
	printf("Unesite niz: ");
	
	for(int i=0;i<n;i++) {
		scanf("%d",&niz[i]);
	}
	
	prekopiraj(niz+2,niz+4,2);
	
	for(int i=0;i<n;i++) {
		printf("%d ",niz[i]);
	}
	
	return 0;
}