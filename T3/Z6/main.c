#include <stdio.h>
#include <math.h>

int main() {
	
	int n,i; 
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n<=0) {
		printf("Broj nije prirodan.");
		return 1;
	} else if(n==1) {
		printf("Broj nije ni prost ni slozen.");
		return 1;
	}
	
	for(i=2;i<n/2;i++) {
		
		if(n%i == 0){
			printf("Broj je slozen.");
			return 0;
		}
	
	}
	
	printf("Broj je prost.");
	
	return 0;
}
