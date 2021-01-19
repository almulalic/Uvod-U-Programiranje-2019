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

int broj_rijeci(char *s ) {

	char *pocetak=s;
	int duzina=0;
	
	while(*s!='\0') {
		if((*pocetak!=' ' && pocetak==s) || (*s!=' ' && (*(s-1)==' ' || *(s-1)=='.' || *(s-1)==',' || *(s-1)=='-' || *(s-1)=='!' || *(s-1)=='?')) )
			duzina++;
	
		s++;
	}
	
	return duzina;
	
}

char* izbaci_rijec(char *s, int n) {
	char *pocetak = s;
	int brojPronadjenih = 0;
	char *p;
	
	while(*s==' ') s++;
	
	while(*s != '\0') {
		
		if(s==pocetak || (*(s-1)==' ' && *s>='a' && *s) || *(s+1)=='\0'){
			brojPronadjenih++;
			
			if(brojPronadjenih == n)
				p = s;
			
			if(brojPronadjenih==n+1) {
				while(*p++=*s++);
				return pocetak;
			}
			
		}
				
		s++;	
	}
	
	return pocetak;
}

int main()
{

	char string[50];
	int broj;

	printf("Unesite recenicu: ");
	unesi(string,50);
	printf("Unesite broj: ");
	scanf("%d",&broj);

	printf("%s",izbaci_rijec(string,broj));

	// duz=duzina(string);
	// if ((broj==1) || (broj>duz))
	// 	return 1;
	// else
	// printf("Sada glasi: %s",izbaci_rijec(string,broj));
	
	
	return 0;
}
