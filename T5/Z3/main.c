#include <stdio.h>

int main() {
	
	float nizA[5],nizB[5];
	int i;
	
	printf("Unesite clanove niza A: ");
	for(i=0;i<5;i++)
		scanf("%f",&nizA[i]);
	
	printf("Unesite clanove niza B: ");
	for(i=0;i<5;i++)
		scanf("%f",&nizB[i]);
	
	
	printf("Niz A glasi: ");
	for(i=0;i<5;i++){
		if(i!=4)
			printf("%.2f, ",nizA[i]);
		else
			printf("%.2f",nizA[i]);
			
	}
	
	printf("\n");
	
	printf("Niz B glasi: ");
	for(i=0;i<5;i++){
		if(i!=4)
			printf("%.2f, ",nizB[i]);
		else
			printf("%.2f",nizB[i]);
			
	}
	
	printf("\n");
	
	printf("Niz C glasi: ");
	for(i=0;i<5;i++){
		if(i!=4)
			printf("%.2f, ",2*nizA[i] + nizB[i]);
		else
			printf("%.2f",2*nizA[i] + nizB[i]);
			
	}
	
	
	return 0;
}
