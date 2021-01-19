#include <stdio.h>
#include <math.h>

#define epsilon 0.0001

int jeValidanBroj(char *broj) {
    return (*broj >= '0' && *broj <= '9');
}

char* nadji_zbir(char *s) {
    
    char *broj;
    float _broj;
    int i;
    int indexTacke=1,indexCifri;
    int cifre[100];
    float djelilac=1;
    float brojevi[100];
    int indexBrojeva=0;
    int predznak=1;
    char *prvi,*drugi;
    int pokIndex=0;
    
    while(*s!='\0') {
        
        if(jeValidanBroj(s)) {
            broj=s;
            indexCifri=0;
            _broj=0;
            djelilac=1;
            predznak = *(broj-1)=='-' ? -1:1;
            
            if(pokIndex==0) {
                 
                if(predznak==-1)
                    prvi = (broj-1);
                else
                    prvi=broj;
            } else if (pokIndex==1) {
                
                if(predznak==-1)
                    drugi = (broj-1);
                else
                    drugi=broj;
            }
                
            while(jeValidanBroj(broj) || *broj=='.') {
                
                if(*broj=='.'){
                    cifre[indexCifri]=-1;
                    indexTacke=indexCifri;
                } else
                    cifre[indexCifri]=*broj-'0';
                
                indexCifri++;
                broj++;
                s++;
            }
            
            for(i=indexTacke-1;i>=0;i--) {
                _broj+=cifre[i]*djelilac;
                djelilac*=10;
            }
            
            djelilac=0.1;
            for(i=indexTacke+1;i<indexCifri;i++) {
                _broj+=cifre[i]*djelilac;
                djelilac/=10;
            }
            
            brojevi[indexBrojeva]=_broj*=predznak;
            
            if(indexBrojeva==2) {
                if(fabs(brojevi[0]+brojevi[1]-brojevi[2])<epsilon){
                    indexBrojeva=0;
                    pokIndex=0;
                    return prvi;
                } else {
                    indexBrojeva=0;
                    pokIndex=0;
                    return nadji_zbir(drugi);
                }
            }
            
            indexBrojeva++;
            pokIndex++;
        }
        
        s++;
    }
    
    return NULL;
}

int razlike (char *s) {
    
    char *pocetak;
    pocetak=nadji_zbir(s);
    char *broj;
    float _broj;
    int i;
    int indexTacke=0,indexCifri;
    int cifre[100];
    float djelilac=1;
    float brojevi[100];
    int indexBrojeva=0;
    int predznak=1;
    int pokIndex=0;
    char *drugi;
    
    while(*pocetak!='\0') {
        
        if(jeValidanBroj(pocetak)) {
            broj=pocetak;
            indexCifri=0;
            _broj=0;
            djelilac=1;
            predznak = *(broj-1)=='-' ? -1:1;
            
            if(pokIndex==1) {
                pokIndex++;
                if(predznak==-1)
                    drugi=broj-1;
                else
                    drugi=broj;
            }
            
            while(jeValidanBroj(broj) || *broj=='.') {
                
                if(*broj=='.') {
                    cifre[indexCifri]=-1;
                    indexTacke=indexCifri;
                } else 
                    cifre[indexCifri]=*broj-'0';
                    
                indexCifri++;
                broj++;
                pocetak++;

            }   
            
            for(i=indexTacke-1;i>=0;i--) {
                _broj+=cifre[i]*djelilac;
                djelilac*=10;
            }
            
            djelilac=0.1;
            for(i=indexTacke+1;i<indexCifri;i++) {
                _broj+=cifre[i]*djelilac;
                djelilac/=10;
            }
            
            brojevi[indexBrojeva]=_broj*=predznak;
            
            if(indexBrojeva==1) {
                printf("%g - %g = %g\n",brojevi[0],brojevi[1],brojevi[0]-brojevi[1]);
                indexBrojeva=0;
                pokIndex=0;
                if(nadji_zbir(drugi)==NULL)
                    return 0;
                else
                    razlike(nadji_zbir(drugi));
            }
            
            pokIndex++;
            indexBrojeva++;

        }
        
        pocetak++;
    }

}

int main()
{
    razlike("Od 3 broja u stringu, zbir -0.2 i 1.55 daje 1.35 ili 2.9?");
    printf("Sljedeci test:\n");
    razlike("Od 3 broja u stringu, zbir -0.1 i 1.55 daje 1.25 ili 2.8?");
    return 0;
}
