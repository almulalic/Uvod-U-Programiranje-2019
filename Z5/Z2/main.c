#include <stdio.h>
#include <string.h>

struct Planina {
    char naziv[51];
    int visina;
};

int testirajNaziv(char *naziv) {
   
    while(*naziv!='\0') {
        if(*naziv=='a' || *naziv=='A')
            return 1;
        naziv++;
    }
    
    return 0;
}

int ucitaj(struct Planina planine[1000],int duzinaUcitanih) {
    
    FILE *ulaz;
    int i=0;
    
    ulaz=fopen("planine.txt","r");
    
    if(ulaz==NULL) {
        printf("Greska pri ucitavanju datoteke planine.txt");
        return 0;
    } 
    
     while(i<duzinaUcitanih) {
        if(fscanf(ulaz,"%d%*[ ]%[^\n]",&planine[i].visina,planine[i].naziv)==2) {
            i++;
        } else if(fscanf(ulaz,"%[a-zA-Z ]%d",planine[i].naziv,&planine[i].visina)==2) {
            planine[i].naziv[strlen(planine[i].naziv)-1] = '\0';
            i++;
        } else 
            return i;
    }
    
    fclose (ulaz);
    
    return i;
}

int zapisi(struct Planina planine[1000],int duzina) {
    
    FILE *izlaz;
    int i=0;
    
    izlaz=fopen("planine.dat","wb");
    
    if(izlaz==NULL) {
        printf("Greska pri ucitavanju binarne datoteke planine.dat");
        return 1;
    } 

    fwrite(planine, sizeof(struct Planina), duzina, izlaz); 
    
    fclose(izlaz);
    return 0;
}

void ispis(struct Planina planine[1000],int duzina) {
    int i=0,indeks=0;
    int maxVisina = 0;
    
    for(i=0;i<duzina;i++) {
        if(planine[i].visina < 2000) {
            maxVisina=planine[i].visina;
            break;
        }
    }
    
    for(i=0;i<duzina;i++) {
        if(testirajNaziv(planine[i].naziv) == 1 && planine[i].visina < 2000 && planine[i].visina > maxVisina) {
            indeks=i;
            maxVisina = planine[i].visina;
        }
    }
    
    printf("%s %d\n",planine[indeks].naziv,planine[indeks].visina);
}

int main() {
    
    struct Planina planine[1000];
    int duzinaUcitanih=0;

    duzinaUcitanih = ucitaj(planine,1000);
    zapisi(planine,duzinaUcitanih);
    ispis(planine,duzinaUcitanih);

    // int i;
    // printf("\n\n");
    // for(i=0;i<duzinaUcitanih;i++) {
    //     printf("%s %d\n",planine[i].naziv,planine[i].visina);
    // }
    
    return 0;
}