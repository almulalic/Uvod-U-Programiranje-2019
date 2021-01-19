#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int uporedi(char string1[],char string2[]) {
	
	char *prvi=&string1[0];
	char *drugi=&string2[0];
	
	while(*prvi == *drugi) {
        if(*prvi!=*drugi)
            return 0;
        else if(*prvi=='\0' && *drugi=='\0')
        	break;
        prvi++;
        drugi++;
   }
    
    if(*prvi=='\0' && *drugi=='\0')
        return 1;
    else {
        return 0;
    }
    
	return 0;
}


int main() {
	
	FILE *ulaz;
	int predmetId,prolaznost=0;
	double prosjecnaOcjena=0;
	int brojacOcjena=0,brojacIndeksa=0;
	int index,predmet,ocjena,validanPredmet=0;
    char nazivPredmeta[40],unosPredmeta[40];
    int validanUnos=0;
    
    
	while(validanUnos!=1){
		
		printf("Unesite predmet: "); 
		unesi(unosPredmeta,40);
		
		ulaz = fopen("predmeti.txt","r");
	 
		if(ulaz==NULL) {
			printf("Greska u otvaranju datoteke predmeti.txt");
			return 1;
		}
		
		while(fscanf(ulaz,"%d %[^\n]",&predmetId,nazivPredmeta)==2) {
			if(uporedi(unosPredmeta,nazivPredmeta)){
				validanUnos=1;
				break;
			}
		}
		
		fclose(ulaz);
		
		if(!validanUnos)
			printf("Nepostojeci predmet!\n");
	}
	
	ulaz=fopen("ispiti.txt","r");
	
	while (fscanf(ulaz,"%d %d %d",&index,&predmet,&ocjena) == 3) {
		
		if(predmet == predmetId) {
			prosjecnaOcjena+=ocjena;
			brojacOcjena++;
			
			if(ocjena >= 6) 
				prolaznost++;
	
			validanPredmet=1;
		}
		
		brojacIndeksa++;
		
	}
	
	fclose(ulaz);
	
	if(validanPredmet) {
		printf("Prosjecna ocjena: ");
		printf("%.2f\n",prosjecnaOcjena/brojacOcjena);
		printf("Prolaznost: ");
		printf("%g%%",((double)prolaznost/(double)brojacOcjena)*100.);
	} else { 
		printf("Zalimo, ali ne postoje podaci o predmetu %s!",unosPredmeta);
	}
	
	return 0;
}
