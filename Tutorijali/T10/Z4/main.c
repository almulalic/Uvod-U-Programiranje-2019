
#include <stdio.h>

void unesi(char* string) {
    
    char znak = getchar();
    int i=0;
    
    if (znak == '\n') znak=getchar();
    while (i < 200-1 && znak != '\n') {
        string[i] = znak;
        i++;
        znak = getchar();
    }
    string[i]='\0';

}

char* whitespace (char* s)
{
	int i=0;
	int j=0;
	char* p=s;
	char *q=s;
	
	while (*p == ' ' || *p == '\t' || *p == '\n') p++;
	while (*p != '\0') *s++=*p++;
	*s='\0';
	
	if (s!=q) {
		s--;
		while(*s == ' ') s--;
		s++;
		*s = '\0';
	}
	
	s=q;
	p=q;

	while (*(s+i) != '\0') {
		if (*(s+i)==' ' || *(s+i)=='\t' || *(s+i)=='\n') {
			*(s+i) = ' ';
			 j = i+1;
			while (*(s+j)==' ' || *(s+j)=='\t' || *(s+j)=='\n')
				j++;
			if (j != i+1) {
				do {
					*(s+i+1)=*(s+j);
					s++;
				} while (*(s+i+1)!='\0');
				*(s+i)='\0';
			}
			s = p;
		}
		i++;
	}
	return p;
}

int main()
{
	char recenica[50];
	
	printf("Unesite recenicu:");
	unesi(recenica);
	printf("\nRecenica:%s", whitespace(recenica));
	return 0;
}
