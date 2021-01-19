#include <stdio.h>

void ispisi(int niz[],int n) {
	
	printf("{");
	
	for(int i=0;i<n;i++) {
		if(i<n-1)
			printf("%d, ",niz[i]);
		else
			printf("%d",niz[i]);
	}
	
	printf("}");
	
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
	
	ispisi(niz,n);
	
	return 0;
}
