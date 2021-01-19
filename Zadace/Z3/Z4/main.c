#include <stdio.h>
#include <math.h>

#define epsilon 0.00001

void zamjeniMjesta(double *prvi,double *drugi) {
    
    double temp;
    
    temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

int partition(double A[],int manji,int veci) {
    
    int i,j;
    double pivot = A[veci];

    i = manji-1;
    
    for(j=manji;j<=veci-1;j++) {
        if(A[j] < pivot) {
            i++;
            zamjeniMjesta(&A[i],&A[j]);
        }
    }
    
    zamjeniMjesta(&A[i+1],&A[veci]);
    
    return i+1;
}

void quickSort(double A[1000],int manji,int veci) {
    
    int index;

    if (manji < veci) {
        
        index = partition(A,manji,veci);
    
        quickSort(A,manji,index-1);
        quickSort(A,index+1,veci);
    }
    
}

int matrice_permutacija(double A[][100],double B[][100], double C[][100],int M,int N){
    
    int i,j;
    double nizA[10000],nizB[10000],nizC[10000];
    int brojac=0;
    
 
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
            nizA[brojac]=A[i][j];
            nizB[brojac]=B[i][j];
            nizC[brojac]=C[i][j];
            brojac++;
        }
    }
    
    quickSort(nizA,0,brojac-1);
    quickSort(nizB,0,brojac-1);

    // for(i=0;i<brojac;i++) {
    //     printf("%g ",nizB[i]);
    // }
    
    for(i=0;i<brojac;i++) {
        if(fabs(nizB[i]-nizA[i]) > epsilon)
            return 0;
    }
    
    quickSort(nizC,0,brojac-1);
        
   
    for(i=0;i<brojac;i++) {
        if(fabs(nizC[i]-nizB[i]) > epsilon)
            return 0;
    }
    
    return 1;

}

int main(){
    
    double A[100][100],B[100][100],C[100][100];
    int M,N;
    int i,j;
    
    printf("Unesite M i N: ");
    scanf("%d %d",&M,&N);
    
    printf("Unesite clanove prve matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&A[i][j]);
        }
    }
    
    printf("Unesite clanove druge matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&B[i][j]);
        }
    }
    
    printf("Unesite clanove trece matrice: ");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%lf",&C[i][j]);
        }
    } 
    
    if(matrice_permutacija(A,B,C,3,3))
        printf("Matrice imaju iste elemente.");
    else
        printf("Matrice nemaju iste elemente.");
    
    
    
return 0;
}
