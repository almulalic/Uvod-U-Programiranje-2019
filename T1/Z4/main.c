#include <stdio.h>
#define PI 3.14

int main() {
	
	
	double a,b,poluprecnik,visinaKvadar,visinaCilindar,povrsina,zapremina;
	
	printf("Unestie visinu i dimenzije a i b: ");
	scanf("%lf %lf %lf",&visinaKvadar,&a,&b);
	printf("Unesite poluprecnik i visinu valjka: ");
	scanf("%lf %lf",&poluprecnik,&visinaCilindar);
	
	povrsina = (2*(visinaKvadar*a + visinaKvadar*b + a*b)) + (poluprecnik*poluprecnik*PI + 2*poluprecnik*PI*visinaCilindar);
	zapremina = visinaKvadar*a*b + poluprecnik*poluprecnik*PI*visinaCilindar;

	
	printf("\nPovrsina tijela sa slike je %.2f:",povrsina);
	printf("\nZapremina tijela sa slike je : %.2f:",zapremina);
	
	return 0;
}