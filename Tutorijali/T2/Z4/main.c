#include <stdio.h>

int main() {
	
	int broj1,broj2,broj3;
	int temp;
	
	printf("Unesite tri broja: "); 
	scanf("%d %d %d",&broj1,&broj2,&broj3);
	
	if((broj1 < 50 || broj1 > 200  ) || (broj2 < 50 || broj2 > 200  ) || (broj3 < 50 || broj3 > 200  )){
		printf("Svi brojevi nisu iz intervala 50 do 200\n");
		return 1;
	}
	
	if ((broj2 < broj1) && (broj2 < broj3)) {
		temp = broj1;
		broj1 = broj2;
		broj2 = temp;
	} else if ((broj3 < broj1) && (broj3 < broj1)){
		temp = broj1;
		broj1 = broj3;
		broj3 = temp;
	}
	
	if(broj2 > broj3) {
		temp = broj2;
		broj2 = broj3;
		broj3 = temp;
	} 
	
	printf("Brojevi poredani po velicini glase: %d,%d,%d\n",broj1,broj2,broj3);
	
	if(((broj1 != broj2) && (broj2 != broj3)))
		printf("Unesena su 3 razlicita broja"); 
	else if(((broj1 != broj2 && broj2 == broj3)) || ((broj1 == broj2) && broj2 != broj3) || ((broj1 == broj3) && (broj2 != broj3)))
		printf("Unesena su 2 razlicita broja");
	else
		printf("Unesen je 1 razlicit broj");

	
	
	return 0;
}
