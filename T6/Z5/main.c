#include <stdio.h>

#define DIM 10

int main() {
	
	int matrica[DIM][DIM]={0};
	int i,j,min;
	
	
	for(i=0;i<DIM;i++) {
		for(j=0;j<DIM;j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	
	min=matrica[0][0];

	for(i=0;i<DIM;i++) {
		
		if(matrica[i][i] < min)
			min = matrica[i][i];
		
	}


	
	printf("%d",min);
	
	return 0;
}
