#include <stdio.h>

char max_slovo(char* s) {
	
	int histogram[26],i;
	int max=0;
	char maxSlovo='-';
	
	for(i=65;i<91;i++) {
		histogram[i]=0;
	} 
	
	while (*s != '\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			histogram[(int)*s]++;
		}
		s++;
	}
	
	for(i=0;i<26;i++) {
		if(histogram[i+65] > max) {
			max = histogram[i+65];
			maxSlovo = i;
		}
	}
	
	if(maxSlovo=='-') {
		for(i=0;i<26;i++) {
			if(histogram[i+65]!=0)
				return 65+i;
		}
	}
	
	return 65+maxSlovo;
	
}

int main() {
	
	char s[] = "X";
    printf("%c", max_slovo(s));
 
	return 0;
}
