#include <stdio.h>

int main() {
	
	int n;
	int maxKolona;
	int visinaPoklopac;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	printf("\n");
	
	if(n%2==1 || n < 4 || n > 100) {
		printf("Broj je van trazenog opsega.");
		return 1;
	}
	
	maxKolona = n*2;
	visinaPoklopac = n/2-1;
	
	for(int i=0; i<n; i++) {
		
		for(int j=0; j<maxKolona; j++) {
			
			if(i==0 || i==n-1 || j==0 || j==maxKolona-1 || (i==visinaPoklopac && (j>i-1 && j<maxKolona-i)) || (j==i && i<visinaPoklopac) || (j==maxKolona-1-i && i<visinaPoklopac))
				printf("+");
			else
				printf(" ");

		}
		
		printf("\n");
	}
	
	
	return 0;
}
