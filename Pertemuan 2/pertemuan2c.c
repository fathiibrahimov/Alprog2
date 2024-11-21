#include <stdio.h>
#include <stdlib.h>

int main(){
	
	//membersihkan layar
	system("cls");
	int papan[3][3];
	//angka 1 untuk pemain pertama berupa huruf o;
	//angka 2 untuk pemain kedua berupa huruf x
	int i,j,k;
	
	//inisialisasi papan diisi 0 semua
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			papan[i][j]=0;
		}
	}
	
	//awalnya pemain diset -1 sebagai penanda permainan belum dimulai
	int pemain = -1;
	//x dan y juga diset -1 sebagai penanda permainan belum dimulai
	int x=-1, y=-1;
	for(i=0;i<9;i++){
		//mengisi papan jika ada masukan dari pemain
		if((x!=-1)&&(y!=-1)){
			papan[x][y]=pemain;
		}
		//menggambar papan
		printf("Kondisi Papan:\n");
		printf("-------------\n");
		for(j=0;j<3;j++){
			printf("| ");
			for(k=0;k<3;k++){
				if(papan[k][j]==0){
					//jika papan kosong
					printf("  | ");
				}else if(papan[k][j]==1){
					//jika papan diisi pemain kedua
					printf("o | ");
				}else if(papan[k][j]==2){
					//jika papan diisi pemain kedua
					printf("X | ");
				}
			}
			printf("\n-------------\n");
		}
	
		printf("\n");
	
		//pergantian pemain yang akan mengisi papan
		if(pemain==1){
			pemain=2;
		}else{
			pemain=1;
		}
		//meminta masukan pemain
		printf("Masukkan X, Y (Pemain %d): ", pemain);
		scanf("%d %D", &x, &y);
		//membersihkan layar
		system("cls");	
	}
	return 0;
}