#include <stdio.h>

int obrnut(int broj) {
	
	int obrnuti=0;
	
	while(broj!=0) {
		obrnuti*=10;
		obrnuti+=(broj%10);
		broj/=10;
	}
	
	return obrnuti;
}


int main() {
	
	int broj;
	
	printf("Unesite broj: ");
	scanf("%d",&broj);
	
	printf("%d",obrnut(broj));
	
	return 0;
}
