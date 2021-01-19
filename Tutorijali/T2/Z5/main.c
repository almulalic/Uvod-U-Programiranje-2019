#include <stdio.h>
#include <math.h>


int main() {
	
	double a,b,c;
	double x;
	double derivacija;
	
	printf("Unesite tri koeficijenta");
	scanf("%f,%f,%f",&a,&b,&c);
	
	if((a <= -10 || a>= 10) && (b <= -10 || b >= 10) && (c <= -10 || c >= 10)){
		printf("Koeficijenti a, b i c nisu u zadanom rasponu.");
		return 1;
	}
	
	printf("Unesite tacku x:");
	scanf("%f",x);
	
	
	printf("Prva derivacija u tacki x=%g je %g.",x,derivacija);
	return 0;
}
