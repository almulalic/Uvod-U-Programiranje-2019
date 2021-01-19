#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* Zbog funkcije exit() */

struct Student {
    char prezime[15];
    char ime[10];
    int broj_bodova1 ;
    int broj_bodova2;
};

struct Usmeni {
    char prezime[15];
    char ime[10];
    int ukupno; 
};

void prepisi(char *prvi,char *drugi,int velicina) {
    
    int brojac=0,i;
    
    while(*drugi!='\0') {
        *prvi=*drugi;
        prvi++;
        drugi++;
        brojac++;
    }
    
    for(i=brojac;i<velicina;i++) 
        *prvi = ' ';
    
    *prvi = '\0';
}

int main() {
    struct Student studenti[300];
    FILE *ulaz, *izlaz;
    int i, j, vel, max;
	struct Usmeni usmeni[300],temp;
	int brojacUsmeni=0;
	
    /* Otvaranje datoteka */
    if ((ulaz = fopen("ispit.bin","rb")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.bin");
        return 1;
    }

    if ((izlaz = fopen("ispit_sortiran.bin","wb")) == NULL) {
        fclose(ulaz);
        printf("Greska pri otvaranju datoteke ispit_sortiran.bin");
        return 1;
    }

    /* Ucitavanje datoteke u niz studenti */
    i=0;
     while (i<300 && fscanf(ulaz,"%15s%10s%2d%2d%\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1 ,&studenti[i].broj_bodova2) == 4)
        i++;
        
    vel = i;
	
	for(i=0;i<vel;i++) {
		if(studenti[i].broj_bodova1  >= 10 && studenti[i].broj_bodova2 >= 10) {
			prepisi(usmeni[brojacUsmeni].prezime,studenti[i].prezime,15);
			prepisi(usmeni[brojacUsmeni].ime,studenti[i].ime,10);
			usmeni[brojacUsmeni].ukupno = studenti[i].broj_bodova1  + studenti[i].broj_bodova2;
			brojacUsmeni++;
		}
	}
    
    /* Sortiranje niza po broju bodova */

    for (i=0; i<brojacUsmeni; i++) {
        max = i;
        for (j=i; j<brojacUsmeni; j++) 
            
            if (usmeni[j].ukupno > usmeni[max].ukupno) 
                max = j;

            temp = usmeni[i];
            usmeni[i] = usmeni[max];
            usmeni[max] = temp;
        
    }

	if ((izlaz = fopen("usmeni.bin","wb")) == NULL) {
        printf("Greska pri otvaranju datoteke usmeni.bin");
        return 1;
    }
    
    // Upis niza u datoteku
    for (i=0; i<brojacUsmeni; i++)
        fprintf(izlaz,"%-15s%-10s%2d\n", usmeni[i].prezime, usmeni[i].ime, usmeni[i].ukupno);

    printf ("Izlazna datoteka usmeni.bin je kreirana\n");
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}
