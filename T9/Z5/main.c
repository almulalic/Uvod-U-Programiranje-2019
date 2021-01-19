#include <stdio.h>
int uporedi(char *prvi,char *drugi) {
   
     while(*prvi++ == *drugi++) {
        if(*prvi!=*drugi)
            return 0;
   }
    
    if(*prvi=='\0' && *drugi=='\0')
        return 1;
    else 
        return 0;
}
int main() {
   //nema main 
	return 0;
}
