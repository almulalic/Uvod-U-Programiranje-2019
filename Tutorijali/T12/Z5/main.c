#include <stdio.h>
#include <math.h>

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

struct Student {
	c
}


int main() {
	
	FILE *ulaz;
	int predmetId,indexId,prolaznost=0;
	double prosjecnaOcjena=0;
	int brojacOcjena=0,brojacIndeksa=0;
	int index,predmet,ocjena,validanPredmet=0;
    char nazivPredmeta[40],unosPredmeta[40];
    int validanUnos=0,validanStudent=0;
    int meniOpcija=1,brojPredmeta=0,brojPolozenih=0,polozeni=0;
    
    while(meniOpcija!=0) {
    	
	    printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
	    scanf("%d",&meniOpcija);
	    
	    if(meniOpcija==0)
	    	return 0;
	    	
	    if(meniOpcija==1) {
	    	
	    	printf("Unesite broj indexa: ");
	    	scanf("%d",&indexId);
	    	
	    	ulaz = fopen("ispiti.txt","r");
	 
			if(ulaz==NULL) {
				printf("Pogresan ulaz");
				return 1;
			}
			
			while (fscanf(ulaz,"%d %d %d",&index,&predmet,&ocjena) == 3) {
				
				if(index == indexId) {
				
					if(ocjena>6) {
						polozeni+=ocjena;
						brojPolozenih++;
					}
					
					brojPredmeta++;
					validanStudent = 1;
				}
				
				brojacIndeksa++;
			}
			
			fclose(ulaz);
			
			float prosjecnaOcjenaPolozenih = (float)polozeni/brojPolozenih;
			
			if(validanStudent) {
				printf("Student je slusao %d predmeta, a polozio %d (%d%%).\n",brojPredmeta,brojPolozenih,brojPolozenih/brojPredmeta*100);
				printf("Prosjecna ocjena polozenih predmeta je %.1f\n",prosjecnaOcjenaPolozenih);
			} else { 
				printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!\n",indexId);
			}
	    	
	    }
	    else if(meniOpcija==2) {
	    	
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
			
			if(!validanUnos){
				printf("Nije pronadjen predmet sa nazivom %s",unosPredmeta);
				return 1;
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
				printf("%g%%\n",((double)prolaznost/(double)brojacOcjena)*100.);
			} else { 
				printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!\n",predmetId);
			}
		
	    }
    }
	
	return 0;
}
