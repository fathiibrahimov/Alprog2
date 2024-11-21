#include<stdio.h>
int main(){
	int matriks1[3][2];
	int matriks2[2][3];
	int matriks3[3][3];
	
	int baris;
	int kolom;
	int i;//i=jumlah kali
	
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
	
	for(baris=0;baris<3;baris++){
		for(kolom=0;kolom<3;kolom++){
			matriks3[baris][kolom]=0;
			for(i=0;i<2;i++){
				matriks3[baris][kolom]+=matriks1[baris][i]*matriks2[i][kolom];
			}
		}
	}
	
	
	return 0;
}