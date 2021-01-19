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

char* velika(char *s) {
	
	char *pocetak = s;
	
	while(*s!='\0') {
		if(*s>='a' && *s<='z')
			*s=*s-32;
		s++;
	}
	
	return pocetak;
}


int main() {
	
	char string[20];
	
	printf("Unesite string: ");
	
	unesi(string,20);
	
	printf("%s",velika(string));
	
	return 0;
}
