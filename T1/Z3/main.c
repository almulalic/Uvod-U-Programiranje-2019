#include <stdio.h>
#include <math.h>


int main() {
	
	double x1,y1,z1;
	double x2,y2,z2;
	
	double x;
	
	printf("Unesite koordinate prve tacke T1 (x1,y1,z1): ");
	scanf("%lf %lf %lf",&x1,&y1,&z1);
	printf("Unesite koordinate prve tacke T2 (x2,y2,z2): ");
	scanf("%lf %lf %lf",&x2,&y2,&z2);
	
	x=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
	
	printf("Udaljenost izmedju tacke T1 i T2 je : %lf",x);
	
	
	return 0;
}
