#include <stdio.h>

struct predmet {
	char naziv[20];
	char ime_prezime_nastavnika[20];
	int kabinet;
};

int prebrojPredmete(struct predmet predmeti[10],int duzina) {
	
	int i;
	int brojac=0;
	
	char *s,*p;
	char q,r;
	for(i=0;i<duzina;i++) {
		s=predmeti[i].naziv;
		q=predmeti[i].naziv[0];
		while(*(s+1)!='\0') s++;
		if(q==*s)
			brojac++;
	
	}
	
	return brojac;
}

int main() {
	
	struct predmet predmeti[10] = {{"tests","zjuric",12},{"tests","zjuric",12},{"tests","zjuric",12},{"tests","zjuric",12},{"tests","zjuric",12}};
	
	printf("%d",prebrojPredmete(predmeti,5));
	
	return 0;
}
