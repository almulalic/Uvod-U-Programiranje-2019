#include <stdio.h>
#include <math.h>

#define epsilon 0.0001

double f(double x) { return x*x-2*x+3; }
double g(double x) { return 2*x; }

double presjek(double A,double B,int* status) {
	
	double h;
	double ha,hb,hh;
	double i,t;
	
	h=((A+B)/2);
	ha=f(A)-g(A);
	hb=f(B)-g(B);
	hh=f(h)-g(h);
	
	if(fabs(g(A)-f(A)) < epsilon && fabs(g(B)-f(B)) < epsilon && fabs(g(h)-f(h)) < epsilon) {
		*status=2;
		return 0;
	} else if(fabs(g(A)-f(A)) < epsilon) {
		*status=0;
		return A;
	} else if(fabs(g(B)-f(B)) < epsilon) {
		*status=0;
		return B;
	} else if(fabs(g(h)-f(h)) < epsilon) {
		*status=0;
		return h;
	}
	
	if((ha<0 && hh>0) || (ha>0 && hh<0)) {
		
		for(i=A;i<h;i+=0.000001) {
			t=fabs(f(i)-g(i));
			
			if(t<epsilon) {
				*status=0;
				return i;
			}
		}
		
	}
	
	if((hh<0 && hb>0) || (hh>0 && hb <0)) {
		
		for(i=h;i<=B;i+=0.000001) {
			t=fabs(f(i)-g(i));
			
			if(t<epsilon) {
				*status=0;
				return i;
			}
		}
	}
	
	for(i=h;i<B;i+=0.01) {
		t = fabs(f(i)-g(i));
		
		if(t<epsilon) {
			*status=0;
			return i;
		}
	}
	
	for(i=A;i<h;i+=0.01) {
		t = fabs(f(i)-g(i));
	
		if(t<epsilon) {
			*status=0;
			return i;
		}
	}
	
	*status = 1;
	return 0;

}

int main() {
	
	int status=-1;
	double rez = presjek(0, 100, &status);
	printf("%.3f %d\n", rez, status);
	
	return 0;
}
