#include <stdio.h>

int main(){
	int matriks[4][6];
	int baris;
	int kolom;
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<6;kolom++){
			printf("Masukkan angka: \n");
			scanf("%d", &matriks[baris][kolom]);
			printf("\n");
		}
	}
	
	//iseng aja buatan sendiri
	for(baris=0;baris<4;baris++){
		printf("|");
		for(kolom=0;kolom<6;kolom++){
			printf("%d", matriks[baris][kolom]);
			if(kolom<5){
				printf(" ");
			}
		}
		printf("|\n");
	}
	
	
	/*buatan Bu Rosa, katanya masih kurang rapih
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<6;kolom++){
			printf("%d", matriks[baris][kolom]);
		}
		printf("\n");
	}
	*/
	
	return 0;
}