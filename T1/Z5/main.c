#include <stdio.h>

int main() {
	
	double VTpotrosnja,MTpotrosnja;
	double VTcijena,MTcijena;
	
	double ukupnaPotrosja,novcaniIznos,udioVT,udioMT;
	
	printf("Unesite potrosnju u Velikoj Tarifi: ");
	scanf("%lf",&VTpotrosnja);
	printf("Unesite potrosnju u Maloj Tarifi: ");
	scanf("%lf",&MTpotrosnja);
	printf("Unesite cijenu u Velikoj Tarifi: ");
	scanf("%lf",&VTcijena);
	printf("Unesite cijenu u Maloj Tarifi: ");
	scanf("%lf",&MTcijena);
	
	ukupnaPotrosja = VTpotrosnja + MTpotrosnja;
	udioVT = (VTpotrosnja/ukupnaPotrosja)*100;
	udioMT = (MTpotrosnja/ukupnaPotrosja)*100;
	novcaniIznos = (VTpotrosnja * VTcijena) + (MTpotrosnja * MTcijena);
	
	printf("\nUkupna potrosnja je: %.2lf KWh" , ukupnaPotrosja);
	printf("\nUdio velike tarife u ukupnoj potrosnji je %g %%" , udioVT);
	printf("\nUdio male tarife u ukupnoj potrosnji je %g %%", udioMT);
	printf("\nUkupna potrosnja je: %.2lf KM",novcaniIznos);
	
	return 0;
}
