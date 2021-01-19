#include <stdio.h>

float maxtemp(float temp[8]) {

	int i;	
	float max=0;

	for(i=0;i<8;i++) {
		if(temp[i]>max)
			max=temp[i];
	}
	
	return max;
}

float prtemp(float temp[8]) {

	int i;	
	float avg=0;

	for(i=0;i<8;i++) {
		avg+=temp[i];
	}
	
	return avg/8.;
}


int main() {
	
	int i;
	float temperature[8];
	
	printf("Unesite temperature: ");
	for(i=0;i<8;i++) {
		scanf("%f",&temperature[i]);
	}
	
	printf("Maksimalna temperatura: %.1f\n",maxtemp(&temperature[0]));
	printf("Prosjecna temperatura: %.1f",prtemp(&temperature[0]));
	
	return 0;
}
