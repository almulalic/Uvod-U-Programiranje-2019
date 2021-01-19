#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	int i = 0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ukloni_komentare(char *string){

    int i = 0;
    int k=0;
    char* pok=string;
    
    while (*(string+i) != '\0') {
        if (*(string+i) == '/' && *(string+i+1) == '*') {
             k = i + 1;
            do {
                k++;
            } while (*(string+k)!='*' && *(string+k+1)!='/');
            k += 2;
            do {
                *(string+i) = *(string+k);
                string++;
            } while (*(string+i)!='\0');
            *(string+i-1)='\0';
            string = pok;
        }
        if (*(string+i) == '/' && *(string+i+1)  == '/') {

            int k = i;
            do {
                k++;
            } while (*(string+k)!='\n' && *(string+k)!='\0');
            k+=2;
            do {
                *(string+i) = *(string+k);
                string++;
            } while (*(string+i)!='\0');
            *(string+i-1)='\0';

            string = pok;
        }
        i++;
    }
    return pok;
}

int main() {
    char recenica[100];
    char kod[] = "int main() {\n\tprintf(\"Hello world\"); /* Pozdrav */\n\treturn 0;\n}";
    
    printf("\nRecenica: %s", ukloni_komentare(kod));
    return 0;
}