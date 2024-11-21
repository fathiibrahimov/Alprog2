//transpose

#include <stdio.h>
int main(){
	int i, j;
	printf("Masukkan jumlah kolom : ");
	scanf("%d", &i);
	printf("Masukkan jumlah baris : ");
	scanf("%d", &j);
	
	int matriks[i][j];
	int k, l;
	
	for(k=0;k<i;k++){
		for(l=0;l<j;l++){
			printf("Masukkan elemen matriks %d %d : ", k, l);
			scanf("%d", &matriks[k][l]);
		}
	}
	
	int matrikstampung[j][i];
	
	for(k=0;k<i;k++){
		for(l=0;l<j;l++){
			matrikstampung[l][k]=matriks[k][l];
		
		}
	}
	
	for(k=0;k<j;k++){
		for(l=0;l<i;l++){
			printf("%d ", matrikstampung[k][l]);
		}
		printf("\n");
	}
	
	return 0;
}