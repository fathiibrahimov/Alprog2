#include "lif.h"

void pasti()
{
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fix[i][j]=ms1[i][j];
		}
	}
}
void rotasi()
{
	int i, j, l = 0;
	for(i = 0; i < n; i++){
		l = 0;
		for(j = n-1; j >= 0; j--){
			keluar[i][l] = ms1[j][i];
			l++; 
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			ms1[i][j]=keluar[i][j];
		}
	}
}
void refleksi()
{
	int i, j, l;
	for(i = 0; i < n; i++){
		l = 0;
		for(j = n-1; j >= 0; j--){
			keluar[i][l] = ms1[i][j];
			l++;
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			ms1[i][j] = keluar[i][j];
		}
	}
}
void transpose()
{
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			keluar[i][j] = ms1[j][i];
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			ms1[i][j] = keluar[i][j];
		}
	}
}
void proses()
{
	int i, j;

	for(i = 0; i < m; i++){
		if(rot[i] == 'A'){
			rotasi(n);
		}else if(rot[i] == 'B'){
			refleksi(n);
		}else if(rot[i] == 'C'){
			transpose(n);
		}
	}
}
int status()
{
	int i, j;
	int kebenaran=0;
	
	int iya = 0;
	//ngecek jumlah n di matriks asli
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(fix[i][j] == 'N'){
				iya++;
			}
		}
	}
	//ngecek jumlah
	int cek = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if((keluar[i][j] == 'N') && (fix[i][j] == 'N')){
				cek++;
			}
		}
	}
	
	if(iya == cek){
		kebenaran=1;
	}else{
		kebenaran=0;
	}
	
	return kebenaran;
}
void cetak()
{
	int i;
	int j;
	
	pasti();
	//untuk mencetak matriks yang belum diubah
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c", fix[i][j]);
			if(j < n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
	proses();
	//untuk mencetak matriks yang sudah diubah
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c", ms1[i][j]);
			if(j < n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
	if(status()==1){
		printf("VALID\n");
	}else{
		printf("TIDAK VALID\n");
	}
	
}

/*Saya Aliffia Fajriyannti mengerjakan TP1
dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.Aamiin.*/