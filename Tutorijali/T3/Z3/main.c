#include <stdio.h>

int main() {
	
	int n,i;
	
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
	for(i=n;i>0;i--) {
		if(i%11==0 || i%7==0 || i%5==0)
			printf("%i\n",i);
	}
	
	return 0;
}
