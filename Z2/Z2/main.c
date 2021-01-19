#include <stdio.h>

void ispisiGresku() {
	
	int i,e,r;
	
	char E [5][5] = {
		{'*','*','*','*','*'},
		{'*',' ',' ',' ',' '},
		{'*','*','*','*','*'},
		{'*',' ',' ',' ',' '},
		{'*','*','*','*','*'},
	};
	
	char R [5][5] = {
		{' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' '},
		{'*','*','*','*','*'},
		{'*',' ',' ',' ',' '},
		{'*',' ',' ',' ',' '},
	};
	
	for(i=0;i<5;i++) {
		
		for(e=0;e<5;e++) {
			printf("%c",E[i][e]);
		}
		
		printf("       ");
		
		for(r=0;r<5;r++) {
			printf("%c",R[i][r]);
		}
		
		printf("\n");

	}
}

void ispisiRezultat(int broj1,int broj2,char operacija) {
	
	char nula[5][5] = {
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ','*'},
		{ '*',' ',' ',' ','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	char jedan[5][5] = {
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'}
	};
	
	char dva[5][5] = {
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ',' '},
		{ '*','*','*','*','*'}
	};
	
	char tri[5][5] = {
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	char cetiri[5][5] = {
		{ '*',' ',' ',' ','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'}
	};
	
	char pet[5][5] = {
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ',' '},
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	char sest[5][5] = {
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ',' '},
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	char sedam[5][5] = {
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'},
		{ ' ',' ',' ',' ','*'}
	};
	
	char osam[5][5] = {
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	char devet[5][5] = {
		{ '*','*','*','*','*'},
		{ '*',' ',' ',' ','*'},
		{ '*','*','*','*','*'},
		{ ' ',' ',' ',' ','*'},
		{ '*','*','*','*','*'}
	};
	
	int rezultat=0;
	char cifra1[5][5];
	char cifra2[5][5];
	int prva=0,druga=0;
	int i,j,c1,c2;
	
	switch(operacija) {
		
		case '+':
			rezultat = broj1+broj2;
			break;
		case '-':
			rezultat = broj1-broj2;
			break;
		case '*':
			rezultat = broj1*broj2;
			break;
		case '/':
			rezultat = broj1/broj2;
			break;
	}
	
	prva = (rezultat/10)%10;
	druga = rezultat%10;
	
	if(prva == 0) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = nula[i][j];
			}	
		}
	} else if(prva == 1) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = jedan[i][j];
			}	
		}
	} else if(prva== 2) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = dva[i][j];
			}	
		}
	} else if(prva== 3) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = tri[i][j];
			}	
		}
	} else if(prva== 4) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = cetiri[i][j];
			}	
		}
	} else if(prva== 5) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = pet[i][j];
			}	
		}
	} else if(prva== 6) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = sest[i][j];
			}	
		}
	} else if(prva == 7) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = sedam[i][j];
			}	
		}
	} else if(prva == 8) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = osam[i][j];
			}	
		}
	} else if(prva == 9) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra1[i][j] = devet[i][j];
			}	
		}
	}
	
	if(druga == 0) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = nula[i][j];
			}	
		}
	} else if(druga == 1) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = jedan[i][j];
			}	
		}
	} else if(druga == 2) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = dva[i][j];
			}	
		}
	} else if(druga == 3) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = tri[i][j];
			}	
		}
	} else if(druga == 4) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = cetiri[i][j];
			}	
		}
	} else if(druga == 5) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = pet[i][j];
			}	
		}
	} else if(druga == 6) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = sest[i][j];
			}	
		}
	} else if(druga== 7) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = sedam[i][j];
			}	
		}
	} else if(druga == 8) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = osam[i][j];
			}	
		}
	} else if(druga == 9) {
		for(i=0;i<5;i++) {
			for(j=0;j<5;j++) {
				cifra2[i][j] = devet[i][j];
			}	
		}
	}
	
	
	for(i=0;i<5;i++) {
		
		for(c1=0;c1<5;c1++) {
			printf("%c",cifra1[i][c1]);
		}
		
		printf("       ");
		
		for(c2=0;c2<5;c2++) {
			printf("%c",cifra2[i][c2]);
		}
		
		printf("\n");
	}
	
}

int main() {
	
	int izbor=0,greska=0,kraj=1;
	int broj1,broj2;
	char znak;
	
	
	do {
		
		do {
			
			printf("\nOdaberite cjelobrojnu operaciju: ");
			printf("\n[1] Sabiranje ");
			printf("\n[2] Oduzimanje ");
			printf("\n[3] Mnozenje ");
			printf("\n[4] Dijeljenje ");
			printf("\n[5] Izlaz iz programa ");
			printf("\n>> ");
			scanf("%d",&izbor);
			
			printf("\n");
			
			switch(izbor) {
				
				case 1:
					printf("[1] Sabiranje ");
					znak = '+';
					break;
				case 2:
					printf("[2] Oduzimanje ");
					znak = '-';
					break;
				case 3:
					printf("[3] Mnozenje ");
					znak = '*';
					break;
				case 4:
					printf("[4] Dijeljenje ");
					znak = '/';
					break;
				case 5:
					kraj=1;
					return 0;
				default:
					greska=1;
					break;
		
			}
		
		} while(greska!=0);
		
			
		printf("\nUnesite operande: ");
		scanf("%d %d",&broj1,&broj2);
	
		if(broj1 == 0 || broj2==0 || (broj1+broj2 >= 100 && znak=='+') || (broj1-broj2 < 0 && znak=='-') || (broj1*broj2 >= 100 && znak=='*') )
			ispisiGresku();	
		else 
			ispisiRezultat(broj1,broj2,znak);

	
	} while(kraj!=0);
	
	return 0;
}
