#include <stdio.h>
#include <math.h>

#define epsilon 0.00001

double stepenovanje(double baza,double eksponent) {
	
	double i;
	double rezultat=1;
	
	for(i=0;i<eksponent;i++) {
		rezultat*=baza;	
	}
	
	return rezultat;
	
}

int main(){
	
	int korak,ostatak=0;
	double x,y;
	double a,b,n,h;
	double suma=0;
	
	printf("Unesite prvu tacku intervala: ");
	scanf("%lf",&a);
	
	if ( a <= 0 ) {
		printf("Nedozvoljena vrijednost!");
		return 1;
	}
	
	printf("Unesite drugu tacku intervala: ");
	scanf("%lf",&b);
	
	if ( b <= 0) {
		printf("Nedozvoljena vrijednost!");
		return 1;
	}
	
	if(b - a > 100 || fabs(b-a) < epsilon ) {
		printf("Neispravan interval!");
		return 1;
	}
	
	printf("Unesite eksponent: ");
	scanf("%lf",&n);
	
	if(n < -10 || n > 10) {
		printf("Neispravan eksponent!");
		return 1;
	} 
	
	printf("Unesite korak diskretizacije: ");
	scanf("%lf",&h);
	
	
	printf("Korak    x            y = f(x)\n");
	printf("----------------------------------\n");
	
	korak=0;
	for(x=a;x<b;x+=h) {
		
		y=stepenovanje(stepenovanje(x,a),n);
		ostatak=1;
		
		if(korak<4){
			printf("%5d. %.6lf      %10.5lf\n",korak+1,x,y);
			ostatak=0;
		}
		
		suma+=y;
		korak++;
		
	}

	if(ostatak==1){
		printf("(...)\n");
		printf("%5d. %.6lf     %11.5lf\n",korak,x-h,y);
		printf("----------------------------------\n");
	} else 
		printf("\n----------------------------------\n");
		
	
	printf("P(x^%g)[%g,%g]= %.6lf (dx=%g)",n,a,b,suma*h,h);
	
	return 0;
}
