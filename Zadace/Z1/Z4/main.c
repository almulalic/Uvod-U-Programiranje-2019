#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define kalorijeZaKilogram 7000

int main() {
	
	double visina=0,obimStruka=0,masa=0;
	int treningOpcija=0;
	int brojKilograma=0;
	char spol=0;
	
	int greska=0;
	
	double BMI=0,RFM=0;
	int minimalanBrojSedmica=0;
	
	
	 do {
		
		greska = 0;
		
		printf("Unesite spol (mM/zZ), visinu (u cm), obim struka (u cm), tezinu (u kg): ");
		scanf(" %c %lf %lf %lf", &spol,&visina,&obimStruka,&masa);
		
		if(spol!= 'M' && spol!='m' && spol!= 'Z' && spol!='z'){
			printf("\nGreska u unosu za spol.\n");
			greska = 1;
		} else if ((visina<100 || visina > 220) || (obimStruka < 40 || obimStruka > 200) || masa > 200) {
			printf("\nGreska u unosu atributa.\n");
			greska = 2;
		} 
	
		
	} while (greska != 0);
	
	
	do {
		
		printf("Odaberite zeljenu opciju za trening:\n");
		printf("[1] Joga\n");
		printf("[2] Joga PLUS\n");
		printf("[3] Cardio\n");
		printf("[4] Super cardio\n");
		printf("[5] Total Body\n");
		printf("[6] Body Builder\n");
		printf(">> ");
		scanf("%d",&treningOpcija);
		
		if(treningOpcija < 1 || treningOpcija > 6) 
			printf("Greska u odabiru opcija.\n");
		
	} while(treningOpcija < 1 || treningOpcija > 6);
	
	
	printf("Unesite broj kilograma za koliko zelite smanjiti svoju masu (1-10): ");
	
	do {
		
		scanf("%d",&brojKilograma);
	
		if(brojKilograma < 0 || brojKilograma > 10) 
			printf("\nGreska u unosu za kilazu. Ocekivane vrijednosti: (0-10).\n");
	
	} while(brojKilograma < 0 || brojKilograma > 10);
	
		
	if(spol == 'M' || spol == 'm')
		RFM = 64 - (20 * (visina/obimStruka));
	else if(spol == 'Z' || spol == 'z')
		RFM = 76 - (20 * (visina/obimStruka));
	
	visina/=100;
	
	BMI = masa/(visina*visina);
	
	if(treningOpcija == 1) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (200. * 5);
	} else if(treningOpcija == 2) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (300. * 5);
	} else if(treningOpcija == 3) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (400. * 5);
	} else if(treningOpcija == 4) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (500. * 5);
	} else if(treningOpcija == 5) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (600. * 5);
	} else if(treningOpcija == 6) {
		minimalanBrojSedmica = (kalorijeZaKilogram * brojKilograma) / (600. * 5);
	} 
	

	if( (masa - brojKilograma) / (visina*visina) <= 18.5 && treningOpcija > 2) {
		printf("Odabrani program nije preporucen uz predate podatke.");
		return 1;
	}
	
	printf("Vas BMI iznosi: ");
	
	visina*=100;
	
	if(BMI < 18.5)
		printf("%.2lf (nizak).",BMI);
	else if(BMI >= 18.5 && BMI < 25)
		printf("%.2lf (normalan).",BMI);
	else if(BMI >= 18.5 && BMI < 30)
		printf("%.2lf (povisen).",BMI);
	else if(BMI > 30)
		printf("%.2lf (visok).",BMI);
		
		
	printf("\nVas RFM iznosi: %.2lf %%.",RFM);
	
	if(BMI > 18.5)
		printf("\nMinimalni broj sedmica za treniranje: %d.",minimalanBrojSedmica);
	
	return 0;
}
