#include <stdio.h>

char *izbaci_viska_razmake (char *str) {
	
	char *pocetak = str;
	
	while(*str==' ') {
		str++;
		pocetak++;
	}
	
	char *pocetakRazmaka;
	char *krajRazmaka;
	
	while(*str != '\0') {
		
		if(*str==' ' && *(str+1)==' ') {
			*str=*(str+1);	
		}
		
		str++;
	}
	
	return pocetak;
}

int main() {
	
	printf("%s",izbaci_viska_razmake("   volim           OR   "));
	
	return 0;
}
