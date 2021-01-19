#include <stdio.h>

float maxtemp(float temp[],int brMjerenja) {

	int i;	
	float max=0;
	
	for(i=0;i<brMjerenja;i++) {
		if(temp[i]>max)
			max=temp[i];
	}
	
	return max;
}

float prtemp(float temp[],int brMjerenja) {

	int i;	
	float avg=0;

	for(i=0;i<brMjerenja;i++) {
		avg+=temp[i];
	}
	
	return avg/brMjerenja;
}


int main() {
	
	int i;
	float temperature[100];
	int brMjerenja=0;
	
	printf("Unesite broj mjerenja: ");
	scanf("%d",&brMjerenja);
	printf("Unesite temperature: ");
	for(i=0;i<8;i++) {
		scanf("%f",&temperature[i]);
	}
	
	printf("Maksimalna temperatura: %.1f\n",maxtemp(temperature,brMjerenja));
	printf("Prosjecna temperatura: %.1f",prtemp(temperature,brMjerenja));
	
	return 0;
}
