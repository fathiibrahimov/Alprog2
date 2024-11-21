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
			printf("Masukkan elemen matriks yang ke %d %d : ", k, l);
			scanf("%d", &matriks[k][l]);
		}
	}
	
	int matrikstampung[i][j];
	int a=i-1;
	int b=j-1;
	
	for(k=0;k<i;k++){
		for(l=0;l<j;l++){
			matrikstampung[k][b]=matriks[k][l];
			a--;
		}
		b=j-1;
	}
	
	for(k=0;k<j;k++){
		for(l=0;l<i;l++){
			printf("%d ", matrikstampung[k][l]);
		}
		printf("\n");
	}
	
	
	return 0;
}