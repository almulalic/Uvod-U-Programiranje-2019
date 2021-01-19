#include <stdio.h>

int main() {
	
	int i,j;
	
	for(i=0;i<12;i++) {
		for(j=0;j<12;j++){
			if(i==0 && j==0)
				printf("  X |");
			else if(i==0 && j<=10)
				printf("%4d",j);
			
			if(i==1 && j==0)
				printf("----+");
			else if(i==1 && j<=10)
				printf("----");
				
			if(i>1 && j==0)
				printf("%3d |",i-1);
			else if(i>1 && j>1)
				printf("%4d",(i-1)*(j-1));
		}
		printf("\n");
	}
	
	return 0;
}
