#include <stdio.h>
#include <string.h>

typedef struct{
	char plat[50];
	char nama[50];
	char jenis[50];
	char merk[50];
}parkir;

int main(){
	parkir kendaraan[3][3];
	int cari=0;
	char merkc[50];
	char jenisc[50];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Masukkan plat nomornya: ");
			scanf("%s", &kendaraan[i][j].plat);
			printf("Masukkan nama pemiliknya: ");
			scanf("%s", &kendaraan[i][j].nama);
			printf("Masukkan jenis kendaraannya: ");
			scanf("%s", &kendaraan[i][j].jenis);
			printf("Masukkan merk kendaraannya: ");
			scanf("%s", &kendaraan[i][j].merk);
			printf("=========================\n");
		}
	}
	
		printf("Pilih metode pencarian yang ingin anda pilih\n");
		printf("Tulis angkanya\n");
		printf("1. Merk\n");
		printf("2. Jenis\n");
		scanf("%d", &cari);
	
	if(cari==1){
		printf("Masukkan merk yang ingin anda cari: ");
		scanf("%s", &merkc);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(strcmp(merkc, kendaraan[i][j].merk)==0){
					printf("Ditemukan: \n");
					printf("Plat Nomor : %s\n", kendaraan[i][j].plat);
					printf("Nama Pemilik : %s\n", kendaraan[i][j].nama);
				}
			}
		}
	}else if(cari==2){
		printf("Masukkan jenis yang ingin anda cari: ");
		scanf("%s", &jenisc);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(strcmp(jenisc, kendaraan[i][j].jenis)==0){
					printf("Ditemukan: \n");
					printf("Plat Nomor : %s\n", kendaraan[i][j].plat);
					printf("Nama Pemilik : %s\n", kendaraan[i][j].nama);
				}
			}
		}
		
	}else{
		printf("Inputan yang anda masukkan salah\n");
	}
	
	
	
	return 0;
}