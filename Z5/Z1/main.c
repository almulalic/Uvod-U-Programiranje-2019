#include <stdio.h>

struct Klub {
	char ime[50];
	int brojPobjeda;
	int brojNerjesenih;
	int brojPoraza;
	int brojDatihGolova;
	int brojPrimljenihGolova;
	int brojBodova;
	int golRazlika;
};

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

void ispisi(char string[]){
	int i=0;
	while(string[i]) {
		printf("%c",string[i]);
		i++;
	}
}


int izbaciTimove(struct Klub tabela[],int brojTimova) {
	
	int i,j;
	int najvecaGolRazlika,indeksNajveceg=0;
	int tempTimovi=brojTimova;
	
	while(tempTimovi > 0) {
		for(i=0;i<brojTimova;i++) {
			if(tabela[i].brojBodova < 20) {
				for(j=i;j<brojTimova;j++) {
					tabela[j] = tabela[j+1];
				}
				brojTimova--;
			}
		}
		tempTimovi--;
	}

	najvecaGolRazlika = tabela[0].golRazlika;
	
	for(i=1;i<brojTimova;i++) {
		if(tabela[i].golRazlika > najvecaGolRazlika)
			indeksNajveceg = i;
	}

	printf("Najvecu gol razliku ima: \n");
	ispisi(tabela[indeksNajveceg].ime);
	
	return brojTimova;
	
}

int main() {
	
	int i,j,brojTimova=0;
	struct Klub tabela[100];
	struct Klub temp;
	int max;
	
	printf("Unesite broj timova: ");
	scanf("%d",&brojTimova);
	
	for(i=0;i<brojTimova;i++) {
		printf("Unesite naziv %d. tima: ",i+1);
		unesi(tabela[i].ime,50);
		printf("Broj pobjeda: ");
		scanf("%d",&tabela[i].brojPobjeda);
		printf("Broj nerijesenih: ");
		scanf("%d",&tabela[i].brojNerjesenih);
		printf("Broj poraza: ");
		scanf("%d",&tabela[i].brojPoraza);
		printf("Broj datih golova: ");
		scanf("%d",&tabela[i].brojDatihGolova);
		printf("Broj primljenih golova: ");
		scanf("%d",&tabela[i].brojPrimljenihGolova);
		printf("\n");
		tabela[i].brojBodova = (tabela[i].brojPobjeda * 3) + tabela[i].brojNerjesenih;
		tabela[i].golRazlika = tabela[i].brojDatihGolova - tabela[i].brojPrimljenihGolova;
	}
	
	brojTimova=izbaciTimove(tabela,brojTimova);
	
	 for (i=0; i<brojTimova; i++) {
	    max = i;
	    for (j=i; j<brojTimova; j++)
	        if (tabela[j].brojPobjeda*3+tabela[j].brojNerjesenih > tabela[max].brojPobjeda*3+tabela[max].brojNerjesenih) 
	            max = j;
	
	    temp = tabela[i];
	    tabela[i] = tabela[max];
	    tabela[max] = temp;
    }
    
    printf("\nTabela nakon izbacivanja: \n");
    for(i=0;i<brojTimova;i++) {
    	printf("%d. ",i+1);
    	printf("%s\n",tabela[i].ime);
    }
	
	return 0;
}
