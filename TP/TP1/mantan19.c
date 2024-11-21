#include "mantan19.h"

//PROSEDUR UNTUK MEMINTA MASUKAN USER
void matmat(){
	//UNTUK ITERATOR
	int i; 
	int j;
	
	//MEMINTA ORDO MATRIKS
	scanf("%d", &n);
	
	//MEMINTA ISI MATRIKS
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf(" %c", &matriks[i][j]);
		}
	}
	
	//MEMINTA JUMLAH TRANSFORMASI MATRIKS
	scanf("%d", &m);
	
	//MEMINTA APA SAJA YANG HARUS DILAKUKAN DALAM TRANSFORMASI
	for(i=0;i<m;i++){
		scanf(" %c", &transformasi[i]);
	}
	
	//MENYIMPAN MATRIKS YANG ASLI(iseng aja)
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriksasli[i][j]=matriks[i][j];
		}
	}
	
}

//PROSEDUR UNTUK MENTRANSFORMASIKAN MATRIKS
void henshin(){
	int i;//ITERATOR
	
	//MENCARI TAU APA SAJA TRANSFORMASI YANG DIMINTA UNTUK KEMUDIAN DILAKSANAKAN
	for(i=0;i<m;i++){
		if(transformasi[i]=='A'){ //JIKA DIMINTA ROTASI
			rotasi();
		}else if(transformasi[i]=='B'){ //JIKA DIMINTA REFLEKSI
			refleksi();
		}else if(transformasi[i]=='C'){ //JIKA DIMINTA TRANSPOSE
			transpose();
		}
	}
}

//PROSEDUR UNTUK MELAKUKAN ROTASI
void rotasi(){
	//ITERATOR
	int i;
	int j;
	
	int k=n-1; //UNTUK MENCARI POSISI YANG BARU SETELAH ROTASI
	
	//MELAKUKAN ROTASI DAN MENAMPUNG HASILNYA KE MATRIKS SEMENTARA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrikst[i][j]=matriks[k][i];
			k--;
		}
		k=n-1;
	}
	
	//MENYALIN MATRIKS SEMENTARA KE MATRIKS UTAMA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriks[i][j]=matrikst[i][j];
		}
	}
	
}

//PROSEDUR UNTUK MELAKUKAN REFLEKSI(bukan pijat)
void refleksi(){
	//ITERATOR
	int i;
	int j;
	
	int k=n-1;//UNTUK MENCARI POSISI YANG BARU SETELAH REFEKSI
	
	//MELAKUKAN REFLEKSI DAN MENAMPUNGNYA KE MATRIKS SEMENTARA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrikst[i][j]=matriks[i][k];
			k--;
		}
		k=n-1;
	}
	
	//MENYALIN MATRIKS SEMENTARA KE MATRIKS UTAMA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriks[i][j]=matrikst[i][j];
		}
	}
}

void transpose(){
	//ITERATOR
	int i;
	int j;
	
	//MELAKUKAN TRANSPOSE DAN MENAMPUNGNYA KE MATRIKS SEMENTARA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrikst[i][j]=matriks[j][i];
		}
	}
	
	//MENYALIN MATRIKS SEMENTARA KE MATRIKS UTAMA
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriks[i][j]=matrikst[i][j];
		}
	}
}

int cekvalid(){
	//ITERATOR
	int i;
	int j;
	
	int valid; //PENANDA APAKAH VALID ATAU TIDAK
	int count=0; //MENGHITUNG BERAPA JUMLAH 'N' YANG SAMA POSISINYA DI KEDUA MATRIKS
	int count1=0; //MENGHITUNG BERAPA JUMLAH 'N' DI MATRIKS ASLI
	int count2=0; //MENGHITUNG BERAPA JUMLAH 'N' DI MATRIKS TRANSFORMASI
	int max; //MENCARI TAU BERAPA NILAI MAKSIMAL 'N' YANG ADA DI KEDUA MATRIKS
	
	//MENCARI TAU JUMLAH 'N' YANG SAMA DI KEDUA MATRIKS
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriksasli[i][j]=='N' && matriks[i][j]=='N'){
				count++;
			}
		}
	}
	
	//MENCARI TAU JUMLAH 'N' DI MATRIKS ASLI
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriksasli[i][j]=='N'){
				count1++;
			}
		}
	}
	
	//MENCARI TAU JUMLAH 'N' DI MATRIKS TRANSFORMASI
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriks[i][j]=='N'){
				count2++;
			}
		}
	}
	
	//MENCARI TAU JUMLAH MAKSIMAL 'N' DI KEDUA MATRIKS
	if(count1>=count2){
		max=count1;
	}else{
		max=count2;
	}
	
	//MENCARI TAU APAKAH POSISI 'N' DI TIAP MATRIKS SAMA
	if(max==count){
		valid = 1;
	}else{
		valid =0;
	}
	
	return valid;
}

void cetak(){
	//ITERATOR
	int i;
	int j;
	
	//MENCETAK MATRIKS ASLI
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==n-1){
				printf("%c\n", matriksasli[i][j]);
			}else{
				printf("%c ", matriksasli[i][j]);
			}
		}
	}
	printf("\n");
	
	//MENCETAK MATRIKS TRANSFORMASI
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==n-1){
				printf("%c\n", matriks[i][j]);
			}else{
				printf("%c ", matriks[i][j]);
			}
		}
	}	
	printf("\n");
	
	//MENCETAK STATUS VALID ATAU TIDAK
	if(cekvalid()==1){
		printf("VALID\n");
	}else if(cekvalid()==0){
		printf("TIDAK VALID\n");
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/