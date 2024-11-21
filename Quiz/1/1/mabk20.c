#include "mabk20.h"

void masukan(){//prosedur meminta masukan user
	int i;//iterator
	int j;//iterator
	
	scanf("%d", &b);//meminta baris
	scanf("%d", &k);//meminta kolom
	
	//meminta masukan matriks pertama
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			scanf("%d %d", &matriks[i][j].pembilang, &matriks[i][j].penyebut);
		}
	}
	
	//meminta masukan matriks kedua
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			scanf("%d %d", &matriks2[i][j].pembilang, &matriks2[i][j].penyebut);
		}
	}
}

void banding(){//prosedur untuk membandingkan 2 matriks
	//iterator
	int i;
	int j;
	
	float cak;//pecahan matriks pertama
	float cek;//pecahan matriks kedua
	int sebut1;//menampung sementara penyebut matriks pertama
	int bilang1;//menampung sementara pembilang matriks pertama
	int sebut2;//menampung sementara penyebut matriks kedua
	int bilang2;//menampung sementara pembilang matriks kedua
	
	//mulai membandingkan
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			
			//memasukkan value penyebut dan pembilang masing masing matriks
			//ke sebut dan bilang
			sebut1=matriks[i][j].penyebut;
			bilang1=matriks[i][j].pembilang;
			sebut2=matriks2[i][j].penyebut;
			bilang2=matriks2[i][j].pembilang;
			//untuk mengetes hasil apakah benar
			/*
			printf("bilangsebut : %d %d\n", bilang1, sebut1);
			printf("bilangsebut2 : %d %d\n", bilang2, sebut2);
			*/
			cak=((float)bilang1/sebut1);//mencari hasil pecahannya
			//printf("hasil cak :%f\n", cak);
			cek=((float)bilang2/sebut2);//mencari hasil pecahannya
			//printf("hasil cek :%f\n", cek);
			
			if(cak<cek){//membandingkan hasil pecahan kedua matriks
				matriks[i][j].pembilang=bilang2;
				matriks[i][j].penyebut=sebut2;
				matriks2[i][j].pembilang=bilang1;
				matriks2[i][j].penyebut=sebut1;
			}
		}
	}
}

void cetak(){
	//iterator
	int i;
	int j;
	
	//mencetak matriks terbesar
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			printf("%d %d\n", matriks[i][j].pembilang, matriks[i][j].penyebut);
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi QUIZ 1 dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/