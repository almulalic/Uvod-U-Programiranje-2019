#include <stdio.h>
#include <stdlib.h>

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

struct Student {
    char prezime[15];
    char ime[15];
    int broj_bodova1;
    int broj_bodova2;
};


int main() {
	
	FILE *ulaz,*izlaz;
	int meniOpcija=1;
	struct Student student;
	struct Student studenti[100];
	int indexStudenti=0;
	
	while(meniOpcija!=0) {
		
		printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d",&meniOpcija);
		
		if(meniOpcija==0)
			return 0;
		
		if(meniOpcija==1) {
			printf("Unesite ime: ");
			unesi(student.ime,15);
			printf("Unesite prezime: ");
			unesi(student.prezime,15);
			printf("Unesite broj bodova na I parcijalnom: ");
			scanf("%d",&student.broj_bodova1);
			printf("Unesite broj bodova na II parcijalnom: ");
			scanf("%d",&student.broj_bodova2);
		
			// ulaz=fopen("ispiti.txt","w");
			
			// if(ulaz==NULL) {
			// 	printf("Greska pri otvaranju datoteke ispiti.txt");
			// 	exit(1);
			// }
			
			// while(fscanf(ulaz,"%15s %10s %2d %2d",fajlIme,fajlPrezime,&fajlBodovi1,&fajlBodovi2)==4) {
				
			// }
			
			
			// fclose(ulaz); - U slucaju provjere duplikata korisno je imati spreman dio koda
			
			izlaz = fopen("ispit.txt","a");
			if (izlaz == NULL) {
        		printf("Greska pri otvaranju datoteke ispiti.txt");
        		return 1;
    		}
 
        	fprintf(izlaz,"%-20s%-15s%2d %2d\n", student.prezime,student.ime,student.broj_bodova1,student.broj_bodova2);
        	fclose(izlaz);
			
		} else if(meniOpcija==2) {
			
			printf("\n");
			ulaz=fopen("ispit.txt","r");
			
			if (ulaz == NULL) {
			    printf("Datoteka ne postoji!");
			    return 0;
			}
			
			while(fscanf(ulaz,"%20s%15s%2d%2d\n",studenti[indexStudenti].prezime,studenti[indexStudenti].ime,&studenti[indexStudenti].broj_bodova1,&studenti[indexStudenti].broj_bodova2) != EOF){ 
				printf("%d. %s %s - %d, %d\n",indexStudenti+1,studenti[indexStudenti].ime,studenti[indexStudenti].prezime,studenti[indexStudenti].broj_bodova1,studenti[indexStudenti].broj_bodova2);
				indexStudenti++;
			}
			
			fclose(ulaz); 
		}
		
	
	}
	
	
	return 0;
}
