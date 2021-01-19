#include <stdio.h>
#include<stdlib.h>

#define limit 301

int main() {
    
    
    char sabitPogodak,fadilaPogodak,bufferDump;
    
    int bonus=0 , brojStrelica = 0;
    
    int sabitZbir=0,fadilaZbir=0;

    printf("Unesite pogotke za Sabita: ");   
    
    do {
        
        scanf(" %c",&sabitPogodak);
        
        if((sabitPogodak != 'S' && sabitPogodak != 'D' && sabitPogodak != 'T' && sabitPogodak != 'X' && sabitPogodak != 'O' && sabitPogodak != 'I') && (sabitPogodak < 49 || sabitPogodak > 57) && sabitPogodak != '.' && brojStrelica != 9){
            
            printf("Neispravni ulazni podaci.\n");
            printf("Unesite pogotke za Sabita: "); 
            scanf("%s",&bufferDump);
            fflush(stdin);
            sabitZbir = 0;

        } else {
            
            if(sabitPogodak == 'S') {
                bonus = 1;
            } else if(sabitPogodak == 'D') {
                bonus = 2;
            } else if(sabitPogodak == 'T') {
                bonus = 3;
            } else if(sabitPogodak == 'X') {
                sabitZbir += 0;
                brojStrelica++;
            } else if(sabitPogodak == 'O') {
                sabitZbir += 25;
                brojStrelica++;
            } else if(sabitPogodak == 'I') {
                sabitZbir += 50;
                brojStrelica++;
            }
            
            if(sabitPogodak >= 49 && sabitPogodak <= 57) {
                sabitZbir += bonus * (sabitPogodak - 48);
                brojStrelica++;
            }
            
        }

    } while(sabitPogodak != '.');
    
    
    printf("Unesite pogotke za Fadilu: ");
    
    brojStrelica = 0;  
           
    do {
        
        scanf(" %c",&fadilaPogodak);
        
        if((fadilaPogodak != 'S' && fadilaPogodak != 'D' && fadilaPogodak != 'T' && fadilaPogodak != 'X' && fadilaPogodak != 'O' && fadilaPogodak != 'I') && (fadilaPogodak < 49 || fadilaPogodak > 57) && fadilaPogodak != '.' && brojStrelica != 9) {
            
            printf("Neispravni ulazni podaci.\n");
            printf("Unesite pogotke za Fadilu: "); 
            scanf("%s",&bufferDump);
            fflush(stdin);
            fadilaZbir = 0;

        } else {
            
            if(fadilaPogodak == 'S') {
                bonus = 1;
            } else if(fadilaPogodak == 'D') {
                bonus = 2;
            } else if(fadilaPogodak == 'T') {
                bonus = 3;
            } else if(fadilaPogodak == 'X') {
                fadilaZbir += 0;
                brojStrelica++;
            } else if(fadilaPogodak == 'O') {
                fadilaZbir += 25;
                brojStrelica++;
            } else if(fadilaPogodak == 'I') {
                fadilaZbir += 50;
                brojStrelica++;
            }
            
            if(fadilaPogodak >= 49 && fadilaPogodak <= 57) {
                fadilaZbir += bonus * (fadilaPogodak - 48);
                brojStrelica++;
            }
            
        }

    } while(fadilaPogodak != '.');
    
    
    if(sabitZbir > 301 && fadilaZbir > 301) {
        printf("Oba igraca su premasila potrebni broj poena, rezultat je nerijesen.");
        return 0;
    }
    
    printf("Sabit je ");
        
    if(sabitZbir <= limit)
        printf("ostvario %i poena",sabitZbir);
    else
        printf("premasio potrebni broj poena");
    
    printf(", Fadila je ");
    
    if(fadilaZbir <= limit)
        printf("ostvarila %i poena. ",fadilaZbir);
    else
        printf("premasila potrebni broj poena. ");
    

    if((sabitZbir > fadilaZbir && sabitZbir <= limit) || (fadilaZbir > limit))
        printf("Pobjednik je Sabit, kojem je ostalo jos %i poena do pobjede.", limit-sabitZbir);
    else if((fadilaZbir > sabitZbir && fadilaZbir <= limit) || (sabitZbir > limit))
        printf("Pobjednik je Fadila, kojoj je ostalo jos %i poena do pobjede.", limit-fadilaZbir);
    else 
        printf("Rezultat je nerijesen.");
        
    return 0;
}
