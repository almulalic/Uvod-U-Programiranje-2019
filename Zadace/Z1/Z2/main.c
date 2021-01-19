#include <stdio.h>
#include <math.h>

#define epsilon 0.0001

int main() {
	
	double p1,q1,r1;
	double p2,q2,r2;
	
	double p3,q3,dx,dy,rx,ry;
	double d,a,h;
	double p1Presjek,q1Presjek,p2Presjek,q2Presjek;
	
	printf("Unesite koordinate centra kruznice A: ");
	scanf("%lf %lf",&p1,&q1);
	printf("Unesite poluprecnik kruznice A: ");
	scanf("%lf",&r1);
	printf("Unesite koordinate centra kruznice B: ");
	scanf("%lf %lf",&p2,&q2);
	printf("Unesite poluprecnik kruznice B: ");
	scanf("%lf",&r2);
	
	
	dx = p2 - p1;
	dy = q2 - q1;
	d = hypot(dx,dy);

	if(fabs(p1- p2) < epsilon && fabs(q1- q2) < epsilon && fabs(r1- r2) < epsilon)
	    printf("Kruznice su identicne.");
	else if (d < fabs(r1-r2)) 
		printf("Jedna kruznica je sadrzana u drugoj.");
	else if (d > r1+r2)
		printf("Kruznice se ne sijeku.");
	else {
		
		a = (pow(r1,2) - pow(r2,2) + pow(d,2))/(2.0 * d);
		
		h = sqrt((r1*r1) - (a*a));
		
		p3 = p1 + (dx * a/d);
		q3 = q1 + (dy * a/d);
		
		rx = - dy * (h/d);
		ry = dx * (h/d);
		
		
		p1Presjek = p3 + rx;
		q1Presjek = p3 - rx;
		
		p2Presjek = q3 + ry;
		q2Presjek = q3 - ry;
		
		if( fabs(p1Presjek - q1Presjek) < epsilon && fabs(p2Presjek - q2Presjek) < epsilon )
			printf("Kruznice se dodiruju u tacki (%.2lf,%.2lf).",p1Presjek,p2Presjek);
		else
			printf("Kruznice se sijeku u tackama (%.2lf,%.2lf) i (%.2lf,%.2lf).",p1Presjek,p2Presjek,q1Presjek,q2Presjek);	
	
	}
	
	
	return 0;
}
