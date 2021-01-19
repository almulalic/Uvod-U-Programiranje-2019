#include <stdio.h>
#include <math.h>

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

double parsirajOperaciju(int broj1,int broj2, int kodOperacije) {
    switch(kodOperacije) {
        case -1:
        return broj1-broj2;
        case -2:
        return pow(broj1,broj2);
        case -3:
        return broj1*broj2;
        case -4:
        return broj1/broj2;
        case -5:
        return broj1+broj2;
        case -6:
        return broj1-broj2;
    }
    
    return 0;
}

int izracunaj(char* izraz,int* ok) {
	
	int suma,i=0,j=0,djelilac=1,_broj=0,operand=-1,preznak=1;
	int brojevi[200],indexBrojevi=0;
	int operacije[200],indexOperacije=0;
	int cifre[100];
	char* broj;
	int finalnaSuma=0;

	
	while(*izraz != '\0') {
	
		if(*izraz >= '0' && *izraz <= '9') {
			broj=izraz;
			i=0;
			j=0;
			_broj=0;
			djelilac=1;
			preznak = (*(izraz-1) == '-' && (*(izraz-2) == '-' || *(izraz-2)=='+' ) || (*(izraz-1) == '-' && indexBrojevi==0)) ? -1:1;
			
			i=0;
			while(*broj>='0' && *broj<='9') {
				cifre[i]=*broj-'0';
				i++;
				broj++;
			}
			
			j=i-1;
			while(j>=0) {
				_broj+=cifre[j]*djelilac;
				djelilac*=10;
				j--;
			}
			
			brojevi[indexBrojevi]=_broj*preznak;
			indexBrojevi++;
			izraz+=(i-1);
		} else if(*izraz=='-' && *(izraz+1)=='-') {
		    operacije[indexOperacije]=-1;
		    indexOperacije++;
		} else if(*izraz=='^' ) {
		    operacije[indexOperacije]=-2;
		    indexOperacije++;
		} else if(*izraz=='*' ) {
		    operacije[indexOperacije]=-3;
		    indexOperacije++;
		} else if(*izraz=='/' ) {
		    operacije[indexOperacije]=-4;
		    indexOperacije++;
		} else if(*izraz=='+' ) {
		    operacije[indexOperacije]=-5;
		    indexOperacije++;
		} else if(*izraz=='-' && indexBrojevi!=0) {
		    operacije[indexOperacije]=-6;
		    indexOperacije++;
		} 
		
		izraz++;	
		preznak=1;
		
	}
	
	if(indexOperacije!=indexBrojevi-1){
		*ok=0;
		return 0;
	}
    
    do {
	    i=0;
	    while(i<indexOperacije) {
	        
	       if(operacije[i]==operand && operand!=-1) {
	     
	            brojevi[i+1]=parsirajOperaciju(brojevi[i],brojevi[i+1],operand);;
	            
	            for(j=i;j<indexBrojevi;j++) 
	                brojevi[j]=brojevi[j+1];
	           
	           for(j=i;j<indexOperacije;j++)
	                operacije[j]=operacije[j+1];
	            
	            indexBrojevi--;
	            indexOperacije--;
	            i--;
	    }
	    i++;
	    }
	    operand--;
	} while(operand!=-7);
	
	*ok=1;
	return brojevi[0];
}

int main() {
	
	char string[200];
	int greska;
	
	printf("Unesite string: ");
	unesi(string,200);
	printf("%d",izracunaj(string,&greska));
	
	return 0;
}
