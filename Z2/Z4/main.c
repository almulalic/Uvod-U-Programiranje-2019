#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define epsilon 0.00000001
#define brojJela 26

int main() {
    
    int i,j,k,greska=0,indexNajmanjeKombinacijeJ=0,indexNajmanjeKombinacijeK=0;
    float cijeneJela[brojJela];
    float kombinacije[26][26]={0};
    int narucenaJela[100],unosJela,brojNarucenihJela=0;
    int brojacJela=0,prvoJelo=0,drugoJelo=0,provjeraJela=0;
    float unosCijena,cijena=0,cijenaKombinacije=0,najmanjaKombinacija=0,najvecaKombinacija=0;
    
    cijeneJela[0]=0;
	for(i=1;i<26;i++) {
	    scanf("%f",&unosCijena);
	    if(unosCijena < 0)
	        i--;
	    else
	        cijeneJela[i]=unosCijena;
	        
	}


	do {
		printf("Unesite kombinaciju: ");
		scanf("%d",&provjeraJela);
		
		if(provjeraJela==0)
			break;
		else {
			
			prvoJelo=provjeraJela;
		
			scanf("%d %f",&drugoJelo,&cijenaKombinacije);
			
			if((prvoJelo < 1 || prvoJelo > brojJela) || (drugoJelo < 1 || drugoJelo > brojJela ) || prvoJelo==drugoJelo || fabs(0-kombinacije[prvoJelo][drugoJelo]) > epsilon  || fabs(0-kombinacije[drugoJelo][prvoJelo]) > epsilon || cijenaKombinacije >= cijeneJela[prvoJelo] + cijeneJela[drugoJelo])
			  	printf("Neispravna kombinacija!\n");
			else if(fabs(kombinacije[prvoJelo-1][drugoJelo-1]) - cijenaKombinacije < epsilon){
				kombinacije[prvoJelo][drugoJelo] = cijenaKombinacije;
				kombinacije[drugoJelo][prvoJelo] = cijenaKombinacije;
				
				if(cijenaKombinacije>najvecaKombinacija)
					najvecaKombinacija=cijenaKombinacije;
					
			}
		}
		
	} while(prvoJelo!=0);
	
	do {
		
		cijena = 0;
		
		do {
			
			printf("Unesite racun: ");
			brojNarucenihJela=0;
			greska=0;
			
			for(i=0;i<100;i++) {
				
				scanf("%d",&unosJela);
				
				if(unosJela == 0 && i==0)
					return 0;
				else if (unosJela == 0 && i!=0)
					break;
				else if(unosJela < 0 || unosJela > 25 || fabs(0-cijeneJela[unosJela]) < epsilon) {
					printf("Jelo nije u ponudi\n");
					greska=1;
				} else
					narucenaJela[i] = unosJela;
					
				brojNarucenihJela++;
			}
			
		} while(greska!=0);
		
		
		i=0;
		brojacJela=0;
		
		while(brojacJela < brojNarucenihJela) {
			
			j=0,k=0;
			indexNajmanjeKombinacijeJ=-1;
			najmanjaKombinacija=najvecaKombinacija;
			
			while(j<brojNarucenihJela) {
				
				if(narucenaJela[i] != 0 && narucenaJela[j] != 0) {
		
					if(fabs(0-kombinacije[narucenaJela[i]][narucenaJela[j]]) > epsilon  ) {
						
						if(kombinacije[narucenaJela[i]][narucenaJela[j]] <= najmanjaKombinacija) {
							najmanjaKombinacija = kombinacije[narucenaJela[i]][narucenaJela[j]];
							indexNajmanjeKombinacijeJ=j;
						} 
					}
				}
				
				j++;
			}
			
			indexNajmanjeKombinacijeK=-1;
			
			while(k<brojNarucenihJela) {
				
				if(narucenaJela[k] != 0 && narucenaJela[i] != 0) {
		
					if(fabs(0-kombinacije[narucenaJela[k]][narucenaJela[i]]) > epsilon  ) {
						
						if(kombinacije[narucenaJela[k]][narucenaJela[i]] <= najmanjaKombinacija) {
							najmanjaKombinacija = kombinacije[narucenaJela[k]][narucenaJela[i]];
							indexNajmanjeKombinacijeK=k;
						} 
					}
				}
				
				k++;
			}
			
			if(indexNajmanjeKombinacije != -1 && indexNajmanjeKombinacijeK == -1) {
				cijena+=najmanjaKombinacija;
				narucenaJela[i]=0;
				narucenaJela[indexNajmanjeKombinacijeJ]=0;
			} else {
				cijena+=najmanjaKombinacija;
				narucenaJela[i]=0;
				narucenaJela[indexNajmanjeKombinacijeK]=0;
			} 
			
			i++;
			brojacJela++;
		}
		
		
	    for(i=0;i<brojNarucenihJela;i++) {
	        if(narucenaJela[i]!=0)
	            cijena+=cijeneJela[narucenaJela[i]];
		}
		
		printf("Ukupan iznos racuna je: %.2f KM\n",cijena);
	
	} while(1);
	
	return 0;
}
