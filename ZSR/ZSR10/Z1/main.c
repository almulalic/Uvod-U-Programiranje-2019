#include <stdio.h>

const char* pronadji_posljednji(const char *s) {
	char *pocetakRijeci;
	
	while(*s!='\0') {
		if(*(s-1)==' ') {
			pocetakRijeci=s;
		}
		s++;	
	}
	
	return pocetakRijeci;
}

int main() {
	
	char string[] = "danas je divan dan!";
	
	printf("%s",pronadji_posljednji(string));
	
	
	return 0;
}
