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

char* rot13(char* s) {
 
 char *poc = s;
 
 while(*s != '\0') {
    if(*s >= 'a' && *s <= 'z') {
        *s = *s + 13 > 'z' ? 'a' + ( *s + 12 - 'z') : *s+13;
    } else if(*s >= 'A' && *s <= 'Z') {
        *s = *s + 13 > 'Z' ? 'A' + ( *s + 12 - 'Z') : *s+13;
    }
    s++;
 }
 
 return poc;
}

int main() {
	char testni_string[] = "Moje ime je medvjedic Lino";
    printf("%s", rot13(testni_string));
	return 0;
}
