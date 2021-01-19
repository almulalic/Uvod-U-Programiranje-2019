#include <stdio.h>

int jeValidnoSlovo(char slovo) {
    return ((slovo>='a' && slovo<='z') || (slovo>='A' && slovo <= 'Z'));
}

int jeKrajSloga(char *znak) {
    return (*znak == 'A' || *znak == 'a' || *znak == 'E' || *znak == 'e' || *znak == 'I' || *znak == 'i' || *znak == 'O' || *znak == 'o' || *znak == 'U' || *znak == 'u' || *(znak+1) == ' ' || *(znak+1)=='-');
}

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

void upisi(char *prvi,char *drugi) {
   
   while(*prvi !='\0') {
        *drugi=*prvi;
        prvi++;
        drugi++;
   }
   
   *drugi='\0';
}

int prebrojSlova(char *s) {
    
    int brojac=1;
    
    while(*s!='\0') {
        brojac++;    
        s++;
    }
    
    return brojac;
}

void max_slog(char* s,char* rezultat) {
    
    int histogram[100];
    char slogovi[50][50]={'\0'};
    int i,j,k;
    int slova,najveci,histogramBrojac=0;
    int indexSloga=0,indexSlova=0;
    
    while(*s!='\0') {
        
        indexSlova=0;
        
        while(jeValidnoSlovo(*s)) {
            if(*s<'a')
                slogovi[indexSloga][indexSlova]=*s+('a'-'A'); 
            else 
                slogovi[indexSloga][indexSlova]=*s; 
            
            if(jeKrajSloga(s)){
                indexSloga++;
                break;
            } else {
                indexSlova++;       
                s++;
            }
        }
        s++;
    }
    
    indexSloga++;
    
    for(i=0;i<indexSloga;i++) {
        slova=0;
        for(j=0;j<indexSloga;j++) {
            if(uporedi(slogovi[i],slogovi[j])) {
                slova++;
            } 
        }
        for(k=0;k<i;k++) {
            if(uporedi(slogovi[i],slogovi[k])) {
                break;
            }
        }
        if(k==i) {
            histogram[histogramBrojac]=slova;
            histogramBrojac++;
        } else {
            histogram[histogramBrojac]=-1;
            histogramBrojac++;
        }
    }
    
    najveci=0;
    int indexNajveceg=0;
    int isti[100];
    int indexIstih=0;
    for(i=0;i<histogramBrojac;i++) {
        if(histogram[i]>najveci) {
            najveci=histogram[i];
            indexNajveceg=i;
            indexIstih=0;
        } else if(histogram[i]==najveci) {
            isti[indexIstih]=i;
            indexIstih++;
        }
    }
    
    if(indexIstih==0) {
        upisi(slogovi+indexNajveceg,rezultat);
    } else {
            indexIstih++;
            najveci=prebrojSlova(slogovi);
            indexNajveceg=0;
            int max=0;
            
            for(i=0;i<indexIstih;i++) {
                max=prebrojSlova(slogovi+isti[i]);
                if(max > najveci) {
                    najveci=max;
                    indexNajveceg=i;
                }
            }
            
            upisi(slogovi+indexNajveceg+1,rezultat);
    } 
    
    // for(i=0;i<indexIstih;i++)
    //     printf("%s ",slogovi[i]);
        
}

int main() {
    
    char s[100] = "Stoper je podigao prst u zrak";
    char rezultat[100];
    
    max_slog(s,rezultat);
    printf("%s",rezultat);
    return 0;
}
