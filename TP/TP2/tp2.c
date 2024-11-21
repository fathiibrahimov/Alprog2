#include "tp2.h"

void masuk(){//prosedur meminta masukan user
	//iterator
	int i;
	int j;
	
	//meminta ordo matriks
	scanf("%d %d", &n, &m);
	
	//mengisi matriks jabatan
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%s", karyawan[i][j].jabatan);
		}
	}
	
	//mengisi matriks nama
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%s", karyawan[i][j].nama);
		}
	}
	
	//mengisi matriks gaji
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d", &karyawan[i][j].gaji);
		}
	}
	
	o=0;//mengatur supaya mulai dari nol, untuk mengetahui berapa banyak ingin ditukar
	do{//mengisi yang ingin ditukar	sampai diinput kata "oke."	
		scanf("%s", cek);
		strcpy(tukar[o], cek);
		o++;
		
	}while(strcmp(cek, "oke.") != 0);
	
}

void gajinaik(){
	int i, j, k;//iterator
	int l=0;
	int a;
	int b;
	int z;
	int gajitampung;
	int posisi[4];
	char pasif[100];
	char aktif[100];
	char namatampung[100];
	
	//mengosongkan array supaya tidak error
	for(i=0;i<100;i++){
		pasif[i]='\0';
		aktif[i]='\0';
	}
	
	for(i=0;i<o;i++){
		for(j=0;j<strlen(tukar[i]);j++){
			if(tukar[i][j]=='-'){
				//memasukkan jabatan sebelum dan sesudah tanda pemisah ke pasif dan aktif
				for(k=0;k<j;k++){
					pasif[k]=tukar[i][k];
				}
				for(k=j+1;k<strlen(tukar[i]);k++){
					aktif[l]=tukar[i][k];
					l++;
				}
				l=0;
				
				//mencari ada dimanakah posisi jabatan yang sama
				for(a=0;a<n;a++){
					for(b=0;b<m;b++){
						if(strcmp(karyawan[a][b].jabatan, pasif)==0){
							posisi[0]=a;
							posisi[1]=b;
						}
						if(strcmp(karyawan[a][b].jabatan, aktif)==0){
							posisi[2]=a;
							posisi[3]=b;
						}
					}
				}
				
				//copy paste isi matriks untuk menukar yang ingin ditukar
				if(strcmp(pasif, aktif)==0){
				//abaikan saja
				}else{
					strcpy(namatampung, karyawan[posisi[0]][posisi[1]].nama);
					strcpy(karyawan[posisi[0]][posisi[1]].nama, karyawan[posisi[2]][posisi[3]].nama);
					strcpy(karyawan[posisi[2]][posisi[3]].nama, namatampung);
					gajitampung=karyawan[posisi[0]][posisi[1]].gaji*120/100;
					karyawan[posisi[0]][posisi[1]].gaji=karyawan[posisi[2]][posisi[3]].gaji*120/100;
					karyawan[posisi[2]][posisi[3]].gaji=gajitampung;
				}
				
				for(z=0;z<100;z++){
					pasif[z]='\0';
					aktif[z]='\0';
				}
			}
		}
	}
}

void cetak(){//prosedur untuk mencetak keluaran
	//iterator
	int i;
	int j;
	
	//mencetak sesuai ketentuan
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%s->%s,%d", karyawan[i][j].jabatan, karyawan[i][j].nama, karyawan[i][j].gaji);
			if(j<m-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Evaluasi 2 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/