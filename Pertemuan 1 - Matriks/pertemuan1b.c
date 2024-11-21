#include <stdio.h>
int main{
	int matriks1[4][6];
	int matriks2[4][6];
	
	int baris;
	int kolom;
	
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<6;kolom++){
			printf("Masukkan angka: \n");
			scanf("%d", &matriks1[baris][kolom]);
			printf("\n");
		}
	}
	
	for(baris=0;baris<4;baris++){
		for(kolom=0;kolom<6;kolom++){
			matriks2[baris][kolom]=matriks1[baris][kolom];
		}
	}
	
	return 0;
}