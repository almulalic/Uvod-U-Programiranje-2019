#include <stdio.h>

const char* pronadji_posljednji(const char *s) {
	char *pocetakRijeci;
	
	while(*s!='\0') {
		if(*(s-1)==' ' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
			pocetakRijeci=s;
		}
		s++;	
	}
	
	char *posljenja = pocetakRijeci;
	
	while(*posljenja != '\0') {
		if(*posljenja==' ') 
			*posljenja='\0';
		
		posljenja++;
	}
	
	return pocetakRijeci;
}

int main() {
	
	char string[] = "danas je divan  dan!                    ";
	
	printf("%sa",pronadji_posljednji(string));
	
	return 0;
}
