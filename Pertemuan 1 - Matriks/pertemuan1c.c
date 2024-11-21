#include <stdio.h>
int main{
	int matriks1[2][3];
	int matriks2[2][3];
	int matriks3[2][3];
	
	int baris;
	int kolom;
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<3;kolom++){
			printf("Masukkan angka matriks1: \n");
			scanf("%d", &matriks1[baris][kolom]);
			printf("\n");
		}
	}
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<3;kolom++){
			printf("Masukkan angka matriks2: \n");
			scanf("%d", &matriks2[baris][kolom]);
			printf("\n");
		}
	}
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<3;kolom++){
			matriks3[baris][kolom]=matriks1[baris][kolom]+matriks2[baris][kolom];
		}
	}
	
	return 0;
}