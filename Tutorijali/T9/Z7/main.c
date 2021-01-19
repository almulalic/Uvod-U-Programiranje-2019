#include <stdio.h>
#include <math.h>

int strcmpi(const char *s1, const char *s2,int velikamala) {

	while (*s1!='\0' && *s2!='\0') {

		if(velikamala==0) {
			if(*s1>*s2 && round(*s1-*s2)!='a'-'A')
				return 1;
			if(*s1<*s2 && round(*s1-*s2)!='a'-'A')
				return -1;
		}

		if(velikamala==1) {

			if(*s1<*s2)
				return -1;
			if(*s1>*s2)
				return 1;
		}

		s1++;
		s2++;
	}

	if(*s1>*s2)
		return 1;

	if(*s1<*s2)
		return -1;

	return 0;
}

int main() {

	return 0;
}
