#include <stdio.h>

int provjeri(int matrica[100][100],int visina){

	int i,j=0;

	if(visina==0)
		return 1;
	else if(matrica[0][0]==-1)
		return 1;
		
		
	for(i=0;i<visina;i++) {
		j=0;
		while(matrica[i][j]!=-1) {
			if(matrica[i][j]<=0 || j==99)
				return 0;
			j++;
		}
	}
	
	return 1;
}

int fibonaci_niz(int niz[100]) {
	
	int i=1,j=0;
	int predhodni=1,trenutni=1;
	
	if(niz[0]==-1)
		return 1;
	
	if(niz[0]==1 && niz[1]==1)
	    j++;
	    
	while(trenutni<=niz[0]) {
	    
	    trenutni+=predhodni;
	    predhodni=i;
		
		i+=trenutni-predhodni;
		
	}
    
	while(niz[j]!=-1) {
	    
	    if(niz[j]!=predhodni || niz[j]==0)
	        return 0;
	        
	    trenutni+=predhodni;
	    predhodni=i;
	    
	    j++;	
		i+=trenutni-predhodni;
	}
	
    return 1;
}

int fibonacci_matrica(int matrica[100][100],int visina) {
	
	int i;
	
	for(i=0;i<visina;i++) {
		if(!fibonaci_niz(matrica[i]))
			return 0;
	}
	
	return 1;
}

int main() {

	
	int matrica[100][100];
	int i,j,unos;
	int V;
	
	do {
		printf("Unesite visinu matrice: ");
		scanf("%d",&V);
	} while(V<=0);
	
	printf("Unesite matricu: ");
	for(i=0;i<V;i++) {
		for(j=0;j<100;j++) {
			scanf("%d",&unos);
			if(unos==-1){
				matrica[i][j]=unos;
				break;
			 }else if(unos<=0)
				j--;
			else
				matrica[i][j]=unos;
		}
	}

	if(provjeri(matrica,V))
		printf("\nMatrica je validna.");
	else 
		printf("\nMatrica nije validna.");
		
	if(fibonacci_matrica(matrica,V))
		printf("\nMatrica je Fibonacci matrica.");
	else
		printf("\nMatrica nije Fibonacci matrica.");
	
	return 0;
}
