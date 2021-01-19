#include <stdio.h>

int main() {
	
	int unos=0;
	int pet=0,sedam=0,jedanaest=0;
	
	printf("Unesite brojeve: ");
	while(unos!=-1) {
		scanf("%d",&unos);
		
		if(unos%5==0)
			pet++;
		
		if(unos%7==0)
			sedam++;
		
		if(unos%11==0)
			jedanaest++;

	}
	
	printf("\nDjeljivih sa 5: %d\n",pet);
	printf("Djeljivih sa 7: %d\n",sedam);
	printf("Djeljivih sa 11: %d",jedanaest);
	
	return 0;
}
