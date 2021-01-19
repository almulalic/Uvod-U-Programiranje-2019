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

int prebroji(char* s, char znak) {
    int broj = 0;
    while (*s != '\0') {
        if (*s == znak)
            broj++;
        s++;
    }
    return broj;
}

int samoglasnici(char *s) {
	
	int brojac=0;
	
	while(*s!='\0') {
		
		if(*s == 'a' || *s == 'A' || *s == 'E' || *s == 'e' || *s == 'I' || *s == 'i' || *s == 'O' || *s == 'o' || *s == 'U' || *s == 'u'  ) {
			brojac++;
		}
		
		s++;
	}
	
	return brojac;
}

int main() {
    char a[80],c;
    printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
    unesi(a, 80);
    printf ("\nKoji znak treba prebrojati: ");
    scanf ("%c", &c);
    printf ("\nBroj znakova %c je: %d\n",c,prebroji(a,c));
    printf ("\nBroj samoglasnika je: %d\n",samoglasnici(a));
    return 0;
}
