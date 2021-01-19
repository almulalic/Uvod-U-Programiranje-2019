#include <stdio.h>

void udvostruci(int* niz,int n) {
	
	for(int i=0;i<n;i++) {
		*(niz+i)=*(niz+i)*2;
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
	
	udvostruci(niz,n);
	
	for(int i=0;i<n;i++) {
		printf("%d ",niz[i]);
	}
	
	return 0;
}
