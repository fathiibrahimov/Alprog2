#include <stdio.h>

typedef struct{
	char nama[50];
	char nim[50];
	char nilai;
}siswa;

int main(){
	siswa kelas1[2][2];
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Masukkan NIM siswa: ");
			scanf("%s", kelas1[i][j].nim);
			printf("Masukkan nama siswa: ");
			scanf("%s", kelas1[i][j].nama);
			printf("Masukkan nilai siswa: ");
			scanf(" %c", &kelas1[i][j].nilai);
			printf("=========================\n");
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("NIM siswa : %s\n", kelas1[i][j].nim);
			printf("Nama siswa : %s\n", kelas1[i][j].nama);
			printf("Nilai siswa : %c\n", kelas1[i][j].nilai);
			printf("=========================\n");
		}
	}
	
	return 0;
}