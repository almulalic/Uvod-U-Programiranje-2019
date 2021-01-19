#include <stdio.h>

int main() {
	
	double a,b,c,d;
	
	printf("Unesite brojeve a,b,c,d: ");
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	
	if( b < c || a < d )
		printf("Skupovi se ne sijeku.");
	else if( b > c || a > d)
		printf("Rezultantni interval je [%lf,%lf].",b,c);

	
	return 0;
}
