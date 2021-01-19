#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* kapitaliziraj(char *s) {
	
	char* slovo = s;
	
	while(*s!='\0') {
		if(*s>='a' && *s<='z' && (s==slovo || *(s-1)==' ') ) {
			*s=*s-('a'-'A');
		}
		s++;
	}
	
	return slovo;
}

int main() {
	char string[100];
	
	printf("Unesite neki tekst: ");
	unesi(string,40);
	
	kapitaliziraj(string);

	printf("%s",string);
	
	return 0;
}
